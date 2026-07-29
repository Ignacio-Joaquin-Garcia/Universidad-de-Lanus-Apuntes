package main

import (
	"fmt"
	"time"
)

func busquedaLineal(arr []int, target int) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1
}

func main() {
	size := 1000000
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = i
	}

	start := time.Now()
	result := busquedaLineal(arr, 500000)
	elapsed := time.Since(start)

	fmt.Printf("Resultado: %d\n", result)
	fmt.Printf("Tiempo O(n): %d µs\n", elapsed.Microseconds())
}
