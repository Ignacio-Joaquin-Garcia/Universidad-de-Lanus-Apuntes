package main

import "fmt"

type Persona struct {
	Nombre string
	Edad   int
}

func main() {
	// Crear instancia de struct
	p1 := Persona{Nombre: "Juan", Edad: 25}
	fmt.Println("Persona 1:", p1)

	// Acceder a campos
	fmt.Println("Nombre:", p1.Nombre)
	fmt.Println("Edad:", p1.Edad)

	// Modificar campo
	p1.Edad = 26
	fmt.Println("Nueva edad:", p1.Edad)
}