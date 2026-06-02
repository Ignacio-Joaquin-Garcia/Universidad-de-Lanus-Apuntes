#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef void * DatoPtr;
struct Nodo;
typedef struct Nodo * NodoPtr;

///Basicas para Arboles Binarios
NodoPtr crearNodo();
void liberarNodo(NodoPtr nodo);

void insertarArbol(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));

void mostrarArbolPreorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));
void mostrarArbolInorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));
void mostrarArbolPostorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr));
//Muestra del arbol acostado para debuggear (Derecha -> Raiz -> Izquierda)
void mostrarArbolAcostado(NodoPtr nodo, int nivel, void (*mostrarNodoGenerico)(DatoPtr));

NodoPtr buscarBinario(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));
NodoPtr eliminarDatoArbol(NodoPtr arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));
int contador2Hijos(NodoPtr arbol);
NodoPtr buscarMenorMayores(NodoPtr arbol);

///Arboles AVL
//Utiles
int alturaArbol(NodoPtr arbol);
int balanceo(NodoPtr arbol);
int rotarDer(NodoPtr * arbol);
int rotarIzq(NodoPtr * arbol);
int reOrdenar(NodoPtr * arbol, NodoPtr * auxArbol);
void balancearArbol(NodoPtr * arbol);
//Insertar y Eliminar Balanceado
void insertarArbolBalanceado(NodoPtr * arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));
NodoPtr eliminarDatoArbolBalanceado(NodoPtr arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr));
//Metricas de Arboles
int obtenerPeso(NodoPtr arbol);
int obtenerCantidadTotalHojas(NodoPtr arbol);
int obtenerNivel(NodoPtr arbol, NodoPtr nodoNivel);
NodoPtr obtenerMinNodo(NodoPtr arbol);
NodoPtr obtenerMaxNodo(NodoPtr arbol);



///Getters
DatoPtr getDato(NodoPtr nodo);
NodoPtr getIzquierda(NodoPtr nodo);
NodoPtr getDerecha(NodoPtr nodo);
///Setters
void setDato(NodoPtr nodo, DatoPtr dato);
void setIzquierda(NodoPtr nodoCambio, NodoPtr nodo);
void setDerecha(NodoPtr nodoCambio, NodoPtr nodo);

#endif // ARBOL_H_INCLUDED
