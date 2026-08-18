#include "nodo.h"
#include "personaje.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

NodoPtr crearNodo(PersonajePtr p, NodoPtr siguiente){
    NodoPtr n = malloc(sizeof(struct Nodo));
    n->p = p;
    n->siguiente = siguiente;
    return  n;
};
void mostrarNodo(NodoPtr n){
    printf("\n\t--Nodo--");
    mostrarPersonaje(n->p);
};
