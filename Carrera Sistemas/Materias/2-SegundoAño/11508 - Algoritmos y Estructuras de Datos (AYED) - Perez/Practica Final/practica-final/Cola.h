#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "Nodo.h"
struct Cola;
typedef struct Cola * ColaPtr;

///Creador Y Destructor
ColaPtr crearCola();
void liberarCola(ColaPtr c);

///Insercion y Obtencion
void encolar(ColaPtr c, DatoPtr d);
NodoPtr desencolar(ColaPtr c);

///TDA
//Getters
NodoPtr getPrimeroCola(ColaPtr c);
NodoPtr getUltimoCola(ColaPtr c);
//Setters
void setPrimeroCola(ColaPtr c, NodoPtr n);
void setUltimoCola(ColaPtr c, NodoPtr n);

#endif // COLA_H_INCLUDED
