#ifndef PERSONASENJUEGO_H_INCLUDED
#define PERSONASENJUEGO_H_INCLUDED

#include "Funciones.h"
#include "Persona.h"
///Personas en Juego
struct PersonasEnJuego{
    PersonaPtr * poseePersonas;
    int cantPersonas;
};
typedef struct PersonasEnJuego * PersonasEnJuegoPtr;

PersonaPtr * crearVectorPersonasEnJuego(int c);
void liberarVectorPersonarEnJuego(PersonasEnJuegoPtr p);
void cambiarVectorPersonasEnJuego(int c, PersonasEnJuegoPtr p);

PersonasEnJuegoPtr crearPersonasEnJuego(int cantPersonas);
void mostrarPersonasEnJuego(PersonasEnJuegoPtr pJ);

void jugar(int numGanadores[], bool informarNumeros);
void verificarCartones(PersonasEnJuegoPtr pJ, int numGanadores[]); //Se verifican los cartones de todas las personas, se les asigna la cantidadAciertos. Informar si gano y que gano
void informarAciertos(PersonasEnJuegoPtr pJ);

void promedioCartonPara8Aciertos();

unsigned int recompensasGanador(int cantidadAciertos);

#endif // PERSONASENJUEGO_H_INCLUDED
