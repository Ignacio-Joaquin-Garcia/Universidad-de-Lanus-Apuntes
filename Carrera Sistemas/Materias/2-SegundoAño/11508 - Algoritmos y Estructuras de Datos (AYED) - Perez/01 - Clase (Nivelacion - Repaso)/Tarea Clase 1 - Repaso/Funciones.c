#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "Funciones.h"

///Utiles
int generarAleatorio(int min, int max){
    int a = min + rand() % (1+max-min);
    return a;
};

void ordenarShell(int t, int numeros[]){
    int m = t / 2;
    while(m > 0){
        bool cambio = true;
        while(cambio){
            cambio = false;
            for(int i = 0; i + m < t; i++){
                if(numeros[i] > (numeros[i + m])){
                    int aux = numeros[i];
                    numeros[i] = numeros[i + m];
                    numeros[i + m] = aux;
                    cambio = true;
                }
            }
        }
        m = m / 2;
    }
};
bool busquedaBinaria(int t, int valorBuscado, int arrayComparar[]){
    //Busqueda Binaria
    int m = t / 2;
    int izq = 0;
    int der = t-1;
    bool numEncontrado = false;
    while (izq <= der && !numEncontrado){
        if(arrayComparar[m] == valorBuscado){
            return true;
        } else{
            if(arrayComparar[m] > valorBuscado){
                der = m-1;
            } else{
                izq = m+1;
            }
        }
        m = (izq + der) / 2;
    };
    return numEncontrado;

};
void obtenerFechaHoy(char * fechaHoy, int tam){
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char * formato = "%d-%m-%Y";
    int bytesEscritos = strftime( fechaHoy, tam, formato, &tiempoLocal);
    if (bytesEscritos == 0) {
         printf("Error formateando fecha");
    };
};
