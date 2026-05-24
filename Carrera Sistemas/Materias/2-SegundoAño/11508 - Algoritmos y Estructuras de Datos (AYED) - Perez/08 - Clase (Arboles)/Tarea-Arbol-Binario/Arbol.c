#include <stdio.h>
#include <stdlib.h>

#include "Arbol.h"

struct Nodo{
    NodoPtr izquierda;
    NodoPtr derecha;
    DatoPtr dato;
};

NodoPtr crearNodo(DatoPtr dato){
    NodoPtr n = (NodoPtr) malloc(sizeof(struct Nodo));

    if(dato != NULL){
         n->dato = dato;
    }
    n->derecha = NULL;
    n->izquierda = NULL;

    return n;
};
void liberarNodo(NodoPtr nodo){
    free(nodo->dato);
    free(nodo);
}


void insertarArbol(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(nodo == NULL){
        nodo = crearNodo(dato);
        return;
    }

    if(busquedaGenerico(nodo->dato, dato) < 0){
        if(nodo->izquierda == NULL){
            nodo->izquierda = crearNodo(dato);
        } else{
            insertarArbol(nodo->izquierda, dato, busquedaGenerico);
        }
    } else{
        if(nodo->derecha == NULL){
            nodo->derecha = crearNodo(dato);
        } else{
            insertarArbol(nodo->derecha, dato, busquedaGenerico);
        }
    }
};

void mostrarArbolPreorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarNodoGenerico(nodo->dato);
        mostrarArbolPreorden(nodo->izquierda, mostrarNodoGenerico);
        mostrarArbolPreorden(nodo->derecha, mostrarNodoGenerico);
    };
};
void mostrarArbolInorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarArbolInorden(nodo->izquierda, mostrarNodoGenerico);
        mostrarNodoGenerico(nodo->dato);
        mostrarArbolInorden(nodo->derecha, mostrarNodoGenerico);
    };
};
void mostrarArbolPostorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarArbolPostorden(nodo->izquierda, mostrarNodoGenerico);
        mostrarArbolPostorden(nodo->derecha, mostrarNodoGenerico);
        mostrarNodoGenerico(nodo->dato);
    };
};

NodoPtr buscarBinario(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(nodo == NULL){ return NULL; };
    if(busquedaGenerico(nodo->dato, dato) == 0){
        return nodo;
    } else{
        if(busquedaGenerico(nodo->dato, dato) < 0){
            return buscarBinario(nodo->izquierda, dato, busquedaGenerico);
        } else{
            return buscarBinario(nodo->derecha, dato, busquedaGenerico);
        }
    }
};

NodoPtr eliminarDatoArbol(NodoPtr arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(arbol == NULL){
        printf("El Dato no existe en el arbol!\n");
        return NULL;
    }
    int rta = busquedaGenerico(arbol->dato, dato);

    // buscar izquierda
    if(rta < 0){
        arbol->izquierda = eliminarDatoArbol(arbol->izquierda, dato, busquedaGenerico);
        return arbol;
    }
    // buscar derecha
    if(rta > 0){
        arbol->derecha = eliminarDatoArbol(arbol->derecha, dato, busquedaGenerico);
        return arbol;
    }

    // ENCONTRADO
    int cantHijos = contador2Hijos(arbol);
    switch(cantHijos){
        case 0:{
            liberarNodo(arbol);
            return NULL;
        }
        case 1:{
            if(arbol->izquierda != NULL){
                NodoPtr aux = arbol->izquierda;
                liberarNodo(arbol);
                return aux;
            } else{
                NodoPtr aux = arbol->derecha;
                liberarNodo(arbol);
                return aux;
            }
        }
        case 2:{
            NodoPtr menor = buscarMenorMayores(arbol);

            //Cambio de Punteros a los datos para correcta liberacion de memoria
            DatoPtr aux = arbol->dato;
            arbol->dato = menor->dato;
            menor->dato = aux;

            arbol->derecha = eliminarDatoArbol(arbol->derecha, menor->dato, busquedaGenerico);
            return arbol;
        }
    }
    return arbol;
};
int contador2Hijos(NodoPtr arbol){
    if(arbol == NULL){
        return -1;
    }
    int hijos = 0;
    if(arbol->izquierda != NULL){
        hijos++;
    }
    if(arbol->derecha != NULL){
        hijos++;
    }
    return hijos;
}
NodoPtr buscarMenorMayores(NodoPtr arbol){
    if(arbol == NULL || arbol->derecha == NULL){
        return NULL;
    }
    NodoPtr actual = arbol->derecha;
    while(actual->izquierda != NULL){
        actual = actual->izquierda;
    }
    return actual;
 }



///Getters
DatoPtr getDato(NodoPtr nodo){
    return nodo->dato;
};
NodoPtr getIzquierda(NodoPtr nodo){
    return nodo->izquierda;
};
NodoPtr getDerecha(NodoPtr nodo){
    return nodo->derecha;
};
///Setters
void setDato(NodoPtr nodo, DatoPtr dato){
    nodo->dato = dato;
};
void setIzquierda(NodoPtr nodoCambio, NodoPtr nodo){
    nodoCambio->izquierda = nodo;
};
void setDerecha(NodoPtr nodoCambio, NodoPtr nodo){
    nodoCambio->derecha = nodo;
};
