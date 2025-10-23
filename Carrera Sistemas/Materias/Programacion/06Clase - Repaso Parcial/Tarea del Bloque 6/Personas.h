#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

#include "Vehiculo.h"

struct Persona{
    int dni;
    char nombre[50];

    struct Vehiculo vehiculosEnPosesion[5];
};


struct Vehiculo cargarVehiculoVacio(struct Persona p);
struct Persona cargarPersona(int dni, char nombre[50]);
struct Persona cargarPersonaPorTeclado(struct Persona e);
void mostrarPersona(struct Persona e);
struct Persona ordenarVehiculoPorPrecio(struct Persona e);



#endif // PERSONAS_H_INCLUDED
