#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{
    printf("----- Ejemplo arbol binario ----\n");

    Nodo raiz = nuevoNodo(28);
    insertar(raiz, 11);
    insertar(raiz, 96);
    insertar(raiz, 21);
    insertar(raiz, 6);
    insertar(raiz, 97);
    insertar(raiz, 1);
    insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);

    printf("\nImprimiendo preorden\n");
    preorden(raiz);
    printf("\nImprimiendo inorden\n");
    inorden(raiz);
    printf("\nImprimiendo postorden\n");
    postorden(raiz);

    printf("\nBuscando el 30\n");
    Nodo buscado = buscar(raiz, 30);

    if(buscado == NULL){
        printf("No encontrado!!!!!");
    }

    else{

        printf("Encontrado");
    }



    return 0;
}
