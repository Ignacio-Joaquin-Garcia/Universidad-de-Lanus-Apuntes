#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "canalInfantil.h"
///CANAL
struct CanalInfantil crearCanalParametros(char nombre[100], char web[100], int anoCreacion){
    struct CanalInfantil canal;
    strcpy(canal.nombre, nombre);
    strcpy(canal.web, web);
    canal.anoCreacion = anoCreacion;
    for(int i = 0; i<100;i++){
        canal.poseeCaricaturas[i] = crearCaricaturaVacia();
    }
    return canal;
};
void mostrarCanalInfantil(struct CanalInfantil ci){
    printf("\n--CANAL--");
    printf("\n\tNombre: %s", ci.nombre);
    printf("\n\tWeb: %s", ci.web);
    printf("\n\tAno de Creacion: %d", ci.anoCreacion);
    for(int i = 0; i<100;i++){
        if(strcmp(ci.poseeCaricaturas[i].nombre, "VACIO")){
             mostrarCaricatura(ci.poseeCaricaturas[i]);
        }
    }
    printf("\n");
};
struct CanalInfantil eliminarPorAltura(int cantCaricaturas,int altura, struct CanalInfantil ci){
    for(int i = 0;i<cantCaricaturas;i++){
        for(int j=0;j<10;j++){
            if(ci.poseeCaricaturas[i].poseePersonajes[j]->altura < altura){
                ci.poseeCaricaturas[i].poseePersonajes[j] = crearPersonajeVacio();
            }
        }
    }
    return ci;
};
PersonajePtr busquedaBinaria(float alturaBuscada, int caricaturaBuscar, struct CanalInfantil ci){
    int medio;
    int izquierda = 0;
    int derecha = 10 - 1;
    int noEncontrada = 1;
    int indice = -1;
    while(izquierda <= derecha && noEncontrada){
        medio = floor((izquierda + derecha) / 2);
        if(ci.poseeCaricaturas[caricaturaBuscar].poseePersonajes[medio]->altura == alturaBuscada){
            noEncontrada = 0;
            indice = medio;
        } else{
            if(alturaBuscada < ci.poseeCaricaturas[caricaturaBuscar].poseePersonajes[medio]->altura){
                derecha = medio - 1;
            } else {
                izquierda = medio + 1;
            }
        }
    }
    PersonajePtr buscado = malloc(sizeof(struct Personaje));;
    if(!noEncontrada){
        buscado = ci.poseeCaricaturas[caricaturaBuscar].poseePersonajes[indice];
    } else {
        buscado = crearPersonajeVacio();
    };
    return buscado;
};
