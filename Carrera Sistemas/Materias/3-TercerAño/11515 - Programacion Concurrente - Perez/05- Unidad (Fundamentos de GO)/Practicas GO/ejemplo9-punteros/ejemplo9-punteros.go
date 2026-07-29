package main

import "fmt"

func incrementar(x *int) {
	*x++
}

func main() {
	x := 5
	fmt.Println("Valor inicial:", x)

	incrementar(&x)
	fmt.Println("Valor despues de incrementar:", x)

	//Puntero
	p := &x
	fmt.Println("Direccion de x:", p)
	fmt.Println("Valor apuntado por p:", *p)
}
