#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "lista.h"
#include "pasajero.h"

struct Avion;
typedef struct Avion * AvionPtr;

AvionPtr crearAvion(char* tipo, int matricula, int capacidad);

char* getTipo(AvionPtr a);
int getMatricula(AvionPtr a);
ListaPtr getListaPasajeros(AvionPtr a);
int getCapacidad(AvionPtr a);

void setTipo(AvionPtr a, char* tipo);
void setMatricula(AvionPtr a, int matricula);
void setCapacidad(AvionPtr a, int capacidad);

int agregarPasajero(AvionPtr a, PasajeroPtr p);
void eliminarPasajerosVentanilla(AvionPtr a);

void mostrarAvion(AvionPtr a);
void mostrarAvionDatoPtr(void * a);

void liberarAvion(AvionPtr a);


#endif // AVION_H_INCLUDED
