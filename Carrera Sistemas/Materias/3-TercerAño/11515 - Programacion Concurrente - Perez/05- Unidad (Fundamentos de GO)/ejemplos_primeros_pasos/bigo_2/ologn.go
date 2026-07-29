package main

import (
	"fmt"
	"time"
)

func busquedaBinaria(arr []int, target int) int {
	low, high := 0, len(arr)-1
	for low <= high {
		mid := low + (high-low)/2
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			low = mid + 1
		} else {
			high = mid - 1
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
	result := busquedaBinaria(arr, 500000)
	elapsed := time.Since(start)

	fmt.Printf("Resultado: %d\n", result)
	fmt.Printf("Tiempo O(log n): %d µs\n", elapsed.Microseconds())
}
