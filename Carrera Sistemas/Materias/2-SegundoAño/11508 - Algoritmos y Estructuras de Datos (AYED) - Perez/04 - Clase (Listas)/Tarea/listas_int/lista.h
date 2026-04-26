#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;
typedef struct Lista * ListaPtr;

///Constructor
ListaPtr crearLista();
///Destructor
void liberarLista(ListaPtr lista);
///Insertar
void insertarPrimero(ListaPtr lista, int dato);
void insertarUltimo(ListaPtr lista, int dato);
void insertarPosicion(ListaPtr lista, int dato, int posicion);
void insertarEnOrden(ListaPtr lista, int dato);
///Obtencion
int obtenerPrimero(ListaPtr lista);
int obtenerUltimo(ListaPtr lista);
int obtenerPosicicon(ListaPtr lista, int posicion);
int obtenerTamanio(ListaPtr lista);
///Eliminacion
void eliminarPrimero(ListaPtr lista);
void eliminarUltimo(ListaPtr lista);
void eliminarPosicicon(ListaPtr lista, int posicion);
///Utiles
void ordenarLista(ListaPtr lista);
ListaPtr ordenarListaCopia(ListaPtr lista);
ListaPtr duplicarLista(ListaPtr lista);
int buscarElemento(ListaPtr lista, int datoBuscado);
///Muestreo
void mostrarLista(ListaPtr lista);
///Getters
NodoPtr getPrimero(ListaPtr l);
///Setters
void setPrimero(ListaPtr l, NodoPtr primero);



#endif // LISTA_H_INCLUDED
