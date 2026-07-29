#include <stdio.h>
#include <stdlib.h>

#include "ArbolBinario.h"

/// Arbol Binario
struct NodoArbol{
    DatoPtr dato;
    NodoArbolPtr izquierda;
    NodoArbolPtr derecha;
};


/// Creacion y Destruccion
NodoArbolPtr crearNodo(DatoPtr d){
    NodoArbolPtr nodo = (NodoArbolPtr) malloc(sizeof(struct NodoArbol));

    nodo->dato = d;
    nodo->derecha = NULL;
    nodo->izquierda = NULL;

    return nodo;
};



/// Insertar
void insertarEnArbol(NodoArbolPtr n, DatoPtr d, int (*busquedaGenerica)(DatoPtr, DatoPtr)){
    // ¿Izquierda o Derecha?
    // Si es mayor va a la derecha
    if (busquedaGenerica(d, n->dato) > 0){
        // Tienes espacio a la derecha?
        if (n->derecha == NULL){
            n->derecha = crearNodo(d);
        } else{
            // Si la derecha ya está ocupada, recursividad
            insertarEnArbol(n->derecha, d, busquedaGenerica);
        }
    } else{
        if (n->izquierda == NULL){
            n->izquierda = crearNodo(d);
        } else{
            insertarEnArbol(n->izquierda, d, busquedaGenerica);
        }
    }
};


/// Mostrar
// ()-> Copiar o Recrear la estructura del arbol
void preOrden(NodoArbolPtr n, void (*mostrarGenerico)(DatoPtr)){
    if (n != NULL){
        mostrarGenerico(n->dato);
        preOrden(n->izquierda, mostrarGenerico);
        preOrden(n->derecha, mostrarGenerico);
    }
};
// ()-> Imprimir el arbol listando los datos de manera ordenada
void inOrden(NodoArbolPtr n, void (*mostrarGenerico)(DatoPtr)){
    if (n != NULL){
        inOrden(n->izquierda, mostrarGenerico);
        mostrarGenerico(n->dato);
        inOrden(n->derecha, mostrarGenerico);
    }
};
// ()-> Sirve para Borrar Nodos
void postOrden(NodoArbolPtr n, void (*mostrarGenerico)(DatoPtr)){
    if (n != NULL){
        postOrden(n->izquierda, mostrarGenerico);
        postOrden(n->derecha, mostrarGenerico);
        mostrarGenerico(n->dato);
    }
};


/// Busqueda
NodoArbolPtr buscarBinario(NodoArbolPtr n, DatoPtr d, int (*busquedaGenerica)(DatoPtr, DatoPtr)){
    if (n == NULL){ return NULL; };
    if (n->dato == d){
        return n;
    } else{
        if (busquedaGenerica(d, n->dato) > 0){
            return buscarBinario(n->derecha, d, busquedaGenerica);
        } else{
            return buscarBinario(n->izquierda, d, busquedaGenerica);
        }
    }
};


/// TDA
//Getters
DatoPtr getDatoArbol(NodoArbolPtr n){
    return n->dato;
};
NodoArbolPtr getIzquierdaArbo(NodoArbolPtr n){
    return n->izquierda;
};
NodoArbolPtr getDerechaArbol(NodoArbolPtr n){
    return n->derecha;
};

//Setters
void setDatoArbol(NodoArbolPtr n, DatoPtr d){
    n->dato = d;
};
void setIzquierdaArbol(NodoArbolPtr n, NodoArbolPtr i){
    n->izquierda = i;
};
void setDerechaArbol(NodoArbolPtr n, NodoArbolPtr d){
    n->derecha = d;
};
