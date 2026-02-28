#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "personaje.h"

struct Nodo{
    PersonajePtr p;
    struct Nodo * siguiente;
};
typedef struct Nodo * NodoPtr;

NodoPtr crearNodo(PersonajePtr p, NodoPtr siguiente);
void mostrarNodo(NodoPtr n);

#endif // NODO_H_INCLUDED
