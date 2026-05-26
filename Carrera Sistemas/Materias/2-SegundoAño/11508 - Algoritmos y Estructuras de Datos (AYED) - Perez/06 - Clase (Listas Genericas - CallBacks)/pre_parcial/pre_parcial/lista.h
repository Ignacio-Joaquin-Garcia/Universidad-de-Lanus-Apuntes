#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();

NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

// Insertar:
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

// Eliminar:
DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

// Obtener:
NodoPtr obtenerPrimero(ListaPtr lista);
int obtenerTamanio(ListaPtr lista);

// Mostrar/Liberar/Duplicar:
void mostrarLista(ListaPtr lista, void (*mostrarDato)(NodoPtr));
void liberarLista(ListaPtr lista);


void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));

#endif // LISTA_H_INCLUDED
