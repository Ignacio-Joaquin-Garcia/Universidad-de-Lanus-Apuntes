#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"
#include "caricatura.h"
struct Lista{
    NodoPtr primero;
};
typedef struct Lista * ListaPtr;

ListaPtr crearLista();

void mostrarLista(ListaPtr l);
void anadirPrimero(ListaPtr l, NodoPtr n);
void anadirUltimo(ListaPtr l, NodoPtr n);
void anadirCaricaturaALaLista(ListaPtr l, struct Caricatura c);
float calculoPromedioAlturaPersonajes(ListaPtr l);

#endif // LISTA_H_INCLUDED
