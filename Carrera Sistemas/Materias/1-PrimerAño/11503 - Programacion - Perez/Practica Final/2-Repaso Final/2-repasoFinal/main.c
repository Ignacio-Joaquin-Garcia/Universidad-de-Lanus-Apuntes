#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "lista.h"

int main()
{
    ListaPtr vector = crearLista(3, NULL);

    NodoPtr n1 = crearNodo(200, NULL);
    anadirUltimo(vector, n1);
    NodoPtr n2 = crearNodo(300, NULL);
    anadirUltimo(vector, n2);

    mostrarLista(vector);
    return 0;
}
