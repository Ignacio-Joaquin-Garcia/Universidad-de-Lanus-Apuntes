#ifndef LISTAPERSONAS_H_INCLUDED
#define LISTAPERSONAS_H_INCLUDED

#include "Personas.h"

struct ListaPersonas{
    struct Persona arrayPersonas[100];
};

struct ListaPersonas cargarPersonasVacias(struct ListaPersonas e);
struct Vehiculo buscarPatentes(struct ListaPersonas e, int patenteBuscar);
struct ListaPersonas cargarPersonas(struct ListaPersonas e, int cantPersonas);
void mostrarPersonas(struct ListaPersonas e, int cantPersonas);
struct ListaPersonas ordernarVehiculoPorPrecio(struct ListaPersonas e, int cantPersonas);
#endif // LISTAPERSONAS_H_INCLUDED
