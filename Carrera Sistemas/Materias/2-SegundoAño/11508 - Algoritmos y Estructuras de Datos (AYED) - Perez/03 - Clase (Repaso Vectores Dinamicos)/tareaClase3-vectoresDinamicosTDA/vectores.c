#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "vectores.h"

//Override
struct Vector{
    int * datos;
    int tam;
};

//Constructor
VectorPtr crearVector(int tam){
    VectorPtr v = malloc(sizeof(struct Vector));
    v->datos = malloc(tam * sizeof(int));
    v->tam = tam;
    return v;
};
void cambiarTamVector(VectorPtr v, int nuevoTam){
    int vAux[v->tam];
    for(int i = 0; i < v->tam; i++){
        vAux[i] = v->datos[i];
    }
    free(v->datos);
    v->datos = malloc(nuevoTam * sizeof(int));
    for(int i = 0; i < v->tam; i++ ){
        v->datos[i] = vAux[i];
    }
    v->tam = nuevoTam;
}

//Destructor
void liberarVector(VectorPtr v){
    free(v->datos);
    free(v);
};

//Carga
void cargarVectorParametros(int vCarga[], int tamVectorCarga, VectorPtr v){
    if(tamVectorCarga > v->tam){
        cambiarTamVector(v, tamVectorCarga);
    }
    for(int i = 0; i<tamVectorCarga; i++){
        v->datos[i] = vCarga[i];
    }
};
void cargarVectorAleatorio(VectorPtr v, int minimo, int maximo){
    for(int i = 0; i<v->tam; i++){
        v->datos[i] = generarNumAleatorio(minimo, maximo);
    }
};
//Muestreo
void mostrarVector(VectorPtr v){
    printf("Vector: [");
    for(int i = 0; i < v->tam; i++){
        if(i != v->tam-1){
            printf("%d, ", v->datos[i]);
        } else{
            printf("%d]\n\n", v->datos[i]);
        }
    }
};
void mostrarVectorInvertido(VectorPtr v){
    printf("Vector Invertido: [");
    for(int i = v->tam-1; i >= 0; i--){
        if(i != 0){
            printf("%d, ", v->datos[i]);
        } else{
            printf("%d]\n\n", v->datos[i]);
        }
    }
};
//Orden y Busqueda
void ordenarVector(VectorPtr v){
    int m = v->tam / 2;

    while(m > 0){
        bool cambio = true;
        while(cambio){
            cambio = false;
            for(int i = 0; i < v->tam - m; i++){
                if(v->datos[i] > v->datos[i+m]){
                    int aux = v->datos[i];
                    v->datos[i] = v->datos[i+m];
                    v->datos[i+m] = aux;
                    cambio = true;
                }
            }
        }
        m = m / 2;
    }
};
int busquedaSecuencialVector(VectorPtr v, int numBuscado){
    int numEncontrado = -1;
    for(int i = 0; i < v->tam; i++){
        if(v->datos[i] == numBuscado){
            return i;
        }
    }
    return numEncontrado;
};
int busquedaBinariaVector(VectorPtr v, int numBuscado){
    ordenarVector(v);
    int numEncontrado = -1;

    int izquierda = 0;
    int derecha = v->tam - 1;
    while(izquierda <= derecha){
        int m = (izquierda + derecha) / 2;
        if(v->datos[m] == numBuscado){
            return m;
        } else{
            if(v->datos[m] < numBuscado){
                izquierda = m+1;
            } else{
                derecha = m-1;
            }
        }
    }
    return numEncontrado;
};

//Utiles
int contarParesEnVector(VectorPtr v){
    int cantPares;

    for(int i = 0; i < v->tam; i++){
        if(v->datos[i] % 2 == 0){
            cantPares++;
        }
    }

    return cantPares;
};
int calcularModuloVector(VectorPtr v){
    int moduloVector = 0;
    for(int i = 0; i < v->tam; i++){
        moduloVector = moduloVector + v->datos[i] * v->datos[i];
    }
    return sqrt(moduloVector);
};
int buscarMaximoVector(VectorPtr v){
    int maximo = 0;
    for(int i = 1; i < v->tam; i++){
        if(v->datos[i] > v->datos[maximo]){
            maximo = i;
        }
    }
    return v->datos[maximo];
};
int buscarMinimoVector(VectorPtr v){
    int minimo = 0;
    for(int i = 1; i < v->tam; i++){
        if(v->datos[i] < v->datos[minimo]){
            minimo = i;
        }
    }
    return v->datos[minimo];
};
int sumaDeVectores(VectorPtr v1, VectorPtr v2){
    int suma = 0;
    for(int i = 0; i < v1->tam; i++){
        suma = suma + v1->datos[i];
    }
    for(int i = 0; i < v2->tam; i++){
        suma = suma + v2->datos[i];
    }
    return suma;
};
void multiplicacionEscalarVector(VectorPtr v1, int escalar){
    for(int i = 0; i < v1->tam; i++){
        v1->datos[i] = v1->datos[i] * escalar;
    }
};

//Utiles
int generarNumAleatorio(int minimo, int maximo){
    int numAleatorio = minimo + rand() % (maximo+1-minimo);
    return numAleatorio;
};

//Getters
int getTam(VectorPtr v){
    return v->tam;
};
int * getVector(VectorPtr v){
    //Lo cree para que sea full TDA, pero enrealidad nunca se deberia modificar al vector diracmente sino mediante funciones
    return v->datos;
};
//Setters
bool setTam(VectorPtr v, int tam){
    if(v->tam < tam){
        cambiarTamVector(v, tam);
    }
    v->tam = tam;
    return true;
};
bool setVector(VectorPtr v, int vCarga[], int tamVCarga){
    if(v->tam < tamVCarga){
        cambiarTamVector(v, tamVCarga);
    }
    v->tam = tamVCarga;
    for(int i = 0; i < tamVCarga; i++){
        v->datos[i] = vCarga[i];
    }
    return true;
};
