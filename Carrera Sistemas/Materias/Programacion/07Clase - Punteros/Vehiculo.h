#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

#include "Vehiculo.h"

struct Vehiculo{
    char color[50];
    int anio;
    int precio;
    int patente;
};
typedef struct Vehiculo * VehiculoPtr;

VehiculoPtr cargarVehiculo(char color[50], int anio, int precio, int patente);
void cargarVehiculoPorTeclado(VehiculoPtr e);
void mostrarVehiculo(VehiculoPtr e);
void analisisPatente(VehiculoPtr b);

#endif // VEHICULO_H_INCLUDED
