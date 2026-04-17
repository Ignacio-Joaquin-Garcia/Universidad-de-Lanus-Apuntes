#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "vectores.h"
#include "matrices.h"
//TDA
struct Matriz{
    int ** m;
    int f;
    int c;
};
//Constructor
MatrizPtr crearMatriz(int f, int c){
    MatrizPtr m = malloc(sizeof(struct Matriz));
    m->f = f;
    m->c = c;
    m->m = (int **) malloc(f * sizeof(int *));
    for(int i = 0; i < f; i++){
        m->m[i] = (int *) malloc(c * sizeof(int));
    }

    return m;
};
//Destructor
void liberarMatriz(MatrizPtr m){
    for(int i = 0; i < m->f; i++){
        free(m->m[i]);
    }
    free(m->m);
    free(m);
};
//Dinamismo
MatrizPtr cambiarTamMatriz(MatrizPtr m, int fNuevo, int cNuevo){
    int matrizAux[m->f][m->c];
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            matrizAux[i][j] = m->m[i][j];
        }
    }
    MatrizPtr mNuevo = crearMatriz(fNuevo, cNuevo);
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            mNuevo->m[i][j] = matrizAux[i][j];
        }
    }
    liberarMatriz(m);
    return mNuevo;
};
//Carga
void cargarMatrizParametros(MatrizPtr m, int fCarga, int cCarga, int matrizCarga[fCarga][cCarga]){
    if(fCarga > m->f){
        m = cambiarTamMatriz(m, fCarga, m->c);
    }
    if(cCarga > m->c){
        m = cambiarTamMatriz(m, m->f, cCarga);
    }
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            m->m[i][j] = matrizCarga[i][j];
        }
    }
};
void cargarMatrizAleatoria(MatrizPtr m){
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            m->m[i][j] = generarNumAleatorio(0, 100);
        }
    }
};
//Muestreo
void mostrarMatriz(MatrizPtr m){
    printf("Matriz: \n[\n");
    for(int i = 0; i < m->f; i++){
        printf("f%d:\t[", i);
        for(int j = 0; j < m->c; j++){
            if(j != m->c-1){
                printf("%d, ", m->m[i][j]);
            } else{
                printf("%d", m->m[i][j]);
            }
        }
        printf("]\n");
    }
    printf("]\n");
};
//Estadisticas
int buscarMaximoMatriz(MatrizPtr m){
    int maximo = m->m[0][0];
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            if(maximo < m->m[i][j]){
                maximo =  m->m[i][j];
            }
        }
    }
    return maximo;
};
int buscarMinimoMatriz(MatrizPtr m){
    int minimo = m->m[0][0];
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            if(minimo > m->m[i][j]){
                minimo =  m->m[i][j];
            }
        }
    }
    return minimo;
};
int promedioMatriz(MatrizPtr m){
    int contador = 0;
    int suma = 0;

    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            contador++;
            suma+= m->m[i][j];
        }
    }

    int promedioNum = suma / contador;
    return promedioNum;
};
int sumaDeMatriz(MatrizPtr m){
    int suma = 0;
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            suma+= m->m[i][j];
        }
    }
    return suma;
};
long long productoDeMatriz(MatrizPtr m){
    long long producto = 1;
    for(int i = 0; i < m->f; i++){
        for(int j = 0; j < m->c; j++){
            producto = producto * m->m[i][j];
        }
    }
    return producto;
};

//Getters
int getColumnas(MatrizPtr m){
    return m->c;
};
int getFilas(MatrizPtr m){
    return m->f;
};
//Setter
bool setColumnas(MatrizPtr m, int columnas){
    m = cambiarTamMatriz(m, m->f, columnas);
    return true;
};
bool setFilas(MatrizPtr m, int filas){
    m = cambiarTamMatriz(m, filas, m->c);
    return true;
};
bool setMatriz(MatrizPtr m, int fMatriz, int cMatriz, int matriz[fMatriz][cMatriz]){
    cargarMatrizParametros(m, fMatriz, cMatriz, matriz);
    return true;
};
