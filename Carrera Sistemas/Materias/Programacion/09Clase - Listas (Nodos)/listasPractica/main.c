#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funciones.h"
#include "nodo.h"
#include "lista.h"


int main()
{
    srand(time(0));
    ListaPtr vector = crearLista();

    insertarPrimero(vector, 20);
    insertarPrimero(vector, 2000);
    insertarUltimo(vector, 10);
    printTamano(vector);
    insertarPos(vector, 5, 1);



    mostrarLista(vector);
    printTamano(vector);

    ordenarLista(vector);
    busquedaBinariaElemento(vector, 5);

    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);
    insertarAleatorioPos(vector, 1, 0, 10);

    mostrarLista(vector);

    return 0;
}






