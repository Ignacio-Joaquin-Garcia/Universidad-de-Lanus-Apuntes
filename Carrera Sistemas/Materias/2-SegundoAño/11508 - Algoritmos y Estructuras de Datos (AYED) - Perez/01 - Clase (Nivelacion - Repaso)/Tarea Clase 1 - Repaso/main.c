#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <time.h>

#include "Funciones.h"
#include "Carton.h"
#include "Persona.h"
#include "PersonasEnJuego.h"

int valorCarton = 70;
int numGanadores[20];

int main()
{
    //Inicializacion de Librerias Externas
    srand(time(0));
    char fechaHoy[70];
    obtenerFechaHoy(fechaHoy, sizeof(fechaHoy));
    printf("Fecha Hoy: %s", fechaHoy);
    //Lectura Cartones Anteriores
    leerCartonesGuardados("cartones.txt");

    //Se ingresa numeros carton e informa cantidad de veces que un mismo carton tuvo que jugar para lograr 8 aciertos
    promedioCartonPara8Aciertos();

    //Creacion Puntero a Puntero de Structs para almacena de personas
    int cantPersonasEnJuego = 1;
    PersonasEnJuegoPtr listaJuego1 = crearPersonasEnJuego(cantPersonasEnJuego);

    //Se cargan las Personas | Tener en cuenta las fechas! si la fecha ya paso el carton NO se compra
    //P1
    cargarPersonaParametros("Igna", 11000111, listaJuego1->poseePersonas[0]);
    comprarCarton(listaJuego1->poseePersonas[0], valorCarton, fechaHoy, "31-05-2026", "libertad 1138");
    //P2 - En este caso ademas se cambia la cantidad de personas que tiene el juego restructurando el vector
    cantPersonasEnJuego = 2;
    cambiarVectorPersonasEnJuego(cantPersonasEnJuego, listaJuego1);
    cargarPersonaParametros("Pepe", 22000222, listaJuego1->poseePersonas[1]);
    comprarCarton(listaJuego1->poseePersonas[1], valorCarton, fechaHoy, "04-04-2026", "libertad 1138");

    //Se muestra las Personas que jugaran, Salen los Numeros, Se verifica Ganadores
    mostrarPersonasEnJuego(listaJuego1);
    jugar(numGanadores, true);
    verificarCartones(listaJuego1, numGanadores);

    //Se informa de los aciertos de las personas en Juego
    informarAciertos(listaJuego1);
    //Se muestra que se va a guardar y se Guarda
    mostrarCartonConAciertos(stdout, listaJuego1->poseePersonas[0], numGanadores);
    mostrarCartonConAciertos(stdout, listaJuego1->poseePersonas[1], numGanadores);
    guardarCartonConAciertos(listaJuego1->poseePersonas[0], numGanadores, "cartones.txt");
    guardarCartonConAciertos(listaJuego1->poseePersonas[1], numGanadores, "cartones.txt");
    return 0;
}
