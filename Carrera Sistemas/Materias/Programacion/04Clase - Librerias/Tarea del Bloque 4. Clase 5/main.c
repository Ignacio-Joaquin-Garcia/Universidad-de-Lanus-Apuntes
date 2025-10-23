///------ARCHIVO MAIN.C------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"



int main()
{
    srand(time(0));
    ///DEFINICION Y INICIALIZACION
    int tam = 20;
    int vectorA[tam];
    int vectorB[tam];
    int vectorC[tam];
    int tamCombinado = tam + tam;
    int vectorDConDuplicados[tamCombinado];
    int vectorD[tamCombinado];

    generarArreglo(tam, vectorA);
    generarArreglo(tam, vectorB);

    int numABuscar;

    ///PROCESO
    int posVectorC = eliminarDuplicadosVector(tam, vectorA, vectorC);
    ordenarArreglo(tam, vectorB);
    concatenarVectores(tam, vectorA, tam, vectorB, vectorDConDuplicados);
    int posVectorD = eliminarDuplicadosVector(tamCombinado, vectorDConDuplicados, vectorD);

    ///MOSTRAR
    mostrarArreglo(tam, vectorA, "A");
    mostrarArreglo(tam, vectorB, "B");
    mostrarArreglo(posVectorC, vectorC, "C");
    printf("\nIngrese un numero a buscar para el Vector B: ");
    scanf("%d", &numABuscar);
    printf("\n");
    busquedaBinaria(tam, vectorB, numABuscar);
    mostrarArreglo(posVectorD, vectorD, "D");

    return 0;
}



