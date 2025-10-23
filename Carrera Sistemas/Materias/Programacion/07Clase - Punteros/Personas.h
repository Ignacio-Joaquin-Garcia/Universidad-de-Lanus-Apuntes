#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

#include "Vehiculo.h"

struct Persona{
    int dni;
    char nombre[50];

    VehiculoPtr vehiculosEnPosesion[5];
};
typedef struct Persona * PersonaPtr;

VehiculoPtr cargarVehiculoVacio(PersonaPtr p);
PersonaPtr cargarPersona(int dni, char nombre[50]);
PersonaPtr cargarPersonaPorTeclado(PersonaPtr e);
void mostrarPersona(PersonaPtr e);
PersonaPtr ordenarVehiculoPorPrecio(PersonaPtr e);



#endif // PERSONAS_H_INCLUDED
