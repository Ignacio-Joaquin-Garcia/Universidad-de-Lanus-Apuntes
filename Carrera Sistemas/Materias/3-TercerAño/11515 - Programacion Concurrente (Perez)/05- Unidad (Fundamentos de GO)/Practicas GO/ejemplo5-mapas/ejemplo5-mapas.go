package main

import "fmt"

func main() {
	//Map | Diccionario (Clave-Valor)
	mapa := make(map[string]int)
	mapa["uno"] = 1
	mapa["dos"] = 2
	mapa["tres"] = 3

	fmt.Println("Mapa:", mapa)

	//Acceder a un valor
	fmt.Println("valor de 'dos':", mapa["dos"])

	//Iterrar sobre el mapa
	for clave, valor := range mapa {
		fmt.Printf("Clave: %s, Valor: %d\n", clave, valor)
	}

}
