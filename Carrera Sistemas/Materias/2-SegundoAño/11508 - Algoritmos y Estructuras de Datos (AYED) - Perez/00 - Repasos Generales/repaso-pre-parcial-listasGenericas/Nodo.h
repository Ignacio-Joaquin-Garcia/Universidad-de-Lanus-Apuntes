#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Dato;
typedef struct Dato * DatoPtr;

struct Nodo;
typedef struct Nodo * NodoPtr;

NodoPtr crearNodoParametros(DatoPtr dato, NodoPtr siguiente);
void liberarNodo(NodoPtr nodo);


void mostrarNodo(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));


///Getters
DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

///Setters
void setDato(NodoPtr nodo, DatoPtr dato);
void setSiguiente(NodoPtr nodo, NodoPtr nodoSiguiente);

#endif // NODO_H_INCLUDED
