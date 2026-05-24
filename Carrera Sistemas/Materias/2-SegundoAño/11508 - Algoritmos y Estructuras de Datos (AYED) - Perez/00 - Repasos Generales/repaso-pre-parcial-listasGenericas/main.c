#include <stdio.h>
#include <stdlib.h>

#include "ListasGenericas.h"
#include "Motivos.h"
#include "Persona.h"


/*
void mostrarNodoInt(void * d){
    int dato = *(int*) d;
    printf("\n\t{ %d }", dato);
};
*/

int main()
{
    /*
    ListaGenericaPtr lista = crearLista();

    int * n1 = malloc(sizeof(int));
    int * n2 = malloc(sizeof(int));
    int * n3 = malloc(sizeof(int));

    *n1 = 8;
    *n2 = 11;
    *n3 = 2;

    insertarPrimero(lista, n1);
    insertarPrimero(lista, n2);
    insertarPrimero(lista, n3);

    mostrarListaGenerica(lista, mostrarNodoInt);
    */

    ListaGenericaPtr ListaPersonasEstadio = crearLista();

    PersonaPtr p1 = crearPersonaParametros("Jaun");
    MotivosPtr p1m1 = crearMotivosParametros(1, "juan queria asistir mucho1");
    MotivosPtr p1m2 = crearMotivosParametros(2, "juan queria asistir mucho2");
    MotivosPtr p1m3 = crearMotivosParametros(3, "juan queria asistir mucho3");

    PersonaPtr p2 = crearPersonaParametros("Coco");
    PersonaPtr p3 = crearPersonaParametros("Zael");

    insertarPrimero(ListaPersonasEstadio, p1);
    insertarPrimero(ListaPersonasEstadio, p2);
    insertarPrimero(ListaPersonasEstadio, p3);

    insertarPrimero(getListaMotivos(p1), p1m1);
    insertarPrimero(getListaMotivos(p1), p1m2);
    insertarPrimero(getListaMotivos(p1), p1m3);

    mostrarListaGenerica(ListaPersonasEstadio, mostrarPersonaGenerico);


    return 0;
}
