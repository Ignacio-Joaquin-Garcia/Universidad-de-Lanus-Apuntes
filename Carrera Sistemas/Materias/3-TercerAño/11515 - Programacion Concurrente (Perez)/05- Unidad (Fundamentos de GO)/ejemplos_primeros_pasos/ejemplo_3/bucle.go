package main

import "fmt"

func main() {
	// Bucle for
	for i := 1; i <= 10; i++ {
		fmt.Println(i)
	}

	// Bucle while (usando for)
	j := 1
	for j <= 10 {
		fmt.Println("While-like:", j)
		j++
	}
}