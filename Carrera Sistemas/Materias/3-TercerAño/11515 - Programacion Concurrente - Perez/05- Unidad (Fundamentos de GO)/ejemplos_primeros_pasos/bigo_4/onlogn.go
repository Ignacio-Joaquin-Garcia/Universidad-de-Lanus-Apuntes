package main

import (
	"fmt"
	"sort"
	"time"
)

func main() {
	size := 100000
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = size - i // reverse order
	}

	start := time.Now()
	sort.Ints(arr)
	elapsed := time.Since(start)

	fmt.Printf("Array ordenado, primer elemento: %d, último: %d\n", arr[0], arr[size-1])
	fmt.Printf("Tiempo O(n log n): %d µs\n", elapsed.Microseconds())
}
