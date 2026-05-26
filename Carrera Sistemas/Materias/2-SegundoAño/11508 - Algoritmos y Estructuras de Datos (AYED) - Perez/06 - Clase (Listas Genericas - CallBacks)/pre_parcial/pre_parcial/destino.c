#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"

struct Destino{
    char ciudad[20];
    float latitud;
    float longitud;
};


DestinoPtr crearDestino(char* ciudad, float latitud, float longitud){
    DestinoPtr d = (DestinoPtr) malloc(sizeof(struct Destino));

    strcpy(d->ciudad, ciudad);
    d->latitud = latitud;
    d->longitud = longitud;

    return d;
}

char* getCiudad(DestinoPtr d){
    return d->ciudad;
}
float getLatitud(DestinoPtr d){
    return d->latitud;
}
float getLongitud(DestinoPtr d){
    return d->longitud;
}

void setCiudad(DestinoPtr d, char* ciudad){
    strcpy(d->ciudad, ciudad);
}
void setLatitud(DestinoPtr d, float latitud){
    d->latitud = latitud;
}
void setLongitud(DestinoPtr d, float longitud){
    d->longitud = longitud;
}

void mostrarDestino(DestinoPtr d){
    printf("\n---------DESTINO---------\n");
    printf("\nCIUDAD: %s\n", d->ciudad);
    printf("\nLATITUD: %f\n", d->latitud);
    printf("\nLONGITUD: %f\n", d->longitud);
}

void liberarDestino(DestinoPtr d){
    free(d);
}


