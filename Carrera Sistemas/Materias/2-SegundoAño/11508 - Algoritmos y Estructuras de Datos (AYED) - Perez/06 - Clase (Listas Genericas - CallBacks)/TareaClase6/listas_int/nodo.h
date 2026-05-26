#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef void * DatoPtr;
struct Nodo;
typedef struct Nodo * NodoPtr;
///Constructor
NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);
///Destructor
void liberarNodo(NodoPtr nodo);
///Mostrar
void mostrarNodoInt(DatoPtr dato);
void mostrarNodoChar(DatoPtr dato);
void mostrarNodoFloat(DatoPtr dato);
///Getters
DatoPtr getDato(NodoPtr n);
NodoPtr getSiguiente(NodoPtr n);
///Setters
void setDato(NodoPtr n, DatoPtr dato);
void setSiguiente(NodoPtr n, NodoPtr siguiente);



#endif // NODO_H_INCLUDED
