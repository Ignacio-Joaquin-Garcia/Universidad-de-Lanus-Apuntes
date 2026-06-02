#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
void insertarPrimero(ListaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;
};
void insertarUltimo(ListaPtr lista, DatoPtr dato){
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
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion){
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
/*
void insertarEnOrden(ListaPtr lista, DatoPtr dato){
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
*/
void insertarEnOrdenGenerico(ListaPtr lista, DatoPtr dato, bool (*ptrFuncionOrdenamiento)(DatoPtr, DatoPtr)){
    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;

    if(actual == NULL){
        insertarPrimero(lista, dato);
        return;
    }

    if(ptrFuncionOrdenamiento(getDato(actual), dato)){
        insertarPrimero(lista, dato);
        return;
    }

    while(actual != NULL && !ptrFuncionOrdenamiento(getDato(actual), dato)){
        anterior = actual;
        actual = getSiguiente(actual);
    }

    NodoPtr nuevo = crearNodo(dato, actual);
    setSiguiente(anterior, nuevo);
};
///Obtencion
DatoPtr obtenerPrimero(ListaPtr lista){
    return getDato(lista->primero);
};
DatoPtr obtenerUltimo(ListaPtr lista){
    NodoPtr actual = lista->primero;
    while(getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    return getDato(actual);
};

DatoPtr obtenerPosicion(ListaPtr lista, int posicion){
    NodoPtr actual = lista->primero;
    for(int i = 0; i < obtenerTamanio(lista); i++){
        if(i == posicion){
            return getDato(actual);
        }
        actual = getSiguiente(actual);
    }
    return NULL;
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
void eliminarPosicion(ListaPtr lista, int posicion){
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
/*
void ordenarLista(ListaPtr lista){
    void * aux;
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

*/
void ordenarListaGenericaSeleccion(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr)){
    void * aux;
    NodoPtr actualI = lista->primero;
    NodoPtr actualJ = lista->primero;
    for(int i = 0; i < obtenerTamanio(lista)-1; i++){
        for(int j = i+1; j < obtenerTamanio(lista); j++){
            actualJ = getSiguiente(actualJ);
            if(ptrFuncionOrdenar(getDato(actualI), getDato(actualJ))){
                aux = getDato(actualJ);
                setDato(actualJ, getDato(actualI));
                setDato(actualI, aux);
            }
        }
        actualI = getSiguiente(actualI);
        actualJ = actualI;
    }
};
void ordenarListaGenericaBurbuja(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr)){
    bool bandera = false;
    NodoPtr auxJ;
    DatoPtr aux;

    for(int i = 0; i < obtenerTamanio(lista)-1; i++){
        bandera = false;
        NodoPtr actualJ = lista->primero;
        for(int j = 0; j < obtenerTamanio(lista)-1-i; j++){
            auxJ = getSiguiente(actualJ);
            if(ptrFuncionOrdenar(getDato(actualJ), getDato(auxJ))){
                aux = getDato(actualJ);
                setDato(actualJ, getDato(auxJ));
                setDato(auxJ, aux);
                bandera = true;
            }
            actualJ = getSiguiente(actualJ);
        }
        if(!bandera){ break; };
    };
}
void ordenarListaGenericaInsercion(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr)){
    //Imposible en listas simplemente enlazadas, se necesitaria un enlaze doble
};
ListaPtr ordenarListaCopiaGenerica(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr)){
    ListaPtr copiaLista = duplicarLista(lista);
    ordenarListaGenericaBurbuja(copiaLista, ptrFuncionOrdenar);
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

///Busqueda
/*
int buscarElementoInt(ListaPtr lista, int datoBuscado){
    NodoPtr actual = lista->primero;
    int i = 0;
    while(actual != NULL){
        if((*(int*) getDato(actual)) == datoBuscado){
            return i;
        }
        actual = getSiguiente(actual);
        i++;
    }
    return -1;
};
int buscarElementoFloat(ListaPtr lista, float datoBuscado){
    NodoPtr actual = lista->primero;
    int i = 0;
    while(actual != NULL){
        if((*(float*) getDato(actual)) == datoBuscado){
            return i;
        }
        actual = getSiguiente(actual);
        i++;
    }
    return -1;
};
int buscarElementoString(ListaPtr lista, char datoBuscado[]){
    NodoPtr actual = lista->primero;
    int i = 0;
    while(actual != NULL){
        if(strcmp(datoBuscado, ((char*) getDato(actual))) == 0){
            return i;
        }
        actual = getSiguiente(actual);
        i++;
    }
    return -1;
};
*/
int buscarElementoSecuencialGenerico(ListaPtr lista, DatoPtr datoBuscado, bool (*ptrFuncionComparar)(DatoPtr, DatoPtr)){
    NodoPtr actual = lista->primero;
    int i = 0;
    while(actual != NULL){
        if(ptrFuncionComparar(datoBuscado, getDato(actual))){
            return i;
        }
        actual = getSiguiente(actual);
        i++;
    }
    return -1;
}
int buscarElementoBinarioGenerico(ListaPtr lista, DatoPtr datoBuscado, int (*ptrFuncionCompararBinario)(DatoPtr, DatoPtr)){
    //Cabe resaltar que si bien esta funcion anda no tiene sentido en Listas simplemente enlazadas y en general en listas
    //En mi caso use una funcion "obtenerPosicion" para poder ejecutar el buscar binario pero esta funcion termina tardando mas que una busqueda secuencial normal

    int izq = 0;
    int der = obtenerTamanio(lista)-1;
    int m;

    while(izq <= der){
        m = (izq + der) / 2;
        if(ptrFuncionCompararBinario(datoBuscado, obtenerPosicion(lista, m)) == 0){
            return m;
        } else{
            if(ptrFuncionCompararBinario(datoBuscado, obtenerPosicion(lista, m)) > 0){
                der = m-1;
            } else{
                izq = m+1;
            }
        }
    }
    return -1;
};

///Mostrar
/*
void mostrarListaInt(ListaPtr lista){
    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;
    while (actual!=NULL){
        mostrarNodoInt(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};
void mostrarListaString(ListaPtr lista){
    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;
    while(actual != NULL){
        mostrarNodoChar(actual);
        actual = getSiguiente(actual);
    };
    printf("\n\n");
};
void mostrarListaFloat(ListaPtr lista){
    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;
    while(actual != NULL){
        mostrarNodoFloat(actual);
        actual = getSiguiente(actual);
    };
    printf("\n\n");
};
*/
void mostrarListaGenerica(ListaPtr lista, void (*ptrFuncionMostrar)(DatoPtr)){
    printf("\n<LISTA>\n");
    NodoPtr actual = lista->primero;
    while (actual!=NULL){
        (*ptrFuncionMostrar)(getDato(actual));
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

