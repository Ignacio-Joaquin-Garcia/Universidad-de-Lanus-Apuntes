#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int main()
{
    ListaPtr lista = crearLista();

    int n1 = 2, n2 = 1, n3 = 3, n4 = 6;
    insertarPrimero(lista, &n1);
    insertarUltimo(lista, &n2);
    insertarUltimo(lista, &n3);
    insertarUltimo(lista, &n4);
    insertarUltimo(lista, &n1);
    insertarUltimo(lista, &n2);
    mostrarListaInt(lista);

    printf("Tam Lista: %d\n",  obtenerTamanio(lista));
    printf("Num Pos 1: %d\n", *(int *) obtenerPosicicon(lista, 1));
    printf("Primer Num: %d\n", *(int *) obtenerPrimero(lista));
    printf("Ultimo Num: %d\n", *(int *) obtenerUltimo(lista));

    ListaPtr listaCopia = duplicarLista(lista);
    mostrarListaInt(listaCopia);

    ListaPtr listaCopia2 = ordenarListaCopia(lista);
    mostrarListaInt(listaCopia2);

    eliminarPrimero(listaCopia2);
    eliminarUltimo(listaCopia2);
    eliminarPosicicon(listaCopia2, 7);
    mostrarListaInt(listaCopia2);
    printf("Pos del Numero 2: %d\n", buscarElementoInt(listaCopia2, 2));

    ListaPtr listaString = crearLista();
    insertarPrimero(listaString, "pepe");
    insertarPrimero(listaString, "pedro");
    insertarPrimero(listaString, "juan");
    eliminarPrimero(listaString);
    insertarPosicion(listaString, "pepe2", 2);
    mostrarListaString(listaString);
    printf("Pos del string 'pedro': %d\n", buscarElementoString(listaString, "pedro"));
    printf("Pos del string 'juan': %d\n", buscarElementoString(listaString, "juan"));
    printf("Ultimo de la Lista: %s\n", (char*) obtenerUltimo(listaString));

    ListaPtr listaFloat = crearLista();
    float pi = 3.14, euler = 2.71828, oro = 1.61803;
    insertarPrimero(listaFloat, &pi);
    insertarPrimero(listaFloat, &euler);
    insertarPrimero(listaFloat, &oro);
    insertarPrimero(listaFloat, &pi);
    eliminarPrimero(listaFloat);
    mostrarListaFloat(listaFloat);
    printf("Pos del Float 3.14: %d\n", buscarElementoFloat(listaFloat, 3.14));

    return 0;
}
