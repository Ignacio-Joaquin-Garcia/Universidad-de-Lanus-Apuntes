
#include "Vehiculo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"

VehiculoPtr cargarVehiculo(char color[50], int anio, int precio, int patente){
    VehiculoPtr v = malloc(sizeof(struct Vehiculo));
    strcpy(v->color, color);
    v->anio = anio;
    v->precio = precio;
    v->patente = patente;
    return v;
};
void cargarVehiculoPorTeclado(VehiculoPtr v){
    printf("\n--Datos cargar vehiculo--");
    printf("\n\tColor del Vehiculo: ");
    getchar();
    fgets(v->color, sizeof(v->color), stdin);
    v->anio = scanfVerificado(-1, "\tIngrese el año del vehciulo", "Ingrese un año valido NO Negativo");
    v->precio = scanfVerificado(-1, "\tIngrese el precio del vehciulo", "Ingrese un precio valido NO Negativo");
    v->patente = scanfVerificado(-1, "\tIngrese la patente del vehciulo", "Ingrese una patente valido NO Negativo");
};

void mostrarVehiculo(VehiculoPtr v){
    printf("\n\t--VEHICULO--");
    printf("\n\t\tPatente: %d", v->patente);
    printf("\n\t\tColor: %s", v->color);
    printf("\n\t\tAnio: %d", v->anio);
    printf("\n\t\tPrecio: %d",v->precio);
    printf("\n");
};
void analisisPatente(VehiculoPtr b){
    if(b->patente == -1){
        printf("\nNO se encontro la patente");
    } else{
        printf("\nSe encontro la patente, el vehiculo encontrado es: ");
        mostrarVehiculo(b);
    }
};

