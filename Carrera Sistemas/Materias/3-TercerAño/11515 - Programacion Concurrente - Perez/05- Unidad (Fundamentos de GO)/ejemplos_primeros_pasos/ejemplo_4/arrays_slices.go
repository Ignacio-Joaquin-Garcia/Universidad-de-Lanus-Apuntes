package main

import "fmt"

func main() {
	// Array
	var arr [5]int = [5]int{1, 2, 3, 4, 5}
	fmt.Println("Array:", arr)

	// Slice
	slice := []int{1, 2, 3, 4, 5}
	fmt.Println("Slice:", slice)

	// Agregar elemento al slice
	slice = append(slice, 6)
	fmt.Println("Slice después de append:", slice)

	// Subslice
	sub := slice[1:4]
	fmt.Println("Subslice:", sub)
}