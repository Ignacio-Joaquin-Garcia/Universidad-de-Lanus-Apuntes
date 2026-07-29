package main

import "fmt"

type Animal interface {
	HacerSonido() string
}

type Perro struct{}

func (p Perro) HacerSonido() string {
	return "Guau"
}

type Gato struct{}

func (g Gato) HacerSonido() string {
	return "Miau"
}

func main() {
	var a Animal

	a = Perro{}
	fmt.Println("Perro dice:", a.HacerSonido())

	a = Gato{}
	fmt.Println("Gato dice:", a.HacerSonido())
}