#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Empleado.h"

int main()
{

    DispositivosTecPtr d1 = crearDispositivoTecParametros("Microcontrolador", "Arduino", 6000, "50kb");
    mostrarDispositivoTec(d1);
    DispositivosTecPtr d2 = crearDispositivoTecParametros("Microcontrolador", "ESP32", 12000, "5Mb");
    mostrarDispositivoTec(d2);

    PersonaPtr p1 = crearPersonaParametros("Pepe", "Garcia", 11000111, 45);
    setDispositivosTec(p1, d1);
    setDispositivosTec(p1, d2);
    mostrarPersona(p1);

    EmpleadoPtr e1 = crearEmpleadoParametros("Ramiro", "Henchoz", 22000222, 34, "NZ2rt", 10000, "Pepsi");
    mostrarEmpleado(e1);


    //Pruebas de Set y Get
    setNombre(getPersona(e1), "Matias");
    printf("\nNombre Nuevo: %s\n\n", getNombre(getPersona(e1)));
    setDni(getPersona(e1), 33000333);
    mostrarEmpleado(e1);

    printf("nombre: %s", getNombre(p1));


    return 0;
}
