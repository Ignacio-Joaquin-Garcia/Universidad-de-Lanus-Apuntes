package main

import (
	"fmt"
	"time"
)

func fibonacci(n int) int {
	if n <= 1 {
		return n
	}
	return fibonacci(n-1) + fibonacci(n-2)
}

func main() {
	n := 30 // small n for O(2^n)

	start := time.Now()
	result := fibonacci(n)
	elapsed := time.Since(start)

	fmt.Printf("Fibonacci de %d: %d\n", n, result)
	fmt.Printf("Tiempo O(2^n): %d µs\n", elapsed.Microseconds())
}
