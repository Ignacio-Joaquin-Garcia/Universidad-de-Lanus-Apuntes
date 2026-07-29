#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct Lista{
    NodoPtr primero;
};

///Creador Y Destructor
ListaPtr crearLista(){
    ListaPtr l = (ListaPtr) malloc(sizeof(struct Lista));

    l->primero = NULL;

    return l;
};
void liberarLista(ListaPtr l){
    NodoPtr actual = l->primero;

    while (actual != NULL){
        NodoPtr aux = actual;
        actual = getSiguiente(actual);
        liberarNodo(aux);
    }

    free(l);
};

///Insercion
void insertarPrimero(ListaPtr l, DatoPtr d){
    if (l->primero == NULL){
        l->primero = crearNodoParametros(d, NULL);
    } else{
        NodoPtr nuevoNodo = crearNodoParametros(d, l->primero);
        l->primero = nuevoNodo;
    }
};
void insertarUltimo(ListaPtr l, DatoPtr d){
    if (l->primero == NULL){
        l->primero = crearNodoParametros(d, NULL);
        return;
    }

    NodoPtr actual = l->primero;

    while (getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }

    NodoPtr nuevoNodo = crearNodoParametros(d, NULL);
    setSiguiente(actual, nuevoNodo);
}
void insertarPos(ListaPtr l, DatoPtr d, int pos){
    int tam = tamLista(l);
    NodoPtr actual = l->primero;

    if (pos >= tam){
        insertarUltimo(l, d);
        return;
    }
    if (pos == 0){
        insertarPrimero(l, d);
        return;
    }


    for (int i = 1; i<pos; i++){
        actual = getSiguiente(actual);
    }
    NodoPtr nuevoNodo = crearNodoParametros(d, getSiguiente(actual));
    setSiguiente(actual, nuevoNodo);
};

///Utiles
ListaPtr duplicarLista(ListaPtr l){
    ListaPtr nuevaLista = crearLista();
    NodoPtr actual = l->primero;

    while (actual != NULL){
        insertarUltimo(nuevaLista, getDato(actual));
        actual = getSiguiente(actual);
    }

    return nuevaLista;
};
ListaPtr duplicarYOrdenar(ListaPtr l, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    ListaPtr nuevaLista = duplicarLista(l);
    ordenarListaGenerico(nuevaLista, busquedaGenerico);
    return nuevaLista;
}
int tamLista(ListaPtr l){
    int tam = 0;
    NodoPtr actual = l->primero;

    while (actual != NULL){
        actual = getSiguiente(actual);
        tam++;
    }

    return tam;
};


///Funciones Genericas
//Muestreo
void mostrarListaGenerico(ListaPtr l, void (*mostrarGenerico)(DatoPtr)){
    NodoPtr actual = l->primero;
    printf("--Lista--\n");
    while (actual != NULL){
        mostrarGenerico(getDato(actual));
        actual = getSiguiente(actual);
    }
};
//Ordenar
void ordenarListaGenerico(ListaPtr l, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    NodoPtr i = l->primero;
    NodoPtr j = getSiguiente(i);
    while (getSiguiente(i) != NULL){
        while(j != NULL){
            if (busquedaGenerico(getDato(i), getDato(j)) < 0){
                DatoPtr aux = getDato(i);
                setDato(i, getDato(j));
                setDato(j, aux);
            }
            j = getSiguiente(j);
        }
        i = getSiguiente(i);
        j = getSiguiente(i);
    }
};
//Busqueda
NodoPtr busquedaSecuencialGenerico(ListaPtr l, DatoPtr datoBuscado, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    NodoPtr actual = l->primero;

    while (actual != NULL){
        if(busquedaGenerico(getDato(actual), datoBuscado) == 0){
            return actual;
        }
        actual = getSiguiente(actual);
    }

    return NULL;
};



///TDA
//Getters
NodoPtr getPrimero(ListaPtr l){
    return l->primero;
};

//Setters
void setPrimero(ListaPtr l, NodoPtr n){
    l->primero = n;
};
