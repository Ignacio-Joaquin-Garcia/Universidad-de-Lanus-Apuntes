package main

import (
	"fmt"
	"time"
)

func trabajador(id int, trabajos <-chan int, resultados chan<- int) {
	for j := range trabajos {
		fmt.Printf("Trabajador %d procesando tarea %d\n", id, j)
		time.Sleep(time.Second) // Simulando carga
		resultados <- j * 2
	}
}

func main() {
	const numTareas = 5
	trabajos := make(chan int, numTareas)
	resultados := make(chan int, numTareas)

	// Lanzamos 3 trabajadores
	for w := 1; w <= 3; w++ {
		go trabajador(w, trabajos, resultados)
	}

	// Enviamos tareas
	for j := 1; j <= numTareas; j++ {
		trabajos <- j
	}
	close(trabajos)

	// Recogemos resultados
	for a := 1; a <= numTareas; a++ {
		<-resultados
	}
	fmt.Println("Todas las tareas finalizadas.")
}
