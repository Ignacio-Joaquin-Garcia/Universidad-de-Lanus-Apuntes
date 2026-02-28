#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
///Nodo

NodoPtr crearNodo(int dato, NodoPtr siguiente){
    NodoPtr n = (NodoPtr) malloc(sizeof(struct Nodo));
    n->dato = dato;
    n->siguiente = siguiente;
    return n;
};
void liberarNodo(NodoPtr n){
    free(n);
};
void mostrarNodo(NodoPtr n){
    printf("--NODO--\n");
    printf("Dato: %d\n", n->dato);
};
