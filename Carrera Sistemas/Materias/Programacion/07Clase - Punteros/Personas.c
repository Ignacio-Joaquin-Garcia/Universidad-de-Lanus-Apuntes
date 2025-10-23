#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#include "Personas.h"

void cargarVehiculosVacios(PersonaPtr p){
    for(int i=0;i<5;i++){
        p->vehiculosEnPosesion[i] = cargarVehiculo("Vacio", -1, -1, -1);
    };
};
PersonaPtr cargarPersona(int dni, char nombre[50]){
    PersonaPtr p = malloc(sizeof(struct Persona));
    p->dni = dni;
    strcpy(p->nombre, nombre);
    cargarVehiculosVacios(p);
    return p;
};
PersonaPtr cargarPersonaPorTeclado(PersonaPtr e){
    int dni = scanfVerificado(1, "Ingrese el DNI de su Persona", "Por favor Ingrese un DNI mayor a 0!");
    char nombre[50];
    printf("\nIngrese el nombre de su Persona a ingresar: ");
    getchar();
    fgets(nombre, sizeof(nombre), stdin);

    e->dni = dni;
    strcpy(e->nombre, nombre);
    cargarVehiculosVacios(e);
    return e;
};
void mostrarPersona(PersonaPtr e){
    printf("\n\n--PERSONA--");
    printf("\n\tNombre: %s", e->nombre);
    printf("\tDNI: %d", e->dni);
    printf("\n\t-Vehiculos En Posesion-");
    for(int i = 0; i<5; i++){
        if(e->vehiculosEnPosesion[i]->patente != -1){
            mostrarVehiculo(e->vehiculosEnPosesion[i]);
        }
    }
};

PersonaPtr ordenarVehiculoPorPrecio(PersonaPtr e){
    VehiculoPtr aux;
    for(int i = 0; i<5 - 1;i++){
        for(int j = i+1; j<5;j++){
            if(e->vehiculosEnPosesion[i]->precio != -1){
                if(e->vehiculosEnPosesion[i]->precio < e->vehiculosEnPosesion[j]->precio){
                    aux = e->vehiculosEnPosesion[i];
                    e->vehiculosEnPosesion[i] = e->vehiculosEnPosesion[j];
                    e->vehiculosEnPosesion[j] = aux;
                }
            }
        }
    }
    return e;
};
