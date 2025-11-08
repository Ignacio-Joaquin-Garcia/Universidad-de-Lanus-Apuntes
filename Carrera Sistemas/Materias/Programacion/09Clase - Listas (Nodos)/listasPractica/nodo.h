#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo{
    int dato;
    struct Nodo * siguiente;
};
typedef struct Nodo * NodoPtr;
NodoPtr crearNodo(int d, NodoPtr siguiente);
void mostrarNodo(NodoPtr n);

#endif // NODO_H_INCLUDED
