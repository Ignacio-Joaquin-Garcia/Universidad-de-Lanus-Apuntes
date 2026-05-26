#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pasajero.h"

struct Pasajero{
    char apellido[20];
    int dni;
    char ventanilla;
};

PasajeroPtr crearPasajero(char* apellido, int dni, char ventanilla){
    PasajeroPtr p = (PasajeroPtr) malloc(sizeof(struct Pasajero));

    strcpy(p->apellido, apellido);
    p->dni = dni;
    p->ventanilla = ventanilla;

    return p;
};

char* getApellido(PasajeroPtr p){
    return p->apellido;
}
int getDni(PasajeroPtr p){
    return p->dni;
}
char getVentanilla(PasajeroPtr p){
    return p->ventanilla;
}

void setApellido(PasajeroPtr p, char* apellido){
    strcpy(p->apellido, apellido);
}
void setDni(PasajeroPtr p, int dni){
    p->dni = dni;
}
void setVentanilla(PasajeroPtr p, char ventanilla){
    p->ventanilla = ventanilla;
}

void mostrarPasajero(PasajeroPtr p){

    printf("\n---------PASAJERO---------\n");
    printf("\nAPELLIDO: %s\n", p->apellido);
    printf("\nDNI: %d\n", p->dni);
    printf("\nVENTANILLA: %c\n", p->ventanilla);
}


void mostrarPsajeroDatoPtr (void * p){

    PasajeroPtr pasajero = (PasajeroPtr )p;

    mostrarPasajero(pasajero);


}





void liberarPasajero(PasajeroPtr p){
    free(p);
}
