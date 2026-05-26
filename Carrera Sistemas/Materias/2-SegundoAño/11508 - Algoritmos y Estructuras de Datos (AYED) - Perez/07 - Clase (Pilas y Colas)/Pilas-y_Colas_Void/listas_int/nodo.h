#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;


typedef struct Nodo * NodoPtr;

typedef void * DatoPtr; ///Dato del tipo puntero a cualquier cosa

DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);

void mostrarNodo(NodoPtr nodo);
void mostrarChar(NodoPtr nodo);
void mostrarFloat(NodoPtr nodo);

void liberarNodo(NodoPtr nodo);





#endif // NODO_H_INCLUDED
