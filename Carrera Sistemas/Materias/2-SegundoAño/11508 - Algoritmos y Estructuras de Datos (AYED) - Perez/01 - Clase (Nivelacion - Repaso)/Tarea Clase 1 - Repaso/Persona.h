#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "Funciones.h"
#include "Carton.h"
///Persona
struct Persona{
    char nombre[50];
    unsigned int dni;
    CartonPtr carton;
};
typedef struct Persona * PersonaPtr;

PersonaPtr crearPersonaParametros(char nombre[50], unsigned int dni);
void mostrarPersona(PersonaPtr p);
void cargarPersonaParametros(char nombre[50], int dni, PersonaPtr p);
void comprarCarton(PersonaPtr p, int valorCartonchar, char fechaEmision[20], char fechaJuego[20], char direccionAgencia[50]);

void mostrarCartonConAciertos(FILE * salida, PersonaPtr p, int numGanadores[]);
void guardarCartonConAciertos(PersonaPtr p, int numGanadores[], char nombreArchivo[25]);
void leerCartonesGuardados(char nombreArchivo[25]);

#endif // PERSONA_H_INCLUDED
