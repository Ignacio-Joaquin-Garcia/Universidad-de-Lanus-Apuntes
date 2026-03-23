#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista{
    NodoPtr primero;
};
typedef struct Lista * ListaPtr;
ListaPtr crearLista();

//Basicas
void mostrarLista(ListaPtr l);
void liberarLista(ListaPtr l);
int obtenerTamano(ListaPtr l);
void printTamano(ListaPtr l);
//Insertar
void insertarPrimero(ListaPtr l, int dato);
void insertarUltimo(ListaPtr l, int dato);
void insertarPos(ListaPtr l, int dato, int posAInsertar);
void insertarAleatorioPos(ListaPtr l, int posAInsertar, int min, int max);
//Eliminar
void eliminarPrimero(ListaPtr l);
void eliminarUltimo(ListaPtr l);
void eliminarPos(ListaPtr l, int posAELiminar);
//Obtener
int obtenerPrimero(ListaPtr l);
int obtenerUltimo(ListaPtr l);
int obtenerPos(ListaPtr l, int pos);
int obtenerMinimo(ListaPtr l);
int obtenerMaximo(ListaPtr l);
//Modificacion
void modificarPrimero(ListaPtr l, int datoCambio);
void modificarUltimo(ListaPtr l, int datoCambio);
void modificarPos(ListaPtr l, int posAModificar, int datoCambio);
//Utiles
void ordenarLista(ListaPtr l);
void buscarElemento(ListaPtr l, int elementoBuscado);
void busquedaBinariaElemento(ListaPtr l, int elementoBuscado);
int estaVacia(ListaPtr l);
void printEstaVacia(ListaPtr l);

#endif // LISTA_H_INCLUDED
