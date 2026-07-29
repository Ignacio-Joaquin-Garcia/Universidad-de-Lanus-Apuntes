package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	totalTransacciones = 50
	cantidadWorkers    = 5
	timeoutRed         = 250 * time.Millisecond // umbral de corte de red bancaria
)

// Transaccion representa una operación financiera entrante.
type Transaccion struct {
	ID      int
	Monto   float64
	Origen  string
	Destino string
}

// resultadoAnalisis transporta el veredicto de la goroutine de análisis interna.
type resultadoAnalisis struct {
	demora time.Duration
}

// generarLote carga secuencialmente 50 transacciones al canal sin buffer
// y lo cierra al finalizar para señalizar a los workers.
func generarLote(transaccionesEntrantes chan<- Transaccion) {
	origenes := []string{"AR", "BR", "MX", "CL", "CO"}
	destinos := []string{"US", "EU", "JP", "UK", "CN"}

	for i := 1; i <= totalTransacciones; i++ {
		tx := Transaccion{
			ID:      i,
			Monto:   rand.Float64() * 100_000,
			Origen:  origenes[rand.Intn(len(origenes))],
			Destino: destinos[rand.Intn(len(destinos))],
		}
		transaccionesEntrantes <- tx
	}
	close(transaccionesEntrantes)
}

// simularAnalisis ejecuta la consulta bancaria en una goroutine propia
// y devuelve el resultado por un canal dedicado de capacidad 1.
// La latencia se modela con time.After + select: la goroutine queda
// suspendida esperando un evento de canal, no bloqueando un hilo del SO.
// El buffer de 1 es crítico: evita que la goroutine quede huérfana
// si el worker ya tomó la rama de timeout en su propio select.
func simularAnalisis() <-chan resultadoAnalisis {
	ch := make(chan resultadoAnalisis, 1)
	go func() {
		demora := time.Duration(100+rand.Intn(301)) * time.Millisecond
		select {
		case <-time.After(demora):
			ch <- resultadoAnalisis{demora: demora}
		}
	}()
	return ch
}

// workerValidacion consume transacciones del canal entrante.
// Por cada una lanza un análisis concurrente y usa select para competir
// contra time.After(timeoutRed): quien llega primero determina el veredicto.
func workerValidacion(
	nodoID int,
	transaccionesEntrantes <-chan Transaccion,
	registroContable chan<- string,
	wg *sync.WaitGroup,
) {
	defer wg.Done()

	for tx := range transaccionesEntrantes {
		analisis := simularAnalisis()

		var mensaje string
		select {

		// ── Caso 1: la red bancaria respondió dentro del umbral ──────────────
		case res := <-analisis:
			mensaje = fmt.Sprintf(
				"1  Transacción %d aprobada  por el Nodo %d  |  $%9.2f  %s→%s  (%dms)",
				tx.ID, nodoID, tx.Monto, tx.Origen, tx.Destino, res.demora.Milliseconds(),
			)

		// ── Caso 2: timeout de red — se aborta la operación ──────────────────
		case <-time.After(timeoutRed):
			mensaje = fmt.Sprintf(
				"2  Transacción %d rechazada por Timeout de Red  (Nodo %d)  |  $%9.2f  %s→%s",
				tx.ID, nodoID, tx.Monto, tx.Origen, tx.Destino,
			)
		}

		registroContable <- mensaje
	}
}

func main() {
	rand.New(rand.NewSource(time.Now().UnixNano()))

	// Canal sin buffer: sincronización estricta productor–consumidor
	transaccionesEntrantes := make(chan Transaccion)

	// Canal con buffer = 50: los workers nunca bloquean al publicar resultados
	registroContable := make(chan string, totalTransacciones)

	// ── Lanzar 5 workers en paralelo ─────────────────────────────────────────
	var wgWorkers sync.WaitGroup
	for nodo := 1; nodo <= cantidadWorkers; nodo++ {
		wgWorkers.Add(1)
		go workerValidacion(nodo, transaccionesEntrantes, registroContable, &wgWorkers)
	}

	// ── Productor en goroutine propia ─────────────────────────────────────────
	go generarLote(transaccionesEntrantes)

	// ── Goroutine centinela: cierra el canal de salida una vez que
	//    TODOS los workers terminaron de escribir ──────────────────────────────
	go func() {
		wgWorkers.Wait()
		close(registroContable)
	}()

	// ── Imprimir resultados ───────────────────────────────────────────────────
	fmt.Println("╔════════════════════════════════════════════════════════════════╗")
	fmt.Println("║     SISTEMA ANTIFRAUDE — REGISTRO CONTABLE  (timeout 250ms)    ║")
	fmt.Println("╚════════════════════════════════════════════════════════════════╝")

	var aprobadas, rechazadas int
	for registro := range registroContable {
		if registro[0] == '1' {
			aprobadas++
		} else {
			rechazadas++
		}
		total := aprobadas + rechazadas
		fmt.Printf("[%02d/%d] %s\n", total, totalTransacciones, registro)
	}

	// ── Resumen final ─────────────────────────────────────────────────────────
	fmt.Println("────────────────────────────────────────────────────────────────")
	fmt.Printf("1  Aprobadas : %d\n", aprobadas)
	fmt.Printf("2  Rechazadas: %d  (timeout de red > %dms)\n", rechazadas, timeoutRed.Milliseconds())
	fmt.Printf("Total      : %d transacciones procesadas\n", aprobadas+rechazadas)
	fmt.Println("────────────────────────────────────────────────────────────────")
}
