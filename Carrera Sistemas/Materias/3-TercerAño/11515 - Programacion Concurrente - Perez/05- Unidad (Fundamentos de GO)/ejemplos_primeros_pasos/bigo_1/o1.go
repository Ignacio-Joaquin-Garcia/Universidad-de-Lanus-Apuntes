package main

import (
	"fmt"
	"time"
)

func accesoConstante(arr []int, index int) int {
	return arr[index]
}

func main() {
	arr := make([]int, 1000000)
	for i := range arr {
		arr[i] = i
	}

	start := time.Now()
	result := accesoConstante(arr, 500000)
	elapsed := time.Since(start)

	fmt.Printf("Resultado: %d\n", result)
	fmt.Printf("Tiempo O(1): %d µs\n", elapsed.Microseconds())
}
