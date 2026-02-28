#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
struct Lista{
    NodoPtr primero;
};
typedef struct Lista * ListaPtr;
ListaPtr crearLista(int dato, NodoPtr siguiente);
void liberarLista(ListaPtr l);
void mostrarLista(ListaPtr l);
void anadirUltimo(ListaPtr l, NodoPtr n);

#endif // LISTA_H_INCLUDED
