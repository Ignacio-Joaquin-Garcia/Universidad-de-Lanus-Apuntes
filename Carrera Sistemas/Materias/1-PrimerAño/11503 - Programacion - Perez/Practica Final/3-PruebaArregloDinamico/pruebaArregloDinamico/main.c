#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * crearVector(int t);
void liberarVector(int * vector);
void mostrarVector(int * vector, int t);
int * cambiarTamanoVector(int * vector, int t, int nuevoTam);

void cambiarNumero(int * numero);

int main()
{
    int t = 3;
    int * vector = crearVector(t);
    vector[0] = 8;
    vector[1] = 999999999;
    vector[2] = 18;
    mostrarVector(vector, t);
    vector = cambiarTamanoVector(vector, t, 2);
    t = 5;
    vector[3] = 1;
    vector[4] = 20;
    mostrarVector(vector, t);

    int num = 5;
    int * numero = &num;
    printf("\n\n\nnum: %d", *numero);
    cambiarNumero(numero);
    cambiarNumero(numero);
    cambiarNumero(numero);
    cambiarNumero(numero);
    printf("\n\n\nnum: %d", *numero);

    return 0;
}


int * crearVector(int t){
    int * vector = (int *) malloc(t * sizeof(vector));
    return vector;
};
void liberarVector(int * vector){
    free(vector);
};
void mostrarVector(int * vector, int t){
    printf("\n----Vector----");
    for(int i = 0; i<t; i++){
        printf("\nElemento %d: %d", i, vector[i]);
    }
};
int * cambiarTamanoVector(int * vector, int t, int nuevoTam){
    if(t > nuevoTam){
        printf("\n\n\tEl nuevo tamano debe ser mayor al actual");
        printf("\n\tAccion no ejecutada\n");
        return vector;
    }
    int * nuevoVector = crearVector(nuevoTam);
    for(int i = 0; i<t;i++){
        nuevoVector[i] = vector[i];
    }
    free(vector);
    return nuevoVector;
};
void cambiarNumero(int * numero){
    *numero = *numero * 2;
};
