#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

/// Arbol Binario
typedef void * DatoPtr;
struct NodoArbol;
typedef struct NodoArbol * NodoArbolPtr;


/// Creacion y Destruccion
NodoArbolPtr crearNodo(DatoPtr d);


/// Insertar
void insertarEnArbol(NodoArbolPtr n, DatoPtr d, int (*busquedaGenerica)(DatoPtr, DatoPtr));

/// Mostrar
void preOrden(NodoArbolPtr n, void (*mostrarGenerico)(DatoPtr));
void inOrden(NodoArbolPtr n, void (*mostrarGenerico)(DatoPtr));
void postOrden(NodoArbolPtr n, void (*mostrarGenerico)(DatoPtr));

/// Busqueda
NodoArbolPtr buscarBinario(NodoArbolPtr n, DatoPtr d, int (*busquedaGenerica)(DatoPtr, DatoPtr));


/// TDA
//Getters
DatoPtr getDatoArbol(NodoArbolPtr n);
NodoArbolPtr getIzquierdaArbo(NodoArbolPtr n);
NodoArbolPtr getDerechaArbol(NodoArbolPtr n);

//Setters
void setDatoArbol(NodoArbolPtr n, DatoPtr d);
void setIzquierdaArbol(NodoArbolPtr n, NodoArbolPtr i);
void setDerechaArbol(NodoArbolPtr n, NodoArbolPtr d);


#endif // ARBOLBINARIO_H_INCLUDED
