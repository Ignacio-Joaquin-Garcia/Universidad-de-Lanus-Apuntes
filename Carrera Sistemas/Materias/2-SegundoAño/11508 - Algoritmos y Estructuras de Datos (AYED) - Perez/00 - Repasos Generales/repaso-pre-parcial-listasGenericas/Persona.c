#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListasGenericas.h"
#include "Motivos.h"
#include "Persona.h"

struct Persona{
    char nombre[50];
    ListaGenericaPtr motivos;
};

PersonaPtr crearPersonaParametros(char nombre[50]){
    PersonaPtr p = malloc(sizeof(struct Persona));

    strcpy(p->nombre, nombre);
    p->motivos = crearLista();

    return p;
};

void mostrarPersonaGenerico(void * dato){
    PersonaPtr p = (PersonaPtr) dato;
    printf("\n\t--Persona--");
    printf("\n\t\tNombre: %s", p->nombre);
    mostrarListaGenerica(p->motivos, mostrarMotivosGenericos);
};

ListaGenericaPtr getListaMotivos(PersonaPtr p){
    return p->motivos;
};
void setListaMotivos(PersonaPtr p, ListaGenericaPtr m){
    liberarLista(m);
    p->motivos = m;
};
