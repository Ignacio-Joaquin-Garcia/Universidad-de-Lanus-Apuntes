package main

import "fmt"

type Persona struct {
	nombre string
	Edad   int
}

func (p Persona) setNombre(nombre string) Persona {
	p.nombre = nombre
	return p
}
func (p Persona) getNombre() string {
	return p.nombre
}

func main() {
	//Crear instancia de struct
	p1 := Persona{Edad: 25}
	p1 = p1.setNombre("Pedro")
	fmt.Println("Persona 1:", p1)

	//Acceder a campos
	fmt.Println("Nombre:", p1.getNombre())
	fmt.Println("Edad:", p1.Edad)

	//Modificar Cambpos
	p1.Edad = 36
	fmt.Println("Edad:", p1.Edad)
}
