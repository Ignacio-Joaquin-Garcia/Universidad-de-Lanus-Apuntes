package main

import (
	"fmt"
	"runtime"
	"sync"
)

var contador int = 0
var mutex sync.Mutex

func ejecutarConteo(wg *sync.WaitGroup) {
	defer wg.Done()

	mutex.Lock()         //Bloquea las Variables que siguen
	defer mutex.Unlock() //Desbloquea las Variables que siguen cuando termine goroutine
	for range 10000 {
		contador++
	}
}

func main() {
	nucleos := runtime.NumCPU()
	fmt.Printf("Núcleos lógicos: %d\n", nucleos)

	var wg sync.WaitGroup

	for i := 0; i < nucleos; i++ {
		wg.Add(1)
		go ejecutarConteo(&wg)
	}

	wg.Wait()

	esperado := nucleos * 10000
	fmt.Println("\n--- RESULTADOS ---")
	fmt.Printf("Valor esperado: %d\n", esperado)
	fmt.Printf("Valor real:     %d\n", contador)
}
