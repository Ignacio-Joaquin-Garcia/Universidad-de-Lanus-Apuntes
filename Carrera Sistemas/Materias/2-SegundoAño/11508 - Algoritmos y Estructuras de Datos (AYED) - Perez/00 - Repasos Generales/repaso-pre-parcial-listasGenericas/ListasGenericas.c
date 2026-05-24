#include <stdio.h>
#include <stdlib.h>
#include "ListasGenericas.h"

struct ListaGenerica{
    NodoPtr primero;
};

ListaGenericaPtr crearLista(){
    ListaGenericaPtr lista = (ListaGenericaPtr) malloc(sizeof(struct ListaGenerica));
    lista->primero = NULL;
    return lista;
};
void liberarLista(ListaGenericaPtr lista){
    NodoPtr actual = lista->primero;
    while(actual != NULL){
        liberarNodo(actual);
    }
    free(lista);
};

void insertarPrimero(ListaGenericaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = crearNodoParametros(dato, lista->primero);
    lista->primero = nuevoNodo;
};
void insertarUltimo(ListaGenericaPtr lista, DatoPtr dato);

int obtenerTam(ListaGenericaPtr lista);

DatoPtr obtenerPrimero(ListaGenericaPtr lista);
DatoPtr obtenerUltimo(ListaGenericaPtr lista);

ListaGenericaPtr invertirLista(ListaGenericaPtr lista);

void mostrarListaGenerica(ListaGenericaPtr lista, void (*mostrarNodoGenerico)(DatoPtr)){
    NodoPtr actual = lista->primero;
    while(actual != NULL){
        mostrarNodo(actual, mostrarNodoGenerico);
        actual = getSiguiente(actual);
    }
};

DatoPtr getPrimero(ListaGenericaPtr lista);
void setPrimero(ListaGenericaPtr lista, DatoPtr dato);
