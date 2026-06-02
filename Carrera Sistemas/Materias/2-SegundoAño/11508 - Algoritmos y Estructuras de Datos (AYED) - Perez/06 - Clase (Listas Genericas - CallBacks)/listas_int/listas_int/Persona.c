#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    printf("--Persona--\n");
    printf("\tNombre: %s\n", p->nombre);
    printf("\tEdad: %d\n", p->edad);
};


///Genericas
void mostrarPersonaGenerica(void * dato){
    PersonaPtr p = (PersonaPtr) (dato);
    mostrarPersona(p);
}
bool funcionOrdenarPersonasGenerica(void * d1, void * d2){
   PersonaPtr p1 = (PersonaPtr) (d1);
   PersonaPtr p2 = (PersonaPtr) (d2);

   if(p1->edad > p2->edad){
        return true;
   } else{
        return false;
   }
}
bool funcionCompararGenerica(void * d1, void * d2){
    PersonaPtr p1 = (PersonaPtr) d1;
    PersonaPtr p2 = (PersonaPtr) d2;
    if(strcmp(p1, p2) == 0){
        return true;
    } else{
        return false;
    }
};
int funcionCompararBinarioGenerica(void * d1, void * d2){
    PersonaPtr p1 = (PersonaPtr) d1;
    PersonaPtr p2 = (PersonaPtr) d2;
    if(strcmp(p1, p2) == 0){
        return 0;
    } else{
        if(strcmp(p1, p2) > 0){
            return 1;
        } else{
            return -1;
        }
    }
};
