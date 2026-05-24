#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef void * DatoPtr;

struct Nodo;
typedef struct Nodo * NodoPtr;

NodoPtr crearNodo();
void liberarNodo(NodoPtr nodo);

void insertarArbol(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));

void mostrarArbolPreorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));
void mostrarArbolInorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));
void mostrarArbolPostorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));

NodoPtr buscarBinario(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));
NodoPtr eliminarDatoArbol(NodoPtr arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));
int contador2Hijos(NodoPtr arbol);
NodoPtr buscarMenorMayores(NodoPtr arbol);


///Getters
DatoPtr getDato(NodoPtr nodo);
NodoPtr getIzquierda(NodoPtr nodo);
NodoPtr getDerecha(NodoPtr nodo);
///Setters
void setDato(NodoPtr nodo, DatoPtr dato);
void setIzquierda(NodoPtr nodoCambio, NodoPtr nodo);
void setDerecha(NodoPtr nodoCambio, NodoPtr nodo);

#endif // ARBOL_H_INCLUDED
