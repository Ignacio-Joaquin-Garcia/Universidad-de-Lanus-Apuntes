#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#include "Vehiculo.h"
#include "Personas.h"
#include "ListaPersonas.h"


int main()
{
    ///DEFINICION E INICIALIZACION
    ListaPersonasPtr totalPersonas;
    VehiculoPtr vBuscado;

    printf("\nCuantas Personas quiere añadir en total? (Maximo 100): ");
    int cantPersonas;
    scanf("%d", &cantPersonas);

    //Carga Inicial Personas por teclado
    totalPersonas = cargarPersonas(cantPersonas);
    mostrarPersonas(totalPersonas, cantPersonas);


    ///PROCESO E SALIDA
    //Ordenamos Vehiculos Por cada Persona
    printf("\n\n\n---Personas con vehiculos Ordenados por precio---");
    totalPersonas = ordernarVehiculoPorPrecio(totalPersonas, cantPersonas);
    mostrarPersonas(totalPersonas, cantPersonas);

    //Busqueda por patente
    printf("\n\n");
    int patenteBuscar = scanfVerificado(-2,"Ingrese pantente de vehiculo a buscar o -1 si no quiere buscar patentes", "Ingrese -1 si no quiere buscar patente");
    vBuscado = buscarPatentes(totalPersonas, patenteBuscar);
    analisisPatente(vBuscado);

    return 0;
}
