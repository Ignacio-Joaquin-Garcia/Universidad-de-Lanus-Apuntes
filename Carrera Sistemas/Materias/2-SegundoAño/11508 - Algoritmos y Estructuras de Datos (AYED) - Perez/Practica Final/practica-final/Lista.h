#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo.h"
struct Lista;
typedef struct Lista * ListaPtr;

///Creador Y Destructor
ListaPtr crearLista();
void liberarLista(ListaPtr l);

///Insercion
void insertarPrimero(ListaPtr l, DatoPtr d);
void insertarUltimo(ListaPtr l, DatoPtr d);
void insertarPos(ListaPtr l, DatoPtr d, int pos);

///Eliminar


///Obtener


///Utiles
ListaPtr duplicarLista(ListaPtr l);
ListaPtr duplicarYOrdenar(ListaPtr l, int (*busquedaGenerico)(DatoPtr, DatoPtr));
int tamLista(ListaPtr l);

///Funciones Genericas
//Muestreo
void mostrarListaGenerico(ListaPtr l, void (*mostrarGenerico)(DatoPtr));
//Ordenar
void ordenarListaGenerico(ListaPtr l, int (*busquedaGenerico)(DatoPtr, DatoPtr));
//Busqueda
NodoPtr busquedaSecuencialGenerico(ListaPtr l, DatoPtr datoBuscado, int (*busquedaGenerico)(DatoPtr, DatoPtr));

///TDA
//Getters
NodoPtr getPrimero(ListaPtr l);

//Setters
void setPrimero(ListaPtr l, NodoPtr n);


#endif // LISTA_H_INCLUDED
