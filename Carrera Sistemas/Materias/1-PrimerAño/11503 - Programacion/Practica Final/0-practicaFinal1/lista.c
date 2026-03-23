#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

ListaPtr crearLista(){
    ListaPtr l = (ListaPtr) malloc(sizeof(struct Lista));
    l->primero = NULL;
    return l;
};
void mostrarLista(ListaPtr l){
    NodoPtr actual = l->primero;
    while(actual != NULL){
        if(actual->p->altura != -1){
            mostrarNodo(actual);
        }
        actual = actual->siguiente;
    }
};
void anadirPrimero(ListaPtr l, NodoPtr n){
    NodoPtr aux = l->primero;
    l->primero = n;
    n->siguiente = aux;
};
void anadirUltimo(ListaPtr l, NodoPtr n){
    NodoPtr actual = l->primero;
    if(actual == NULL){
        l->primero = n;
    } else{
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        actual->siguiente = n;
    }
};
void anadirCaricaturaALaLista(ListaPtr l, struct Caricatura c){
    NodoPtr actual = l->primero;
    if(l->primero == NULL){
        l->primero = crearNodo(c.poseePersonajes[0], NULL);
        actual = l->primero;
        for(int i = 1; i < 10;i++){
            actual->siguiente = crearNodo(c.poseePersonajes[i], NULL);
            actual = actual->siguiente;
        }
    } else{
        while (actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        for(int i = 0; i < 10;i++){
            actual->siguiente = crearNodo(c.poseePersonajes[i], NULL);
            actual = actual->siguiente;
        }
    }
};
float calculoPromedioAlturaPersonajes(ListaPtr l){
    float promedioAltura;
    int acumuladorAltura = 0;
    int contadorPersonajes = 0;
    NodoPtr actual = l->primero;
    if(actual == NULL){
        printf("\n\nLa lista dada no contiene nada!\n\n");
        promedioAltura = -1;
    } else{
        while(actual != NULL){
            if(actual->p->altura != -1){
                acumuladorAltura = acumuladorAltura + actual->p->altura;
                contadorPersonajes = contadorPersonajes + 1;
            }
            actual = actual->siguiente;
        }
        promedioAltura = (float) acumuladorAltura / contadorPersonajes;
    }
    return promedioAltura;
};
