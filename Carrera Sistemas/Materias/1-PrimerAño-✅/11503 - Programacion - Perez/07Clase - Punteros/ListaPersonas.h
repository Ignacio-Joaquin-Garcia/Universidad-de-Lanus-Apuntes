#ifndef LISTAPERSONAS_H_INCLUDED
#define LISTAPERSONAS_H_INCLUDED

#include "Personas.h"

struct ListaPersonas{
    PersonaPtr arrayPersonas[100];
};
typedef struct ListaPersonas * ListaPersonasPtr;

void cargarPersonasVacias(ListaPersonasPtr e);
VehiculoPtr buscarPatentes(ListaPersonasPtr e, int patenteBuscar);
ListaPersonasPtr cargarPersonas(int cantPersonas);
void mostrarPersonas(ListaPersonasPtr e, int cantPersonas);
ListaPersonasPtr ordernarVehiculoPorPrecio(ListaPersonasPtr e, int cantPersonas);
#endif // LISTAPERSONAS_H_INCLUDED
