#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "aeropuerto.h"
#include "avion.h"
#include "pasajero.h"
#include "destino.h"

int main(){

    printf("\n-----------EJEMPLO PRE PARCIAL --------------\n\n");

    ///Aeropuerto ---< Aviones ----< Pasajeros
                            ///----< Destinos

    PasajeroPtr p1 = crearPasajero("Apellido1", 1, 'S');
    PasajeroPtr p2 = crearPasajero("Apellido2", 2, 'S');
    PasajeroPtr p3 = crearPasajero("Apellido3", 3, 'N');
    PasajeroPtr p4 = crearPasajero("Apellido4", 4, 'S');
    PasajeroPtr p5 = crearPasajero("Apellido5", 5, 'N');
    PasajeroPtr p6 = crearPasajero("Apellido6", 6, 'S');

    AvionPtr avion1 = crearAvion("Boeing 737", 1111, 10);
    AvionPtr avion2 = crearAvion("Airbus A320", 2222, 5);
    AvionPtr avion3 = crearAvion("Embraer E190", 3333, 5);


    AeropuertoPtr aeropuerto = crearAeropuerto("Ministro Pistarini", "Riccheri 33", "11-5480-61111");


    insertarAvion(aeropuerto, avion1);
    insertarAvion(aeropuerto, avion2);
    insertarAvion(aeropuerto, avion3);


    printf("\n\n------ Aeropuerto SIN  pasajeros ----\n\n");
    mostrarAeropuerto(aeropuerto);


    agregarPasajero(avion1, p1);
    agregarPasajero(avion1, p2);
    agregarPasajero(avion1, p3);
    agregarPasajero(avion2, p4);
    agregarPasajero(avion2, p5);
    agregarPasajero(avion3, p6);

    printf("\n\n------ Aeropuerto ya con pasajeros ----\n\n");
    mostrarAeropuerto(aeropuerto);

    ///Ordenar pasajes
    ///Eliminar pasajeros
    ///Buscar pasajeros... AVIONES...

    ///Destinos!!!!

    ///Calcular distancia de destinos
    ///Ordenar por distancia...





    return 0;
}

