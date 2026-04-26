#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{
    NodoPtr primero;
};

///Constructor
ListaPtr crearLista(){
    ListaPtr lista = malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
};
///Destructor
void liberarLista(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    while (actual!=NULL){
        free(actual);
        actual = getSiguiente(actual);
    };
}
///Insercion
void insertarPrimero(ListaPtr lista, int dato){
    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;
};
void insertarUltimo(ListaPtr lista, int dato){
    NodoPtr nuevoNodo = crearNodo(dato, NULL);
    if(lista->primero == NULL){
        lista->primero = nuevoNodo;
        return;
    }

    NodoPtr actual = lista->primero;
    while(getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    setSiguiente(actual, nuevoNodo);
};
void insertarPosicion(ListaPtr lista, int dato, int posicion){
    if(posicion > obtenerTamanio(lista) || posicion < 0){
        printf("Posicion fuera de rango en la Lista\n");
        return;
    }
    if(posicion == 0){
        insertarPrimero(lista, dato);
        return;
    }
    NodoPtr actual = lista->primero;
    for(int i = 0; i < posicion-1; i++){
        actual = getSiguiente(actual);
    }
    NodoPtr nuevoNodo = crearNodo(dato, getSiguiente(actual));
    setSiguiente(actual, nuevoNodo);
};
void insertarEnOrden(ListaPtr lista, int dato){
    NodoPtr auxActual;
    NodoPtr actual = lista->primero;
    for(int i = 0; i < obtenerTamanio(lista); i++){
        if(i == 0 && dato <= getDato(actual)){
            insertarPrimero(lista, dato);
            return;
        }
        if(i == obtenerTamanio(lista)-1){
            insertarUltimo(lista, dato);
            return;
        }
        if(dato <= getDato(actual)){
            NodoPtr nuevoNodo = crearNodo(dato, actual);
            setSiguiente(auxActual, nuevoNodo);
            return;
        }
        if(getSiguiente(actual) != NULL){
            auxActual = actual;
            actual = getSiguiente(actual);
        }
    }
};

///Obtencion
int obtenerPrimero(ListaPtr lista){
    return getDato(lista->primero);
};
int obtenerUltimo(ListaPtr lista){
    NodoPtr actual = lista->primero;
    while(getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    return getDato(actual);
};

int obtenerPosicicon(ListaPtr lista, int posicion){
    NodoPtr actual = lista->primero;
    for(int i = 0; i < obtenerTamanio(lista); i++){
        if(i == posicion){
            return getDato(actual);
        }
        actual = getSiguiente(actual);
    }
    return -1;
}
int obtenerTamanio(ListaPtr lista){
    if(lista->primero == NULL){
        return 0;
    }
    NodoPtr actual = lista->primero;
    int t = 1;
    while(getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
        t++;
    }
    return t;
};
///Eliminacion
void eliminarPrimero(ListaPtr lista){
    NodoPtr actual = getSiguiente(lista->primero);
    liberarNodo(lista->primero);
    lista->primero = actual;
};
void eliminarUltimo(ListaPtr lista){
    NodoPtr actual = lista->primero;
    NodoPtr auxActual;
    while(getSiguiente(actual) != NULL){
        auxActual = actual;
        actual = getSiguiente(actual);
    }
    liberarNodo(actual);
    setSiguiente(auxActual, NULL);
};
void eliminarPosicicon(ListaPtr lista, int posicion){
    if(posicion > obtenerTamanio(lista) || posicion < 0){return;};
    if(posicion == 0){
        eliminarPrimero(lista);
        return;
    }
    if(posicion == obtenerTamanio(lista)-1){
        eliminarUltimo(lista);
        return;
    }

    NodoPtr actual = lista->primero;
    NodoPtr auxActual;
    for(int i = 0; i<obtenerTamanio(lista)-1; i++){
        if(i == posicion){
            setSiguiente(auxActual, getSiguiente(actual));
            liberarNodo(actual);
            return;
        }
        auxActual = actual;
        actual = getSiguiente(actual);
    }
};
///Utiles
void ordenarLista(ListaPtr lista){
    int aux;
    NodoPtr actualI = lista->primero;
    NodoPtr actualJ = lista->primero;
    for(int i = 0; i < obtenerTamanio(lista)-1; i++){
        for(int j = i+1; j < obtenerTamanio(lista); j++){
            actualJ = getSiguiente(actualJ);
            if(getDato(actualI) > getDato(actualJ)){
                aux = getDato(actualJ);
                setDato(actualJ, getDato(actualI));
                setDato(actualI, aux);
            }
        }
        actualI = getSiguiente(actualI);
        actualJ = actualI;
    }
};
ListaPtr ordenarListaCopia(ListaPtr lista){
    ListaPtr copiaLista = duplicarLista(lista);
    ordenarLista(copiaLista);
    return copiaLista;
};
ListaPtr duplicarLista(ListaPtr lista){
    ListaPtr copiaLista = crearLista();
    if(lista == NULL){return copiaLista;}
    copiaLista->primero = crearNodo(getDato(lista->primero), NULL);
    NodoPtr actual = lista->primero;
    for(int i = 0; i < obtenerTamanio(lista)-1; i++){
        actual = getSiguiente(actual);
        insertarUltimo(copiaLista, getDato(actual));
    }
    return copiaLista;
};
int buscarElemento(ListaPtr lista, int datoBuscado){
    NodoPtr actual = lista->primero;
    int i = 0;
    while(getSiguiente(actual) != NULL){
        if(getDato(actual) == datoBuscado){
            return i;
        }
        actual = getSiguiente(actual);
        i++;
    }
    return -1;
};
///Muestreo
void mostrarLista(ListaPtr lista){
    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;
    while (actual!=NULL){
        mostrarNodo(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};

///Getters
NodoPtr getPrimero(ListaPtr l){
    return l->primero;
};
///Setters
void setPrimero(ListaPtr l, NodoPtr primero){
    l->primero = primero;
};

