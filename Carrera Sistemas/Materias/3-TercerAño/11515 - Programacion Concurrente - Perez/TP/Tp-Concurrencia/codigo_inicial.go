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
)

// Transaccion representa una operación financiera entrante
type Transaccion struct {
	ID     int
	Monto  float64
	Origen string
	Destino string
}

// generarLote carga secuencialmente 50 transacciones al canal sin buffer.
// Cierra el canal al terminar para señalizar a los workers que no hay más trabajo.
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
		// Envío bloqueante: espera a que un worker esté libre (canal sin buffer)
		transaccionesEntrantes <- tx
	}
	// Señaliza fin de lote; los workers saldrán del range cuando el canal cierre
	close(transaccionesEntrantes)
}

// workerValidacion representa un nodo de análisis antifraude.
// Consume transacciones del canal entrante, simula el análisis y publica
// el resultado en registro_contable. Notifica al WaitGroup al terminar.
func workerValidacion(
	nodoID int,
	transaccionesEntrantes <-chan Transaccion,
	registroContable chan<- string,
	wg *sync.WaitGroup,
) {
	defer wg.Done()

	for tx := range transaccionesEntrantes {
		// Latencia aleatoria que simula análisis de riesgo (100ms – 400ms)
		demora := time.Duration(100+rand.Intn(301)) * time.Millisecond
		time.Sleep(demora)

		mensaje := fmt.Sprintf(
			"Transacción %d aprobada por el Nodo %d  |  $%.2f  %s→%s  (análisis: %dms)",
			tx.ID, nodoID, tx.Monto, tx.Origen, tx.Destino, demora.Milliseconds(),
		)
		registroContable <- mensaje
	}
}

func main() {
	rand.New(rand.NewSource(time.Now().UnixNano()))

	// ── Canales ──────────────────────────────────────────────────────────────
	// Canal sin buffer: sincronización estricta productor–consumidor
	transaccionesEntrantes := make(chan Transaccion)

	// Canal con buffer igual al total de transacciones para que los workers
	// no bloqueen al escribir mientras el main aún no leyó todos los registros
	registroContable := make(chan string, totalTransacciones)

	// ── WaitGroup de workers ─────────────────────────────────────────────────
	var wgWorkers sync.WaitGroup

	// Lanzar exactamente 5 goroutines de validación en paralelo
	for nodo := 1; nodo <= cantidadWorkers; nodo++ {
		wgWorkers.Add(1)
		go workerValidacion(nodo, transaccionesEntrantes, registroContable, &wgWorkers)
	}

	// ── Productor ────────────────────────────────────────────────────────────
	// Corre en su propia goroutine para no bloquear el lanzamiento de workers
	go generarLote(transaccionesEntrantes)

	// ── Cierre limpio de registro_contable ───────────────────────────────────
	// Goroutine centinela: espera a que TODOS los workers terminen y recién
	// entonces cierra el canal de salida, permitiendo que el range del main finalice.
	go func() {
		wgWorkers.Wait()
		close(registroContable)
	}()

	// ── Consumir resultados ──────────────────────────────────────────────────
	fmt.Println("╔══════════════════════════════════════════════════════════════╗")
	fmt.Println("║       SISTEMA ANTIFRAUDE — REGISTRO CONTABLE                ║")
	fmt.Println("╚══════════════════════════════════════════════════════════════╝")

	aprobadas := 0
	for registro := range registroContable {
		aprobadas++
		fmt.Printf("[%02d/%d] %s\n", aprobadas, totalTransacciones, registro)
	}

	// ── Resumen final ────────────────────────────────────────────────────────
	fmt.Println("──────────────────────────────────────────────────────────────")
	fmt.Printf("✔  Lote finalizado: %d transacciones aprobadas sin errores.\n", aprobadas)
	fmt.Println("──────────────────────────────────────────────────────────────")
}
