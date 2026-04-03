#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <time.h>

#include "Persona.h"

///Persona
PersonaPtr crearPersonaParametros(char nombre[50], unsigned int dni){
    PersonaPtr p = malloc(sizeof(struct Persona));
    strcpy(p->nombre, nombre);
    p->dni = dni;
    p->carton = crearCartonVacio();
    return p;
};
void cargarPersonaParametros(char nombre[50], int dni, PersonaPtr p){
    strcpy(p->nombre, nombre);
    p->dni = dni;
};
void mostrarPersona(PersonaPtr p){
    if(p->dni != 0){
        printf("\n---Persona---");
        printf("\n\tDNI: %u", p->dni);
        printf("\n\tNombre: %s", p->nombre);
        mostrarCarton(p->carton);
        printf("\n\n");
    }
};

void comprarCarton(PersonaPtr p, int valorCarton, char fechaEmision[20], char fechaJuego[20], char direccionAgencia[50]){
    printf("\nRecuerde que el valor del carton es de: $%d\n", valorCarton);
    if(valorCarton != -1){
        time_t ahora = time(NULL);
        struct tm * tmAhora = localtime(&ahora);
        tmAhora->tm_hour = 0;
        tmAhora->tm_min  = 0;
        tmAhora->tm_sec  = 0;
        time_t ahoraSinHora = mktime(tmAhora);

        int dia, mes, anio;
        sscanf(fechaJuego, "%d-%d-%d", &dia, &mes, &anio);
        struct tm tmFecha = {0};
        tmFecha.tm_mday  = dia;
        tmFecha.tm_mon   = mes - 1;
        tmFecha.tm_year  = anio - 1900;
        time_t tFecha = mktime(&tmFecha);

        double diferencia = difftime(tFecha, ahoraSinHora);
        if(diferencia > 0){
            printf("\nLa fecha de juego aun no llego");
        } else if(diferencia < 0){
            printf("\nLa fecha de juego ya paso, ERROR AL COMPRAR CARTON");
            return;
        } else{
            printf("\nEl Carton se JUEGA HOY!");
        }
    }

    p->carton = crearCartonParametros(valorCarton, fechaEmision, fechaJuego, direccionAgencia);
};



///Manejo de Archivos
void mostrarCartonConAciertos(FILE * salida, PersonaPtr p, int numGanadores[]){
    fprintf(salida, "---CARTON con Aciertos---\n");
    fprintf(salida, "\tPersona del Carton: %s, DNI: %d\n", p->nombre, p->dni);
    if(p->carton->cantidadAciertos != -1){
        fprintf(salida, "\tCantidad de Aciertos: %d\n", p->carton->cantidadAciertos);
        fprintf(salida, "\tNumeros: [");
        for(int i = 0; i < 8; i++){
            bool numEncontrado = busquedaBinaria(20, p->carton->numeros[i], numGanadores);
            if(numEncontrado){
                fprintf(salida, "#%d, ", p->carton->numeros[i]);
            } else{
                fprintf(salida, "%d, ", p->carton->numeros[i]);
            }
        };
        fprintf(salida, "]\n");
    } else{
        fprintf(salida, "\tEste Carton todavia no se jugo!!\n");
    }
    fprintf(salida, "\n"); //Debido al error de duplicacion de printeo del !feof()
}
void guardarCartonConAciertos(PersonaPtr p, int numGanadores[], char nombreArchivo[25]){
    FILE * archivo = fopen(nombreArchivo, "a");

    mostrarCartonConAciertos(archivo, p, numGanadores);

    fclose(archivo);
    printf("El carton se guardo con exito en archivo: %s\n", nombreArchivo);
}
void leerCartonesGuardados(char nombreArchivo[25]){
    printf("\nCARTONES GUARDADOS: \n");
    FILE * archivo = fopen(nombreArchivo, "r");

    if(archivo != NULL){
        while(!feof(archivo)){
            char linea[50];
            fgets(linea, 50, archivo);
            printf("%s", linea);
        }
    }

    fclose(archivo);
    printf("\n\n");
}


