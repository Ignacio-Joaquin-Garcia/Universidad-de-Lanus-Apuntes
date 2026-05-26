#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{

    NodoPtr primero;

};

NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);


ListaPtr crearLista(){

    ListaPtr lista = malloc(sizeof(struct Lista));

    lista->primero = NULL;

    return lista;
};


void insertarPrimero(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);

    lista->primero = nuevoNodo;


};


void insertarUltimo(ListaPtr lista, DatoPtr dato){

    NodoPtr nuevoNodo = crearNodo(dato, NULL);

    NodoPtr actual = lista->primero;
    if(actual == NULL){
        lista->primero = nuevoNodo;
    }else{
        while(getSiguiente(actual)!=NULL){

            actual = getSiguiente(actual);
        }

       setSiguiente(actual, nuevoNodo);
        }

}; //tarea


void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion); //tarea


DatoPtr obtenerPrimero(ListaPtr lista); //tarea
DatoPtr obtenerUltimo(ListaPtr lista); //tarea
DatoPtr obtenerPosicion(ListaPtr lista, int posicion); //tarea

DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarUltimo(ListaPtr lista); //tarea
DatoPtr eliminarposicion(ListaPtr lista, int posicion); //tarea

int obtenerTamanio(ListaPtr lista){

    int tam = 0 ;
    NodoPtr actual = lista->primero;
    while (actual != NULL){

            tam = tam + 1;
            actual = getSiguiente(actual);

    }

    return tam;
}; //tarea


void ordenarLista(ListaPtr lista, int(*resultadoComparacion)(DatoPtr, DatoPtr)){

    int permutacion;
    NodoPtr nodo;
    NodoPtr ultimo = NULL;

    if(obtenerTamanio(lista)< 2){
        //ya esta ordenada, no hago nada
    } else {

        do{
            permutacion = 0 ;
            nodo = lista->primero;

            while (getSiguiente(nodo) != ultimo){

                if( resultadoComparacion(getDato(nodo),getDato(getSiguiente(nodo)))){


                    DatoPtr aux = getDato(nodo);
                    setDato(nodo, getDato(getSiguiente(nodo)));
                    setDato(getSiguiente(nodo), aux);
                    permutacion = 1;

                }
                nodo = getSiguiente(nodo);

            }
            ultimo = nodo; //opcional!!!

        }while (permutacion!=0);


    }
}

ListaPtr ordenarListaCopia(ListaPtr lista);//tarea
ListaPtr duplicarLista(ListaPtr lista);//tarea

int buscarElemento(ListaPtr lista, DatoPtr datoBuscado);//tarea

void insertarEnOrden(ListaPtr lista, DatoPtr dato);//tarea, si la lista está ordenada cada vez que
//se inserta se inserta en la posición que corresponda


void mostrarLista(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarNodo(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};

void mostrarListaChar(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarChar(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};


void mostrarListaFloat(ListaPtr lista){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrarFloat(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};


void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){

    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        //mostrarFloat(actual);
        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");



};

void liberarLista(ListaPtr lista) {

    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL){
        aux = actual;
        actual = getSiguiente(actual);
        free(aux);
    };
}
