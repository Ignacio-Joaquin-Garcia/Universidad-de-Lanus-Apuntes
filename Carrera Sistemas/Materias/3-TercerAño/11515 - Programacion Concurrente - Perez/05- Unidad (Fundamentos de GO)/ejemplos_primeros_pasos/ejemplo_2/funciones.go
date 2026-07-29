package main

import "fmt"

func sumar(a int, b int) int {
	return a + b
}

func main() {
	resultado := sumar(5, 3)
	fmt.Println("5 + 3 =", resultado)
}