///------ARCHIVO FUNCIONES.C------
#include "funciones.h"

int generarAleatorio(int min, int max){
    int aleatorio = min + rand() % (max+1-min);
    return aleatorio;
};
void generarArreglo(int tam, int vector[]){

    for(int i = 0; i<tam;i++){
        vector[i] = generarAleatorio(1, 100);
    }
};
void mostrarArreglo(int tam, int vector[], char nombreVector[10]){
    printf("\nVector %s: [", nombreVector);
    for(int i = 0; i<tam;i++){
        printf("%d, ", vector[i]);
    }
    printf("]\n");
};

int eliminarDuplicadosVector(int tam, int vectorCopiar[], int nuevoVector[]){
    int vectorNumDuplicados[tam];

        //Se analiza y ponen los numeros repetidos en nuevo vector
    for(int i = 0;i<tam;i++){
        for(int j =0; j<tam;j++){
            if(i!=j){
                if(vectorCopiar[i] == vectorCopiar[j]){
                    vectorNumDuplicados[i] = vectorCopiar[i];
                }
            }
        }
    }

        //Si el numero en vector esta repetido se lo reemplaza por -1
    int numRepetido;
    for(int i = 0;i<tam;i++){
        numRepetido = 0;
        for(int j = 0;j<tam;j++){
            if(vectorCopiar[i] == vectorNumDuplicados[j]){
                numRepetido = 1;
            }
        }
        if(numRepetido == 0){
            nuevoVector[i] = vectorCopiar[i];
        } else{
            nuevoVector[i] = -1;
        }
    }

        //Recarga el vector nuevo sin los num Duplicados con nuevo indice
    int contador = 0;
    for(int i = 0;i<tam;i++){
        if(nuevoVector[i] != -1){
            nuevoVector[contador] = nuevoVector[i];
        } else{
            contador = contador - 1;
        }
        contador = contador + 1;
    }

    return contador;
};
void ordenarArreglo(int tam, int vector[]){
    int aux;
    for(int i=0;i<tam;i++){
        for(int j = i+1; j<tam;j++){
            if(vector[i]>vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
};
void busquedaBinaria(int tam, int vector[], int numBuscado){
    int numEncontrado = 0;
    int izquierda = 0;
    int derecha = tam-1;
    int medio;
    int valor;

    while((numEncontrado == 0) && (izquierda <= derecha)){
        medio = floor((izquierda+derecha) / 2);
        valor = vector[medio];

        if(valor == numBuscado){
            printf("Valor Encontrado en la posicion: %d\n", medio+1);
            numEncontrado = 1;
        } else{
            if(numBuscado < vector[medio]){
                derecha = medio - 1;
            } else{
                izquierda = medio + 1;
            }
        }
    }
    if(numEncontrado == 0){
        printf("Numero NO encontrado en el vector B\n");
    }
};
void concatenarVectores(int tam1, int vector1[], int tam2, int vector2[], int vectorConcatenado[]){
    for(int i=0; i<tam1; i++){
        vectorConcatenado[i] = vector1[i];
    }
    for(int j=0; j<tam2; j++){
        vectorConcatenado[tam1 + j] = vector2[j];
    }
};

