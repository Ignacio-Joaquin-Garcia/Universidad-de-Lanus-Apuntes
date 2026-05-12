package main

import "fmt"

func sumar(a, b int, canal chan int) {
	res := a + b
	canal <- res // Envía el dato al canal
}

func main() {
	canal := make(chan int)

	go sumar(10, 20, canal)
	go sumar(50, 50, canal)

	// Recibimos los datos (bloqueante hasta que lleguen)
	res1 := <-canal
	res2 := <-canal

	fmt.Printf("Resultados recibidos: %d y %d\n", res1, res2)
}
