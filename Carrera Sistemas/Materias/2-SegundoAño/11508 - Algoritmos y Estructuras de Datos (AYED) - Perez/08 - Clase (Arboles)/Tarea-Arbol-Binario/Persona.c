#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Persona.h"

struct Persona{
    char nombre[45];
    int edad;
};

PersonaPtr crearPersonaParametros(char nombre[45], int edad){
    PersonaPtr p = (PersonaPtr) malloc(sizeof(struct Persona));

    strcpy(p->nombre, nombre);
    p->edad = edad;

    return p;
};

void mostrarPersona(PersonaPtr p){
    printf("\n--Persona--");
    printf("\n\tNombre: %s", p->nombre);
    printf("\n\tEdad: %d", p->edad);
};

void mostrarPersonaGenerico(void * dato){
    PersonaPtr p = (PersonaPtr) dato;
    mostrarPersona(p);
};

int busquedaPersonaGenerico(void * datoNodo, void * datoBuscado){
    PersonaPtr pNodo = (PersonaPtr) datoNodo;
    PersonaPtr pBuscado = (PersonaPtr) datoBuscado;

    if(pNodo->edad == pBuscado->edad){
        return 0;
    }
    if(pNodo->edad > pBuscado->edad){
        return -1;
    } else{
        return 1;
    }
};

///Getters
char * getNombre(PersonaPtr p){
    return p->nombre;
};
int getEdad(PersonaPtr p){
    return p->edad;
};
///Setters
void setNombre(PersonaPtr p, char nombre[45]){
    strcpy(p->nombre, nombre);
};
void setEdad(PersonaPtr p, int edad){
    p->edad = edad;
};
