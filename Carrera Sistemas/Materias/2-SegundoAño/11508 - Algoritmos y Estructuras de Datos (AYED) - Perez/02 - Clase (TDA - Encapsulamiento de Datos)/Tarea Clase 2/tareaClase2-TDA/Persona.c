#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Persona.h"
struct Persona{
    char nombre[50];
    char apellido[50];
    int dni;
    int edad;
    DispositivosTecPtr poseeDispositivosTec[5];
};

PersonaPtr crearPersonaParametros(char nombre[50], char apellido[50], int dni, int edad){
    PersonaPtr p = malloc(sizeof(struct Persona));

    strcpy(p->nombre, nombre);
    strcpy(p->apellido, apellido);
    p->dni = dni;
    p->edad = edad;

    for(int i = 0; i<5; i++){
        p->poseeDispositivosTec[i] = crearDispositivoTecParametros("VACIO", "VACIO", -1, "VACIO");
    };

    return p;
};
void mostrarPersona(PersonaPtr p){
    printf("\t---Persona---\n");
    printf("\t\tNombre: %s\n", p->nombre);
    printf("\t\tApellido: %s\n", p->apellido);
    printf("\t\tDNI: %d\n", p->dni);
    printf("\t\tEdad: %d\n", p->edad);
    printf("\t\tDispositivos Tecnologicos: \n");
    for(int i = 0; i < 5; i++){
        //Tiene que acceder por medio de getter
        if(getPrecio(p->poseeDispositivosTec[i]) != -1){
            mostrarDispositivoTec(p->poseeDispositivosTec[i]);
        };
    };
};

//Setters

bool setNombre(PersonaPtr p, char nombre[50]){
    strcpy(p->nombre, nombre);
    return true;
};
bool setApellido(PersonaPtr p, char apellido[50]){
    strcpy(p->apellido, apellido);
    return true;
};
bool setDni(PersonaPtr p, int dni){
    p->dni = dni;
    return true;
};
bool setEdad(PersonaPtr p, int edad){
    p->edad = edad;
    return true;
};
bool setDispositivosTec(PersonaPtr p, DispositivosTecPtr d){
    for(int i = 0; i < 5; i++){
        if(getPrecio(p->poseeDispositivosTec[i]) == -1){
            p->poseeDispositivosTec[i] = d;
            return true;
        };
    };
    return false;
};

//Getters
char * getNombre(PersonaPtr p){
    return p->nombre;
};
char * getApellido(PersonaPtr p){
    return p->apellido;
};
int getDni(PersonaPtr p){
    return p->dni;
};
int getEdad(PersonaPtr p){
    return p->edad;
};
DispositivosTecPtr getDispositivoTec(PersonaPtr p, int posDispositivo){
    return p->poseeDispositivosTec[posDispositivo];
};
