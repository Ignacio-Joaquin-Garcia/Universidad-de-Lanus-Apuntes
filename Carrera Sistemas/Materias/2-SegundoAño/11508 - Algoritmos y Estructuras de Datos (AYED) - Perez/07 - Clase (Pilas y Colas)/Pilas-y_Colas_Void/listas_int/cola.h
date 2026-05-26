#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Cola; ///SOLO puntero al ultimo

typedef struct Cola * ColaPtr;


NodoPtr getUltimo(ColaPtr Cola);
NodoPtr getPrimero(ColaPtr Cola);

void setUltimo(ColaPtr Cola, NodoPtr nuevoUltimo);
void setPrimero(ColaPtr Cola, NodoPtr nuevoPrimero);


ColaPtr crearCola();
void insertarUltimo(ColaPtr Cola, DatoPtr dato); ///ENCOLAR - ENQUEUE
DatoPtr eliminarPrimero(ColaPtr Cola); ///DESENCOLAR - DEQUEUE
ColaPtr duplicarCola(ColaPtr Cola);//tarea
void liberarCola(ColaPtr Cola);




#endif // LISTA_H_INCLUDED
