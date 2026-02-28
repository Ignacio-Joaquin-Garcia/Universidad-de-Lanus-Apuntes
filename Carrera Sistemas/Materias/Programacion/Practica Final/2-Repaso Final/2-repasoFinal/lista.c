#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
///Lista

ListaPtr crearLista(int dato, NodoPtr siguiente){
    ListaPtr l = (ListaPtr) malloc(sizeof(struct Lista));
    l->primero = crearNodo(dato, siguiente);
    return l;
};
void liberarLista(ListaPtr l){
    free(l);
}
void mostrarLista(ListaPtr l){
    printf("--LISTA--\n");
    NodoPtr actual = l->primero;
    int i = 0;
    while(actual != NULL){
        printf("%d: %d\n", i,actual->dato);
        actual = actual->siguiente;
        i++;
    }
};
void anadirUltimo(ListaPtr l, NodoPtr n){
    NodoPtr actual = l->primero;
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }
    actual->siguiente = n;
};
