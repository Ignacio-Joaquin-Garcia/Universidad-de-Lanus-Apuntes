#ifndef AEROPUERTO_H_INCLUDED
#define AEROPUERTO_H_INCLUDED

#include "avion.h"

struct Aeropuerto;
typedef struct Aeropuerto * AeropuertoPtr;

AeropuertoPtr crearAeropuerto(char* nombre, char* direccion, char* telefono);

char* getNombre(AeropuertoPtr a);
char* getDireccion(AeropuertoPtr a);
char* getTelefono(AeropuertoPtr a);

void setNombre(AeropuertoPtr a, char* nombre);
void setDireccion(AeropuertoPtr a, char* direccion);
void setTelefono(AeropuertoPtr a, char* telefono);

void insertarAvion(AeropuertoPtr a, AvionPtr av);

void mostrarAeropuerto(AeropuertoPtr a);

void liberarAeropuerto(AeropuertoPtr a);

ListaPtr getListaAviones(AeropuertoPtr a);
#endif // AEROPUERTO_H_INCLUDED
