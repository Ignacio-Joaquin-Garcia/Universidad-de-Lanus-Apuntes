#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personaje.h"


///PERSONAJE
PersonajePtr crearPersonajeParametros(char nombre[100], char tipo[100], float altura){
    PersonajePtr p = malloc(sizeof(struct Personaje));
    strcpy(p->nombre, nombre);
    strcpy(p->tipo, tipo);
    p->altura = altura;
    return p;
};
void mostrarPersonaje(PersonajePtr p){
    printf("\n\t\t--PERSONAJE--");
    printf("\n\t\t\tNombre: %s", p->nombre);
    printf("\n\t\t\tTipo: %s", p->tipo);
    printf("\n\t\t\tAltura: %.2f", p->altura);
    printf("\n");
};
PersonajePtr crearPersonajeVacio(){
    PersonajePtr p = malloc(sizeof(struct Personaje));
    p = crearPersonajeParametros("VACIO", "VACIO", -1);
    return p;
};
void crearPersonajesVacios(PersonajePtr contenedorPersonajes[100]){
    for(int i = 0; i<100; i++){
        contenedorPersonajes[i] = crearPersonajeVacio();
    }
};
void mostrarPersonajes(PersonajePtr contenedorPersonajes[100]){
    for(int i = 0; i<100; i++){
        if(contenedorPersonajes[i]->altura != -1){
            mostrarPersonaje(contenedorPersonajes[i]);
        }
    }
};
