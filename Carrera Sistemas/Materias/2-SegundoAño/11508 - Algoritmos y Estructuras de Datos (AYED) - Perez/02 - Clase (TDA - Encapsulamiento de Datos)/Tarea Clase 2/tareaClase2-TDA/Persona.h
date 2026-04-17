#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "DispositivosTec.h"

struct Persona;
typedef struct Persona * PersonaPtr;

PersonaPtr crearPersonaParametros(char nombre[50], char apellido[50], int dni, int edad);
void mostrarPersona(PersonaPtr p);



//Setters
bool setNombre(PersonaPtr p, char nombre[50]);
bool setApellido(PersonaPtr p, char apellido[50]);
bool setDni(PersonaPtr p, int dni);
bool setEdad(PersonaPtr p, int edad);
bool setDispositivosTec(PersonaPtr p, DispositivosTecPtr d);
//Getters
char * getNombre(PersonaPtr p);
char * getApellido(PersonaPtr p);
int getDni(PersonaPtr p);
int getEdad(PersonaPtr p);
DispositivosTecPtr getDispositivoTec(PersonaPtr p, int posDispositivo);


#endif // PERSONA_H_INCLUDED
