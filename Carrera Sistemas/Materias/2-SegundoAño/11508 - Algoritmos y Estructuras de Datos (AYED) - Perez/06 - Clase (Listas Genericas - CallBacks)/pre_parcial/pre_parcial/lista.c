#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista {
    NodoPtr primero;
};

ListaPtr crearLista() {
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));
    lista->primero = NULL;

    return lista;
}

NodoPtr getPrimero(ListaPtr lista) {
    return lista->primero;
}
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero) {
    lista->primero = nuevoPrimero;
}

// Insertar:
void insertarPrimero(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;
}
void insertarUltimo(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevoNodo = crearNodo(dato, NULL);


    if(lista->primero == NULL) {
        lista->primero = nuevoNodo;
    } else {
        NodoPtr actual = lista->primero;
        while(getSiguiente(actual)!=NULL) {
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, nuevoNodo);
    }
}
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion) {
    int tam = obtenerTamanio(lista);
    if(posicion > tam+1) {
        printf("No existe esa posicion\n");
    }
    else if(posicion < 0) {
        printf("No existe esa posicion\n");
    }
    else if(posicion == 0) {
        insertarPrimero(lista, dato);
    }
    else if(posicion == tam) {
        insertarUltimo(lista, dato);
    }
    else if(posicion > 0 && posicion < tam){
        NodoPtr actual = lista->primero;
        for(int i=0; i<posicion-1; i++){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, crearNodo(dato, getSiguiente(actual)));
    }
}

// Eliminar:
DatoPtr eliminarPrimero(ListaPtr lista) {
    DatoPtr dato = NULL;
    NodoPtr actual = lista->primero;

    if(actual != NULL) {
        dato = getDato(actual);
        NodoPtr actual = lista->primero;
        lista->primero = getSiguiente(actual);
        liberarNodo(actual);
    }

    return dato;
}
DatoPtr eliminarPosicion(ListaPtr lista, int pos) {
    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;
    DatoPtr dato = NULL;
    int tam = obtenerTamanio(lista);
    int i=0;

    if(actual == NULL){
        printf("Lista vacia\n");
    }
    else if (pos < 0 || pos >= tam) {
        printf("Posicion fuera de rango\n");
    }
    else if(pos == 0){
        dato = eliminarPrimero(lista);
    }
    else if(pos > 0 || pos < tam) {    //pos dentro de la lista
        while(i != pos) {
            anterior = actual;
            actual = getSiguiente(actual);
            i++;
        }
        dato = getDato(actual);
        setSiguiente(anterior, getSiguiente(actual));
        liberarNodo(actual);
    }
    return dato;
}

// Obtener:
NodoPtr obtenerPrimero(ListaPtr lista) {
    return lista->primero;
}
int obtenerTamanio(ListaPtr lista) {
    int tam = 0 ;
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        tam = tam + 1;
        actual = getSiguiente(actual);
    }

    return tam;
}



void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));

    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};



// Mostrar/Liberar/Duplicar:
void mostrarLista(ListaPtr lista, void (*mostrarDato)(NodoPtr)) {
    //printf("<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL) {
        mostrarDato(actual);
        actual = getSiguiente(actual);
    }
    printf("\n");
};
void liberarLista(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL) {
        aux = actual;
        actual = getSiguiente(actual);
        free(aux);
    };
}
