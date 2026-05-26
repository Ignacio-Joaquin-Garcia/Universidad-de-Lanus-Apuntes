#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "avion.h"
#include "aeropuerto.h"

struct Aeropuerto{
    char nombre[20];
    char direccion[20];
    char telefono[15];

    ListaPtr listaAviones;
};

AeropuertoPtr crearAeropuerto(char* nombre, char* direccion, char* telefono){
    AeropuertoPtr a = (AeropuertoPtr) malloc(sizeof(struct Aeropuerto));
    strcpy(a->nombre, nombre);
    strcpy(a->direccion, direccion);
    strcpy(a->telefono, telefono);

    a->listaAviones = crearLista();

    return a;
}

char* getNombre(AeropuertoPtr a){
    return a->nombre;
}
char* getDireccion(AeropuertoPtr a){
    return a->direccion;
}
char* getTelefono(AeropuertoPtr a){
    return a->telefono;
}

void setNombre(AeropuertoPtr a, char* nombre){
    strcpy(a->nombre, nombre);
}
void setDireccion(AeropuertoPtr a, char* direccion){
    strcpy(a->direccion, direccion);
}
void setTelefono(AeropuertoPtr a, char* telefono){
    strcpy(a->telefono, telefono);
}


ListaPtr getListaAviones(AeropuertoPtr a){
    return a->listaAviones;}



void insertarAvion(AeropuertoPtr a, AvionPtr av){
    insertarUltimo(a->listaAviones, av);
}





void mostrarAeropuerto(AeropuertoPtr a){
    printf("\n---------AEROPUERTO---------\n");
    printf("\nNOMBRE: %s -- DIRECCION: %s -- TELEFONO: %s\n", a->nombre, a->direccion, a->telefono);

    mostrarListaGenerica(a->listaAviones, &mostrarAvionDatoPtr);

}

void liberarAeropuerto(AeropuertoPtr a){
    free(a);
}
