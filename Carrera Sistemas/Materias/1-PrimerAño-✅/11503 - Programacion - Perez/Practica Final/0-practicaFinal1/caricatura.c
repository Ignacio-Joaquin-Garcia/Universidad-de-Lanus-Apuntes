#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caricatura.h"

///Caricatura
struct Caricatura crearCaricaturaParametros(char genero[100], char nombre[100], char paisOrigen[100]){
    struct Caricatura c;
    strcpy(c.genero, genero);
    strcpy(c.nombre, nombre);
    strcpy(c.paisOrigen, paisOrigen);
    for(int i = 0; i<10;i++){
        c.poseePersonajes[i] = crearPersonajeVacio();
    }
    return c;
};
void mostrarCaricatura(struct Caricatura c){
    printf("\n\t--CARICATURA--");
    printf("\n\t\tGenero: %s", c.genero);
    printf("\n\t\tNombre: %s", c.nombre);
    printf("\n\t\tPais de Origen: %s", c.paisOrigen);
    for(int i = 0; i<10;i++){
        if(c.poseePersonajes[i]->altura != -1){
            mostrarPersonaje(c.poseePersonajes[i]);
        }
    }
    printf("\n");
};
struct Caricatura crearCaricaturaVacia(){
    struct Caricatura caricaturaVacia = crearCaricaturaParametros("VACIO", "VACIO", "VACIO");;
    return caricaturaVacia;
};
struct Caricatura ordenarPorAltura(struct Caricatura c){
    int cantPersonajes = 10;
    PersonajePtr aux;
    int m = cantPersonajes / 2;
    while (m!=0){
        int cambio = 1;
        while(cambio){
            cambio = 0;
            int i = 0;
            while(i<cantPersonajes-m){
                if(c.poseePersonajes[i]->altura > c.poseePersonajes[i+m]->altura){
                    aux = c.poseePersonajes[i];
                    c.poseePersonajes[i] = c.poseePersonajes[i+m];
                    c.poseePersonajes[i+m] = aux;
                    cambio = 1;
                }
                i++;
            }
        }
        m=m/2;
    }
    return c;
};
struct Caricatura ordenarPorNombre(struct Caricatura c){

    int cantPersonajes = 10;
    PersonajePtr aux;
    int m = cantPersonajes / 2;
    while (m!=0){
        int cambio = 1;
        while(cambio){
            cambio = 0;
            int i = 0;
            while(i<cantPersonajes-m){
                if(strcmp(c.poseePersonajes[i]->nombre, c.poseePersonajes[i+m]->nombre) > 0){
                    aux = c.poseePersonajes[i];
                    c.poseePersonajes[i] = c.poseePersonajes[i+m];
                    c.poseePersonajes[i+m] = aux;
                    cambio = 1;
                }
                i++;
            }
        }
        m=m/2;
    }
    return c;
};
