#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

#include "Vehiculo.h"

struct Vehiculo{
    char color[50];
    int anio;
    int precio;
    int patente;
};

struct Vehiculo cargarVehiculo(char color[50], int anio, int precio, int patente);
struct Vehiculo cargarVehiculoPorTeclado(struct Vehiculo e);
void mostrarVehiculo(struct Vehiculo e);
void analisisPatente(struct Vehiculo b);

#endif // VEHICULO_H_INCLUDED
