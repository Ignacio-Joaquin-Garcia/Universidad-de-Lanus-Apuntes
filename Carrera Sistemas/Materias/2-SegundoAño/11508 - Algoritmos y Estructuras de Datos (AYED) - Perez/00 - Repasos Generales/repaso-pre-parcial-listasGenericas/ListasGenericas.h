#ifndef LISTASGENERICAS_H_INCLUDED
#define LISTASGENERICAS_H_INCLUDED

#include "Nodo.h"

struct ListaGenerica;
typedef struct ListaGenerica * ListaGenericaPtr;

ListaGenericaPtr crearLista();
void liberarLista(ListaGenericaPtr lista);

void insertarPrimero(ListaGenericaPtr lista, DatoPtr dato);
void insertarUltimo(ListaGenericaPtr lista, DatoPtr dato);

int obtenerTam(ListaGenericaPtr lista);

DatoPtr obtenerPrimero(ListaGenericaPtr lista);
DatoPtr obtenerUltimo(ListaGenericaPtr lista);

ListaGenericaPtr invertirLista(ListaGenericaPtr lista);

void mostrarListaGenerica(ListaGenericaPtr lista, void (*mostrarNodoGenerico)(DatoPtr));

DatoPtr getPrimero(ListaGenericaPtr lista);
void setPrimero(ListaGenericaPtr lista, DatoPtr dato);

#endif // LISTASGENERICAS_H_INCLUDED
