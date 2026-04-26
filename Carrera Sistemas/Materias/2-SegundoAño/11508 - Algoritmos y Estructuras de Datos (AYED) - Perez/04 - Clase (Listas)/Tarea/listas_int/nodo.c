#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo {
    int dato;
    struct Nodo * siguiente;
};
///Constructor
NodoPtr crearNodo(int dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->siguiente = siguiente;
    return nodo;
};
void mostrarNodo(NodoPtr nodo){
    printf("{ %d }", nodo->dato);
};
void liberarNodo(NodoPtr nodo){
    free(nodo);
};
///Getters
int getDato(NodoPtr n){
    return n->dato;
}
NodoPtr getSiguiente(NodoPtr n){
    return n->siguiente;
}
///Setters
void setDato(NodoPtr n, int dato){
    n->dato = dato;
}
void setSiguiente(NodoPtr n, NodoPtr siguiente){
    n->siguiente = siguiente;
}
