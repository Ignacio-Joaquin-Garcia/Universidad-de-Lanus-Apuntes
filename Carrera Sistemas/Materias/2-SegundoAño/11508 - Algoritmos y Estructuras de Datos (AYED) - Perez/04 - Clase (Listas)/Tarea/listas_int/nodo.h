#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * NodoPtr;
///Constructor
NodoPtr crearNodo(int dato, NodoPtr siguiente);
///Destructor
void liberarNodo(NodoPtr nodo);
///Muestreo
void mostrarNodo(NodoPtr nodo);

///Getters
int getDato(NodoPtr n);
NodoPtr getSiguiente(NodoPtr n);
///Setters
void setDato(NodoPtr n, int dato);
void setSiguiente(NodoPtr n, NodoPtr siguiente);



#endif // NODO_H_INCLUDED
