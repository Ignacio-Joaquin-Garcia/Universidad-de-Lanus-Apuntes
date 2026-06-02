#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lista.h"
#include "Persona.h"

int main()
{
    ListaPtr lista = crearLista();

    ///LISTA de INT
    int n1 = 2, n2 = 1, n3 = 3, n4 = 6;
    insertarPrimero(lista, &n1);
    insertarUltimo(lista, &n2);
    insertarUltimo(lista, &n3);
    insertarUltimo(lista, &n4);
    insertarUltimo(lista, &n1);
    insertarUltimo(lista, &n2);


    mostrarListaGenerica(lista, mostrarNodoInt);

    ///LISTA de String
    ListaPtr listaString = crearLista();
    insertarPrimero(listaString, "pepe");
    insertarPrimero(listaString, "pedro");
    insertarPrimero(listaString, "juan");
    eliminarPrimero(listaString);
    insertarPosicion(listaString, "pepe2", 2);


    mostrarListaGenerica(listaString, mostrarNodoChar);

    ///LISTA de Float
    ListaPtr listaFloat = crearLista();
    float pi = 3.14, euler = 2.71828, oro = 1.61803;
    insertarPrimero(listaFloat, &pi);
    insertarPrimero(listaFloat, &euler);
    insertarPrimero(listaFloat, &oro);
    insertarPrimero(listaFloat, &pi);
    eliminarPrimero(listaFloat);


    mostrarListaGenerica(listaFloat, mostrarNodoFloat);

    PersonaPtr p1 = crearPersonaParametros("pepe", 18);
    PersonaPtr p2 = crearPersonaParametros("juan", 30);
    PersonaPtr p3 = crearPersonaParametros("rede", 20);

    ListaPtr listaPersonas = crearLista();

    insertarPrimero(listaPersonas, p3);
    insertarPrimero(listaPersonas, p2);
    insertarPrimero(listaPersonas, p1);

    mostrarListaGenerica(listaPersonas, mostrarPersonaGenerica);
    //ordenarListaGenericaSeleccion(listaPersonas, funcionOrdenarPersonasGenerica);
    ordenarListaGenericaBurbuja(listaPersonas, funcionOrdenarPersonasGenerica);
    mostrarListaGenerica(listaPersonas, mostrarPersonaGenerica);


    PersonaPtr p4 = crearPersonaParametros("pepe2", 19);
    insertarEnOrdenGenerico(listaPersonas, p4, funcionOrdenarPersonasGenerica);
    mostrarListaGenerica(listaPersonas, mostrarPersonaGenerica);

    int posElementoBuscado = buscarElementoBinarioGenerico(listaPersonas, p2, funcionCompararBinarioGenerica);
    printf("La persona 2 se encuentra en: %d\n", posElementoBuscado);

    return 0;
}
