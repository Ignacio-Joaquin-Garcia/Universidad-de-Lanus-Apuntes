package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

var (
	contador        int64 = 0
	lock            sync.Mutex
	contadorAtomico int64 = 0
)

func ejecutar(numHilos int, iteraciones int, tipo int) {
	var wg sync.WaitGroup
	for i := 0; i < numHilos; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for j := 0; j < iteraciones; j++ {
				switch tipo {
				case 0:
					contador++ // ❌ SIN SYNC
				case 1:
					lock.Lock() // ⚠️ MUTEX
					contador++
					lock.Unlock()
				case 2:
					atomic.AddInt64(&contadorAtomico, 1) // 🚀 ATOMIC
				}
			}
		}()
	}
	wg.Wait()
}

func main() {
	hilos := runtime.NumCPU()
	iteraciones := 1_000_000
	totalEsperado := int64(hilos * iteraciones)

	fmt.Printf("Núcleos: %d | Iteraciones por hilo: %d\n\n", hilos, iteraciones)

	// --- ❌ SIN SYNC ---
	contador = 0
	t1 := time.Now()
	ejecutar(hilos, iteraciones, 0)
	duracion1 := time.Since(t1)
	fmt.Printf("❌ SIN SYNC\nReal: %d\nTiempo: %v\n\n", contador, duracion1)

	// --- ⚠️ MUTEX ---
	contador = 0
	t2 := time.Now()
	ejecutar(hilos, iteraciones, 1)
	duracion2 := time.Since(t2)
	fmt.Printf("⚠️ MUTEX\nReal: %d\nTiempo: %v\n\n", contador, duracion2)

	// --- 🚀 ATOMIC ---
	contadorAtomico = 0
	t3 := time.Now()
	ejecutar(hilos, iteraciones, 2)
	duracion3 := time.Since(t3)
	fmt.Printf("🚀 ATOMIC\nReal: %d\nTiempo: %v\n\n", contadorAtomico, duracion3)

	// --- 🧘 SECUENCIAL ---
	var c int64 = 0
	t4 := time.Now()
	for i := 0; i < int(totalEsperado); i++ {
		c++
	}
	duracion4 := time.Since(t4)
	fmt.Printf("🧘 SECUENCIAL\nReal: %d\nTiempo: %v\n", c, duracion4)
}
