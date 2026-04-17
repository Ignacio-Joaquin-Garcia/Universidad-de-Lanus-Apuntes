#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "vectores.h"
#include "matrices.h"

int main()
{
    srand(time(0));

    ///Vectores
    VectorPtr v1 = crearVector(5);
    int vCarga[8] = {1,2,3,4,5,6,7,8};
    cargarVectorParametros(vCarga, 8, v1);
    printf("Vector 1:\n");
    mostrarVector(v1);
    cargarVectorAleatorio(v1, 0, 10);
    printf("Vector 1:\n");
    mostrarVector(v1);
    mostrarVectorInvertido(v1);
    ordenarVector(v1);
    printf("Vector 1:\n");
    mostrarVector(v1);

    printf("Minimo: %d\n", buscarMinimoVector(v1));
    printf("Maximo: %d\n", buscarMaximoVector(v1));

    VectorPtr v2 = crearVector(8);
    cargarVectorAleatorio(v2, 0, 10);
    printf("Vector 2:\n");
    mostrarVector(v2);
    printf("Suma de Vectores: %d\n", sumaDeVectores(v1, v2));


    printf("Numero 8 Encontrado en Pos: %d\n", busquedaSecuencialVector(v1, 8));
    printf("Numero 2 Encontrado en Pos: %d\n", busquedaBinariaVector(v1, 8));

    ///Matrices
    MatrizPtr m1 = crearMatriz(2, 3);
    cargarMatrizAleatoria(m1);
    mostrarMatriz(m1);

    printf("Maximo Matriz: %d\n", buscarMaximoMatriz(m1));
    printf("Minimo Matriz: %d\n", buscarMinimoMatriz(m1));
    printf("Suma Matriz: %d\n", sumaDeMatriz(m1));
    printf("Promedio Matriz: %d\n", promedioMatriz(m1));
    printf("Producto Matriz: %ld\n", productoDeMatriz(m1));

    m1 = cambiarTamMatriz(m1, 10, 6);
    cargarMatrizAleatoria(m1);
    mostrarMatriz(m1);

    int mCarga[2][2] = {
    {5, 8},
    {10, 25}
    };
    MatrizPtr m2 = crearMatriz(1,1);
    cargarMatrizParametros(m2, 2, 2, mCarga);
    mostrarMatriz(m2);

    return 0;
}



