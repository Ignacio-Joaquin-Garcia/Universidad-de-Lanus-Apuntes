#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    mostrarLista(lista);

    insertarPrimero(lista, 2);
    insertarUltimo(lista, 1);
    insertarUltimo(lista, 0);
    insertarUltimo(lista, -5);
    insertarUltimo(lista, 10);
    insertarUltimo(lista, 9);
    mostrarLista(lista);
    ordenarLista(lista);
    insertarEnOrden(lista, 8);
    mostrarLista(lista);

    insertarPosicion(lista, 111, 0);
    insertarPosicion(lista, -1, 0);
    insertarPosicion(lista, 2, 0);

    printf("Tam Lista: %d\n", obtenerTamanio(lista));
    printf("Num Pos 1: %d\n", obtenerPosicicon(lista, 1));
    printf("Primer Num: %d\n", obtenerPrimero(lista));
    printf("Ultimo Num: %d\n", obtenerUltimo(lista));

    ListaPtr listaCopia = duplicarLista(lista);
    mostrarLista(listaCopia);

    ListaPtr listaCopia2 = ordenarListaCopia(lista);
    mostrarLista(listaCopia2);

    eliminarPrimero(listaCopia2);
    eliminarUltimo(listaCopia2);
    eliminarPosicicon(listaCopia2, 7);
    mostrarLista(listaCopia2);

    printf("Pos del Numero 2: %d", buscarElemento(listaCopia2, 2));

    return 0;
}
