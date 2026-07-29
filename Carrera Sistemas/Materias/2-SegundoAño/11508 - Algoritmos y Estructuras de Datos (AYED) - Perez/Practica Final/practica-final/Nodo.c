#include <stdio.h>
#include <stdlib.h>

#include "Nodo.h"

struct Nodo{
    DatoPtr dato;
    NodoPtr siguiente;
};

///Creador Y Destructor
NodoPtr crearNodoParametros(DatoPtr dato, NodoPtr siguiente){
    NodoPtr n = (NodoPtr) malloc(sizeof(struct Nodo));

    n->dato = dato;
    n->siguiente = siguiente;

    return n;
};
void liberarNodo(NodoPtr n){
    free(n);
};

/// (Mostrar Nodo)
void mostrarNodoGenerico(NodoPtr n, void (*mostrarGenerico)(DatoPtr)){
    printf("--NODO--\n");
    printf("\tDato: ");
    if (n == NULL){
        printf("NULL\n");
    } else{
        mostrarGenerico(n->dato);
    }
};

///TDA
//Getters
DatoPtr getDato(NodoPtr n){
    return n->dato;
};
NodoPtr getSiguiente(NodoPtr n){
    return n->siguiente;
};

//Setters
void setDato(NodoPtr n, DatoPtr d){
    n->dato = d;
};
void setSiguiente(NodoPtr n, NodoPtr nSet){
    n->siguiente = nSet;
};
