#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef void * DatoPtr;
struct Nodo;
typedef struct Nodo * NodoPtr;

///Creador Y Destructor
NodoPtr crearNodoParametros(DatoPtr dato, NodoPtr siguiente);
void liberarNodo(NodoPtr n);

/// (Mostrar Nodo)
void mostrarNodoGenerico(NodoPtr n, void (*mostrarGenerico)(DatoPtr));

///TDA
//Getters
DatoPtr getDato(NodoPtr n);
NodoPtr getSiguiente(NodoPtr n);

//Setters
void setDato(NodoPtr n, DatoPtr d);
void setSiguiente(NodoPtr n, NodoPtr nSet);


#endif // NODO_H_INCLUDED
