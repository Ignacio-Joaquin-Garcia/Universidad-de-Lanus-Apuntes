#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "DispositivosTec.h"
struct DispositivosTec{
    char tipo[50];
    char marca[50];
    int precio;
    char memoria[50];
};

DispositivosTecPtr crearDispositivoTecParametros(char tipo[50], char marca[50], int precio, char memoria[50]){
    DispositivosTecPtr d = malloc(sizeof(struct DispositivosTec));

    strcpy(d->marca, marca);
    strcpy(d->tipo, tipo);
    strcpy(d->memoria, memoria);
    d->precio = precio;

    return d;
};
void mostrarDispositivoTec(DispositivosTecPtr d){
    printf("\t\t\t--Dispositivo Tecnologico--\n");
    printf("\t\t\t\tTipo: %s\n", d->tipo);
    printf("\t\t\t\tMarca: %s\n", d->marca);
    printf("\t\t\t\tPrecio: %d\n", d->precio);
    printf("\t\t\t\tMemoria: %s\n", d->memoria);
};




//Setters
bool setTipo(DispositivosTecPtr d, char tipo[50]){
    strcpy(d->tipo, tipo);
    return true;
};
bool setMarca(DispositivosTecPtr d, char marca[50]){
    strcpy(d->tipo, marca);
    return true;
};
bool setPrecio(DispositivosTecPtr d, int precio){
    if(precio > 0){
        d->precio = precio;
        return true;
    }
    return false;
};
bool setMemoria(DispositivosTecPtr d, char memoria[50]){
    strcpy(d->memoria, memoria);
    return true;
};
//Getters
int getPrecio(DispositivosTecPtr d){
    return d->precio;
};
char * getTipo(DispositivosTecPtr d){
    return d->tipo;
};
char * getMarca(DispositivosTecPtr d){
    return d->marca;
};
char * getMemoria(DispositivosTecPtr d){
    return d->memoria;
};

