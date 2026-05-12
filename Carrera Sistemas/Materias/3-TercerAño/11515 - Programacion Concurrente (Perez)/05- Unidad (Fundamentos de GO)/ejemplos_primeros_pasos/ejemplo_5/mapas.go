package main

import "fmt"

func main() {
	// Map
	mapa := make(map[string]int)
	mapa["uno"] = 1
	mapa["dos"] = 2
	mapa["tres"] = 3

	fmt.Println("Mapa:", mapa)

	// Acceder a un valor
	fmt.Println("Valor de 'dos':", mapa["dos"])

	// Iterar sobre el mapa
	for clave, valor := range mapa {
		fmt.Printf("Clave: %s, Valor: %d\n", clave, valor)
	}

	// Verificar existencia
	if val, ok := mapa["cuatro"]; ok {
		fmt.Println("Cuatro existe:", val)
	} else {
		fmt.Println("Cuatro no existe")
	}
}