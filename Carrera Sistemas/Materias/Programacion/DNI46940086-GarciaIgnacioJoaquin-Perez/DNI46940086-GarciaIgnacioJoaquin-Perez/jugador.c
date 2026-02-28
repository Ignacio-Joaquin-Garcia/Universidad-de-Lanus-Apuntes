#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "titulos.h"
#include "jugador.h"
///FUNCIONES JUGADOR
TitulosPtr * crearVectorTitulos(int tTitulos){
    TitulosPtr * vector = malloc(tTitulos * sizeof(struct Titulos));
    for(int i = 0;i<tTitulos;i++){
        vector[i] = cargarTituloVacio(vector[i]);
    }
    return vector;
};
void liberarVector(TitulosPtr * vector){
    free(vector);
};
TitulosPtr * redimensionarVectorTitulosManteniendoDatos(TitulosPtr * vectorViejo, int tViejo, int tNuevo){
    TitulosPtr * vectorRedimensionado = crearVectorTitulos(tNuevo);
    for(int i = 0; i<tViejo; i++){
        vectorRedimensionado[i] = vectorViejo[i];
    };
    free(vectorViejo);
    for(int i = tViejo;i<tNuevo;i++){
        vectorRedimensionado[i] = cargarTituloVacio(vectorRedimensionado[i]);
    }
    return vectorRedimensionado;
}

JugadorPtr crearJugadorParametros(int idJugador, char nombreJugador[50], int tTitulos){
    JugadorPtr j = (JugadorPtr) malloc(sizeof(struct Jugador));
    j->idJugador = idJugador;
    strcpy(j->nombreJugador, nombreJugador);
    j->poseeTitulos = crearVectorTitulos(tTitulos);
    return j;
};
void mostrarJugador(JugadorPtr j, int tTitulos){
    printf("--Jugador--\n");
    printf("Id: %d\n", j->idJugador);
    printf("Nombre Jugador: %s\n", j->nombreJugador);
    for(int i = 0; i<tTitulos; i++){
        if(j->poseeTitulos[i]->idTitulo != -1){
            mostrarTitulo(j->poseeTitulos[i]);
        }
    }
};
void mostrarJugadorConVacios(JugadorPtr j, int tTitulos){
    printf("--Jugador--\n");
    printf("Id: %d\n", j->idJugador);
    printf("Nombre Jugador: %s\n", j->nombreJugador);
    for(int i = 0; i<tTitulos; i++){
        mostrarTitulo(j->poseeTitulos[i]);
    }
};
JugadorPtr ordenarPorTitulos(JugadorPtr jugador, int tTitulos){
    TitulosPtr auxTitulo;
    for(int i = 0; i<tTitulos-1; i++){
        for(int j = i+1; j<tTitulos;j++){
            if((jugador->poseeTitulos[i]->idTitulo) > (jugador->poseeTitulos[j]->idTitulo)){
                auxTitulo = jugador->poseeTitulos[i];
                jugador->poseeTitulos[i] = jugador->poseeTitulos[j];
                jugador->poseeTitulos[j] = auxTitulo;
            }
        }
    }

    return jugador;
};
