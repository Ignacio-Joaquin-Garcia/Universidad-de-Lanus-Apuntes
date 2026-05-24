#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"

struct Dato{
    void * dato;
};

struct Nodo{
    DatoPtr dato;
    NodoPtr siguiente;
};

NodoPtr crearNodoParametros(DatoPtr dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->siguiente = siguiente;

    return nodo;
};
void liberarNodo(NodoPtr nodo){
    free(nodo);
};

void mostrarNodo(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    printf("\n--Nodo--");
    mostrarNodoGenerico(nodo->dato);
};

///Getters
DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo){
    return nodo->siguiente;
};

///Setters
void setDato(NodoPtr nodo, DatoPtr dato);
void setSiguiente(NodoPtr nodo, NodoPtr nodoSiguiente){
    nodo->siguiente = nodoSiguiente;
};
