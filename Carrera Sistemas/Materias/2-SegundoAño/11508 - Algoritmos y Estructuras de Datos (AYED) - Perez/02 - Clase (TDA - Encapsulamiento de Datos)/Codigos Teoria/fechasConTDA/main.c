#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"
int main()
{
    printf("--------------Ejemplo TDA fechas!!!!-----------\n");

    FechaPtr fechaHoy = crearFecha(11,4,2024);

    mostrarFecha(fechaHoy);
    return 0;
}
