package main

import (
	"fmt"
	"runtime"
	"sync"
	"sync/atomic"
)

var contadorAtomico int64 = 0

func ejecutarConteo(wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 0; i < 10000; i++ {
		atomic.AddInt64(&contadorAtomico, 1) // 🚀 Operación atómica
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
	fmt.Printf("Valor real con Atomic: %d\n", atomic.LoadInt64(&contadorAtomico))
}
