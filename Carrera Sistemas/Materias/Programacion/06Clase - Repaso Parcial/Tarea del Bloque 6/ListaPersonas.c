#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaPersonas.h"

struct ListaPersonas cargarPersonasVacias(struct ListaPersonas e){
    for(int i = 0; i<100;i++){
        e.arrayPersonas[i] = cargarPersona(-1, "Vacio");
    }
    return e;
};
struct Vehiculo buscarPatentes(struct ListaPersonas e, int patenteBuscar){
    struct Vehiculo b;
    b = cargarVehiculo("No Encontrado", -1, -1, -1);
    for(int i = 0;i<100;i++){
        if(e.arrayPersonas[i].dni != -1){
            for(int j=0; j<5;j++){
                if(e.arrayPersonas[i].vehiculosEnPosesion[j].patente != -1){
                    if(e.arrayPersonas[i].vehiculosEnPosesion[j].patente == patenteBuscar){
                        b = e.arrayPersonas[i].vehiculosEnPosesion[j];
                    }
                }
            }
        }
    }
    return b;
};
struct ListaPersonas cargarPersonas(struct ListaPersonas e, int cantPersonas){
    //Cargamos todas las personas como vacias
    e = cargarPersonasVacias(e);
    for(int i = 0; i<cantPersonas; i++){
        e.arrayPersonas[i] = cargarPersonaPorTeclado(e.arrayPersonas[i]);

        //Añadimos Vehiculos Iniciales de la persona
        int pararIngreso;
        printf("\nDesea Añadir un Vehiculo a esta Persona (1:si/0:no): ");
        scanf("%d", &pararIngreso);
        while(!(pararIngreso == 0 || pararIngreso == 1)){
            printf("\n\tIngrese un valor correcto (1:si/0:no): ");
            scanf("%d", &pararIngreso);
        }

        int j = 0;
        while((j<5) && pararIngreso){
            e.arrayPersonas[i].vehiculosEnPosesion[j] = cargarVehiculoPorTeclado(e.arrayPersonas[i].vehiculosEnPosesion[j]);

            printf("Desea Añadir otro Vehiculo a esta Persona (1:si/0:no)?");
            scanf("%d", &pararIngreso);
            while(!(pararIngreso == 0 || pararIngreso == 1)){
                printf("Ingrese un valor correcto (1:si/0:no)?");
                scanf("%d", &pararIngreso);
            }
            j++;
        }
    }
    return e;
};
void mostrarPersonas(struct ListaPersonas e, int cantPersonas){
    for(int i = 0; i<cantPersonas;i++){
        mostrarPersona(e.arrayPersonas[i]);
    }
};
struct ListaPersonas ordernarVehiculoPorPrecio(struct ListaPersonas e, int cantPersonas){
    for(int i = 0; i<cantPersonas;i++){
        e.arrayPersonas[i] = ordenarVehiculoPorPrecio(e.arrayPersonas[i]);
    }
    return e;
};
