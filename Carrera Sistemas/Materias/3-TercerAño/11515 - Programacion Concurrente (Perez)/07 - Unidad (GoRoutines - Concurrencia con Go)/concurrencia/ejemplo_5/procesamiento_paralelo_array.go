package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

func trabajoPesado(x int) int {
	res := x
	for i := 0; i < 100; i++ {
		res = res*10 + 1
		res = res/2 + 3
	}
	return res
}

func procesar(origen []int, destino []int, inicio int, fin int, wg *sync.WaitGroup) {
	if wg != nil {
		defer wg.Done()
	}
	for i := inicio; i < fin; i++ {
		destino[i] = trabajoPesado(origen[i])
	}
}

func main() {
	const N = 20_000_000
	original := make([]int, N)
	secuencial := make([]int, N)
	paralelo := make([]int, N)

	// Generar datos
	for i := 0; i < N; i++ {
		original[i] = rand.Intn(9) + 1
	}

	// =========================
	// 🧘 SECUENCIAL
	// =========================
	t1 := time.Now()
	procesar(original, secuencial, 0, N, nil)
	duracionSec := time.Since(t1)

	// =========================
	// ⚡ PARALELO (2 Goroutines)
	// =========================
	var wg sync.WaitGroup
	t2 := time.Now()

	wg.Add(2)
	go procesar(original, paralelo, 0, N/2, &wg)
	go procesar(original, paralelo, N/2, N, &wg)

	wg.Wait()
	duracionPar := time.Since(t2)

	// =========================
	// RESULTADOS
	// =========================
	fmt.Printf("🧘 Secuencial: %v\n", duracionSec)
	fmt.Printf("⚡ Paralelo:   %v\n", duracionPar)

	// Validación
	fmt.Printf("Chequeo de integridad: %v\n", secuencial[N-1] == paralelo[N-1])
}
