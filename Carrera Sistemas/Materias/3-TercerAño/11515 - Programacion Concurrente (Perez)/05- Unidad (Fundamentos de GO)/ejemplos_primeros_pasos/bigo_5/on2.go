package main

import (
	"fmt"
	"time"
)

func bubbleSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
}

func main() {
	size := 10000 // smaller size for O(n^2)
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = size - i
	}

	start := time.Now()
	bubbleSort(arr)
	elapsed := time.Since(start)

	fmt.Printf("Array ordenado, primer elemento: %d, último: %d\n", arr[0], arr[size-1])
	fmt.Printf("Tiempo O(n^2): %d µs\n", elapsed.Microseconds())
}
