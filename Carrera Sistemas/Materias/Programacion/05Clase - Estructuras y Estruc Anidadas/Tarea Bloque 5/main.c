#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funciones.h"

int main()
{
    ///DEFINICION E INICIALIZACION
    srand(time(0));

    int numAnimales = validarNum("\n¿Cuantos animales quiere ingresar?: ");
    struct Animales array[numAnimales];
    int formaIngresoDatos = validarNum("\n¿Los quiere ingresar de manera aleatoria o por teclado? (0/1 o >1 respectivamente): ");

    ///PROCESO
    if(formaIngresoDatos == 0){
        crearAnimalesAleatorios(array, numAnimales);
    } else {
        for(int i = 0; i<numAnimales; i++){
            array[i] = crearAnimalPorTeclado();
        }
    }

    ///SALIDA
    mostrarAnimales(array, numAnimales);
    printf("\n\n Ordenado Por Peso --->");
    ordenarPorPeso(array, numAnimales);
    mostrarAnimales(array, numAnimales);

    return 0;
};


