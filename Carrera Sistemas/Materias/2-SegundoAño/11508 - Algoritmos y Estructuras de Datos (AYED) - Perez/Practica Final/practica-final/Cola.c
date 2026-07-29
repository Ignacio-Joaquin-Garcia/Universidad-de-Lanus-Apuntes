#include <stdio.h>
#include <stdlib.h>

#include "Cola.h"

struct Cola{
    NodoPtr primero;
    NodoPtr ultimo;
};

///Creador Y Destructor
ColaPtr crearCola(){
    ColaPtr cola = (ColaPtr) malloc(sizeof(struct Cola));

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
};
void liberarCola(ColaPtr c){
    DatoPtr d = desencolar(c);
    while (d != NULL){ // Bucle desencolando, No recorriendo la cola
        d = desencolar(c);
    }
    free(c);
};

///Insercion y Obtencion
void encolar(ColaPtr c, DatoPtr d){
    NodoPtr nuevoNodo = crearNodoParametros(d, NULL);
    if (c->ultimo == NULL){
        c->primero = nuevoNodo;
        c->ultimo = nuevoNodo;
    }else{
        setSiguiente(c->ultimo, nuevoNodo);
        c->ultimo = nuevoNodo;
    }
};
NodoPtr desencolar(ColaPtr c){
    if (c->primero == NULL){ return NULL; }
    NodoPtr n = c->primero;

    c->primero = getSiguiente(c->primero);
    if (c->primero == NULL){
        c->ultimo = NULL;
    }

    return n;
};


///TDA
//Getters
NodoPtr getPrimeroCola(ColaPtr c){
    return c->primero;
};
NodoPtr getUltimoCola(ColaPtr c){
    return c->ultimo;
};
//Setters
void setPrimeroCola(ColaPtr c, NodoPtr n){
    c->primero = n;
};
void setUltimoCola(ColaPtr c, NodoPtr n){
    c->ultimo = n;
};
