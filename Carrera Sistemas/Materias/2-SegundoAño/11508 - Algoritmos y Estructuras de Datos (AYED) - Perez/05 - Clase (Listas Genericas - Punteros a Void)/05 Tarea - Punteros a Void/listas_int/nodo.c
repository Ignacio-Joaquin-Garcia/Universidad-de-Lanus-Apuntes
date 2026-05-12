#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"


struct Nodo {
    DatoPtr dato;
    NodoPtr siguiente;
};
///Constructor
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->siguiente = siguiente;
    return nodo;
};
///Mostrar
void mostrarNodoInt(NodoPtr nodo){
    printf("{ %d }", *(int*) (nodo->dato));
};
void mostrarNodoChar(NodoPtr nodo){
    printf("{ %s }", (char*) (nodo->dato));
};
void mostrarNodoFloat(NodoPtr nodo){
    printf("{ %.2f }", *(float*) (nodo->dato));
};
void liberarNodo(NodoPtr nodo){
    free(nodo);
};
///Getters
DatoPtr getDato(NodoPtr n){
    return n->dato;
}
NodoPtr getSiguiente(NodoPtr n){
    return n->siguiente;
}
///Setters
void setDato(NodoPtr n, DatoPtr dato){
    n->dato = dato;
}
void setSiguiente(NodoPtr n, NodoPtr siguiente){
    n->siguiente = siguiente;
}
