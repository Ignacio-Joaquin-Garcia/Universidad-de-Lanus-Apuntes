#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"


struct Pila; ///SOLO puntero al ultimo

typedef struct Pila * PilaPtr;


NodoPtr getUltimo(PilaPtr pila);
void setUltimo(PilaPtr pila, NodoPtr nuevoUltimo);


PilaPtr crearPila();
void insertarUltimo(PilaPtr pila, DatoPtr dato); ///APILAR - PUSH
DatoPtr eliminarUltimo(PilaPtr pila); ///DESAPILAR - POP
PilaPtr duplicarPila(PilaPtr pila);//tarea
void liberarPila(PilaPtr pila);




#endif // LISTA_H_INCLUDED
