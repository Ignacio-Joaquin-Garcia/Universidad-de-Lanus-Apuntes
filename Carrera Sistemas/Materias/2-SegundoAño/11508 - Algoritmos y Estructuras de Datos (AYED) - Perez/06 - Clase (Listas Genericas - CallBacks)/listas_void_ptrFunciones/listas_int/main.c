#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "lista.h"

int main()
{

    PersonaPtr p1 = crearPersona(1, "Nico");
    PersonaPtr p2 = crearPersona(33, "Walter");
    PersonaPtr p3 = crearPersona(12, "Brenda");

    ListaPtr lista = crearLista();

    insertarPrimero(lista, &p1);
    insertarPrimero(lista, &p2);
    insertarPrimero(lista, &p3);


    mostrarListaGenerica(lista, &mostrarPersonaDatoPtr);

    ordenarLista(lista, &compararPersonasDatoPtr);

     mostrarListaGenerica(lista, &mostrarPersonaDatoPtr);



    return 0;
}
