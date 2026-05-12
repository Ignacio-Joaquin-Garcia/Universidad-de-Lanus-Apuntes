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
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);
void insertarEnOrden(ListaPtr lista, DatoPtr dato);
///Obtencion
DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicicon(ListaPtr lista, int posicion);
int obtenerTamanio(ListaPtr lista);
///Eliminacion
void eliminarPrimero(ListaPtr lista);
void eliminarUltimo(ListaPtr lista);
void eliminarPosicicon(ListaPtr lista, int posicion);
///Utiles
void ordenarLista(ListaPtr lista);
ListaPtr ordenarListaCopia(ListaPtr lista);
ListaPtr duplicarLista(ListaPtr lista);
///Busqueda
int buscarElementoInt(ListaPtr lista, int datoBuscado);
int buscarElementoFloat(ListaPtr lista, float datoBuscado);
int buscarElementoString(ListaPtr lista, char datoBuscado[]);
///Mostrar
void mostrarListaInt(ListaPtr lista);
void mostrarListaString(ListaPtr lista);
void mostrarListaFloat(ListaPtr lista);
void mostrarLista(ListaPtr lista);
///Getters
NodoPtr getPrimero(ListaPtr l);
///Setters
void setPrimero(ListaPtr l, NodoPtr primero);


#endif // LISTA_H_INCLUDED
