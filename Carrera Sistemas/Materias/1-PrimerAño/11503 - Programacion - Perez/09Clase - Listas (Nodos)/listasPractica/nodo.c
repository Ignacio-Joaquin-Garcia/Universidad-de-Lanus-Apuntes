#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

NodoPtr crearNodo(int d, NodoPtr siguiente){
    NodoPtr n = (NodoPtr) malloc(sizeof(struct Nodo));
    n->dato = d;
    n->siguiente = siguiente;
    return n;
};
void mostrarNodo(NodoPtr n){
    printf("{ %d }", n->dato);
};
