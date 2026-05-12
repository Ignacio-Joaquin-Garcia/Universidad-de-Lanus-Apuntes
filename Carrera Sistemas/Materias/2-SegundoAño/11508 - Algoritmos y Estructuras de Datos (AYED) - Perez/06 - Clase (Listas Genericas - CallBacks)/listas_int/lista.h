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
//void insertarEnOrden(ListaPtr lista, DatoPtr dato);
void insertarEnOrdenGenerico(ListaPtr lista, DatoPtr dato, bool (*ptrFuncionOrdenamiento)(DatoPtr, DatoPtr));
///Obtencion
DatoPtr obtenerPrimero(ListaPtr lista);
DatoPtr obtenerUltimo(ListaPtr lista);
DatoPtr obtenerPosicion(ListaPtr lista, int posicion);
int obtenerTamanio(ListaPtr lista);
///Eliminacion
void eliminarPrimero(ListaPtr lista);
void eliminarUltimo(ListaPtr lista);
void eliminarPosicion(ListaPtr lista, int posicion);
///Utiles
//void ordenarLista(ListaPtr lista);
//ListaPtr ordenarListaCopia(ListaPtr lista);
void ordenarListaGenericaSeleccion(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr));
void ordenarListaGenericaBurbuja(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr));
void ordenarListaGenericaInsercion(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr));
ListaPtr duplicarLista(ListaPtr lista);
ListaPtr ordenarListaCopiaGenerica(ListaPtr lista, bool (*ptrFuncionOrdenar)(DatoPtr, DatoPtr));
///Busqueda
/*
int buscarElementoInt(ListaPtr lista, int datoBuscado);
int buscarElementoFloat(ListaPtr lista, float datoBuscado);
int buscarElementoString(ListaPtr lista, char datoBuscado[]);
*/
int buscarElementoSecuencialGenerico(ListaPtr lista, DatoPtr datoBuscado, bool (*ptrFuncionComparar)(DatoPtr, DatoPtr));
int buscarElementoBinarioGenerico(ListaPtr lista, DatoPtr datoBuscado, int (*ptrFuncionCompararBinario)(DatoPtr, DatoPtr));
///Mostrar
/*
void mostrarListaInt(ListaPtr lista);
void mostrarListaString(ListaPtr lista);
void mostrarListaFloat(ListaPtr lista);
void mostrarLista(ListaPtr lista);
*/
void mostrarListaGenerica(ListaPtr lista, void (*ptrFuncionMostrar)(DatoPtr));
///Getters
NodoPtr getPrimero(ListaPtr l);
///Setters
void setPrimero(ListaPtr l, NodoPtr primero);


#endif // LISTA_H_INCLUDED
