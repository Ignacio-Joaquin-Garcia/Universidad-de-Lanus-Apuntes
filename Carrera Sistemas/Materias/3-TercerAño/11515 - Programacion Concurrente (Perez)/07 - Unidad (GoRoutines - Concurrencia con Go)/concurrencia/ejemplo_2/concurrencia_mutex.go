package main

import (
	"fmt"
	"runtime"
	"sync"
)

var (
	contador int        = 0
	mu       sync.Mutex // Objeto de lock
)

func ejecutarConteo(wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 0; i < 10000; i++ {
		mu.Lock() // ✅ Protegido
		contador++
		mu.Unlock()
	}
}

func main() {
	nucleos := runtime.NumCPU()
	var wg sync.WaitGroup

	for i := 0; i < nucleos; i++ {
		wg.Add(1)
		go ejecutarConteo(&wg)
	}

	wg.Wait()
	fmt.Printf("Valor real con Mutex: %d\n", contador)
}
