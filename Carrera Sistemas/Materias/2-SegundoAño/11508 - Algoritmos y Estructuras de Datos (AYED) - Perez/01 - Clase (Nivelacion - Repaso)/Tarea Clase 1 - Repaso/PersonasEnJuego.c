#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "PersonasEnJuego.h"

//Personas en Juego
PersonaPtr * crearVectorPersonasEnJuego(int c){
    PersonaPtr * pVector = malloc(c * sizeof(PersonaPtr));
    return pVector;
};
void liberarVectorPersonarEnJuego(PersonasEnJuegoPtr p){
    free(p);
};

void cambiarVectorPersonasEnJuego(int c, PersonasEnJuegoPtr p){
    //Copia vector antiguo a aux
    PersonaPtr * aux = malloc(p->cantPersonas * sizeof(PersonaPtr));
    for(int i = 0; i < p->cantPersonas; i++){
        aux[i] = p->poseePersonas[i];
    };
    //Declaramos la nueva memoria
    free(p->poseePersonas);
    p->poseePersonas = malloc(c * sizeof(PersonaPtr));
    //Recuperamos los datos
    for(int i = 0; i < p->cantPersonas; i++){
        p->poseePersonas[i] = aux[i];
    };
    for(int i = p->cantPersonas; i < c; i++){
        p->poseePersonas[i] = crearPersonaParametros("VACIO", 0);
    };
    //liberamos el aux utilizado y actualizamos cantPersonas
    free(aux);
    p->cantPersonas = c;
};

PersonasEnJuegoPtr crearPersonasEnJuego(int cantPersonas){
    PersonasEnJuegoPtr pJ = malloc(sizeof(struct PersonasEnJuego));

    pJ->cantPersonas = cantPersonas;
    pJ->poseePersonas = crearVectorPersonasEnJuego(pJ->cantPersonas);
    for(int i = 0; i < cantPersonas; i++){
        pJ->poseePersonas[i] = crearPersonaParametros("VACIO", 0);
    }

    return pJ;
};
void mostrarPersonasEnJuego(PersonasEnJuegoPtr pJ){
    for(int i = 0; i < pJ->cantPersonas; i++){
        mostrarPersona(pJ->poseePersonas[i]);
    }
};


void jugar(int numGanadores[], bool informarNumeros){
    if(informarNumeros){
        printf("\nPreparense, van a empezar a salir los numeros ganadores!");
    }
    int cantNumGanadores = 20;
    for(int i = 0; i < cantNumGanadores;i++){
        int numGanador = generarAleatorio(0, 99);
        numGanadores[i] = numGanador;
        if(informarNumeros){
            printf("\nNumero ganador N-%d: %d", i+1, numGanador);
        }

    }
    ordenarShell(20, numGanadores);
};
void verificarCartones(PersonasEnJuegoPtr pJ, int numGanadores[]){
    for(int i = 0; i < pJ->cantPersonas; i++){
        if(pJ->poseePersonas[i]->carton->numeros[0] != -1){
            pJ->poseePersonas[i]->carton->cantidadAciertos = 0;
            for(int j = 0; j < 8; j++){
                int numEncontrado = busquedaBinaria(20, pJ->poseePersonas[i]->carton->numeros[j], numGanadores);
                if(numEncontrado){
                    pJ->poseePersonas[i]->carton->cantidadAciertos++;
                }
            }
        }
    }
};

unsigned int recompensasGanador(int cantidadAciertos){
    int valorGanado;
    switch(cantidadAciertos){
        case 5:
            valorGanado = 50;
            break;
        case 6:
            valorGanado = 500;
            break;
        case 7:
            valorGanado = 20000;
            break;
        case 8:
            valorGanado = 11000000;
            break;
        default:
            valorGanado = 0;
            break;
    };
    return valorGanado;
};

void informarAciertos(PersonasEnJuegoPtr pJ){
    printf("\nInforme de Ganadores: ");
    for(int i = 0; i < pJ->cantPersonas; i++){
        if(pJ->poseePersonas[i]->carton->numeros[0] != -1){
            if(pJ->poseePersonas[i]->carton->cantidadAciertos >= 5){
                unsigned int valorGanado = recompensasGanador(pJ->poseePersonas[i]->carton->cantidadAciertos);
                printf("\n\t%s GANO $%u PESOS con %d ACIERTOS", pJ->poseePersonas[i]->nombre, valorGanado, pJ->poseePersonas[i]->carton->cantidadAciertos);
            } else{
                printf("\n\t%s PERDIO con %d ACIERTOS", pJ->poseePersonas[i]->nombre, pJ->poseePersonas[i]->carton->cantidadAciertos);
            }
        }
    }
    printf("\n\n");
};

///Promedio Bucle
void promedioCartonPara8Aciertos(){
    int numGanadores[20];
    int c = 1;
    PersonasEnJuegoPtr listaPersonasPromedio = crearPersonasEnJuego(c);
    cargarPersonaParametros("pruebaPromedio", 99999999, listaPersonasPromedio->poseePersonas[0]);
    printf("Ingresa los numeros de tu carton para ver las posibilidades de que consigas 8 Aciertos\n");
    comprarCarton(listaPersonasPromedio->poseePersonas[0], -1, "-1", "-1", "Prueba Promedio");
    printf("\nCalculando .");

    bool personaLogro8Aciertos = false;
    int cantidadNumGenerados = 0;
    while(!personaLogro8Aciertos){
        jugar(numGanadores, false);
        cantidadNumGenerados++;

        verificarCartones(listaPersonasPromedio, numGanadores);

        if(listaPersonasPromedio->poseePersonas[0]->carton->cantidadAciertos == 8){
            personaLogro8Aciertos = true;
        }
        if(cantidadNumGenerados % 10000 == 0){
            printf(".");
        }
    }

    free(listaPersonasPromedio);
    printf("\n\nLa cantidad de veces que tendrias que jugar con el mismo carton para acertar 8 Aciertos es de: %d", cantidadNumGenerados);
};
