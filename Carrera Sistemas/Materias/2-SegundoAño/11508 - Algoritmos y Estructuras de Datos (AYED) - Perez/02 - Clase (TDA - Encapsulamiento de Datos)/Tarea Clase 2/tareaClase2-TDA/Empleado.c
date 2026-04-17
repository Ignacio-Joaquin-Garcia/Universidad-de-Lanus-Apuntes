#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Empleado.h"
struct Empleado{
    PersonaPtr pHerencia;
    char legajo[50];
    int sueldo;
    char empresa[50];
};

EmpleadoPtr crearEmpleadoParametros(char nombre[50], char apellido[50], int dni, int edad, char legajo[50], int sueldo, char empresa[50]){
    EmpleadoPtr e = malloc(sizeof(struct Empleado));

    strcpy(e->legajo, legajo);
    strcpy(e->empresa, empresa);
    e->sueldo = sueldo;
    //Reutilizacion de los metodos de Persona
    e->pHerencia = crearPersonaParametros(nombre, apellido, dni, edad);

    return e;
};
void mostrarEmpleado(EmpleadoPtr e){
    printf("---Empleado---\n");
    printf("\tEmpresa: %s\n", e->empresa);
    printf("\tLegajo: %s\n", e->legajo);
    printf("\tSueldo: %d\n", e->sueldo);
    mostrarPersona(e->pHerencia);
};




//Setters
bool setLegajo(EmpleadoPtr e, char legajo[50]){
    strcpy(e->legajo, legajo);
    return true;
};
bool setEmpresa(EmpleadoPtr e, char empresa[50]){
    strcpy(e->empresa, empresa);
    return true;
};
bool setSueldo(EmpleadoPtr e, int sueldo){
    e->sueldo = sueldo;
    return true;
};
bool setPersona(EmpleadoPtr e, PersonaPtr p){
    e->pHerencia = p;
    return true;
};
//Getters
char * getLegajo(EmpleadoPtr e){
    return e->legajo;
}
char * getEmpresa(EmpleadoPtr e){
    return e->empresa;
}
int getSueldo(EmpleadoPtr e){
    return e->sueldo;
}
PersonaPtr getPersona(EmpleadoPtr e){
    return e->pHerencia;
}
