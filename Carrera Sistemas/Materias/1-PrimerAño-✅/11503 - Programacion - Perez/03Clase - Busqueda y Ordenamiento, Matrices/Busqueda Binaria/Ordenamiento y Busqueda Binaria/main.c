#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scanearValor(int mayorAEsteValor, char textoValorIngresar[150], char textoAyuda[150]);
int generarAleatorio(int min, int max);
void cargarMatriz(int filas, int columnas, int matriz[filas][columnas], int min, int max);
void printMatriz(int filas, int columnas, int matriz[filas][columnas]);
void ordenarMatrizPorFila(int filas, int columnas, int matriz[filas][columnas]);
int busquedaLineal(int filas, int columnas, int matriz[filas][columnas], int datoBuscar);
int busquedaBinaria(int filas, int columnas, int matriz[filas][columnas], int datoBuscar);
int main()
{
    ///INICIALIZACION
    srand(time(0));
    int filas = 4;
    int columnas = 12;
    int matriz[filas][columnas];

    int minValor = scanearValor(-1, "Ingrese el valor Minimo a generar Aleatoriamente en la matriz", "Por favor ingrese un valor mayor a 0");
    int maxValor = scanearValor(minValor, "Ingrese el valor Maximo a generar Aleatoriamente en la matriz", "Por favor ingrese un valor mayor al anterior");
    cargarMatriz(filas, columnas, matriz, minValor, maxValor);
    printMatriz(filas, columnas, matriz);

    ordenarMatrizPorFila(filas, columnas, matriz);
    printMatriz(filas, columnas, matriz);

    /*
    int auxPrueba = generarAleatorio(0, 100);
    printf("Prueba: %d", auxPrueba);
    */



    return 0;
}

int scanearValor(int mayorAEsteValor, char textoValorIngresar[150], char textoAyuda[150]){
    printf("\n%s: ", textoValorIngresar);
    int userInput;
    scanf("%d", &userInput);
    while(!(userInput > mayorAEsteValor)){
        printf("\n\t%s: ", textoAyuda);
        scanf("%d", &userInput);
    }
    return userInput;
};
int generarAleatorio(int min, int max){
    int numAleatorio = min + rand() % (max+1-min);
    return numAleatorio;
};
void cargarMatriz(int filas, int columnas, int matriz[filas][columnas], int min, int max){
    for(int f = 0; f<filas; f++){
        for( int c = 0; c<columnas; c++){
            matriz[f][c] = generarAleatorio(min, max);
        }
    }
};
void printMatriz(int filas, int columnas, int matriz[filas][columnas]){
    printf("\nMatriz: \n[\n\t");
    for(int f = 0; f<filas; f++){

        for( int c = 0; c<columnas; c++){
            if(c!=columnas-1){
                printf("%d, ", matriz[f][c]);
            } else{
                if(f!=filas-1){
                    printf("%d\n\t", matriz[f][c]);
                } else{
                    printf("%d\n", matriz[f][c]);
                }
            }
        }
    }
    printf("]\n");
};
void ordenarMatrizPorFila(int filas, int columnas, int matriz[filas][columnas]){
    int aux;
    for(int f = 0; f<filas;f++){
        for(int i = 0; i<columnas-1; i++){
            for( int j = i+1; j<columnas; j++){
                if(matriz[f][j] < matriz[f][i]){
                    aux = matriz[f][j];
                    matriz[f][j] = matriz[f][i];
                    matriz[f][i] = aux;
                }
            }
        }
    }
};
int busquedaLineal(int filas, int columnas, int matriz[filas][columnas], int datoBuscar){
    return 0;
};
int busquedaBinaria(int filas, int columnas, int matriz[filas][columnas], int datoBuscar){
    return 0;
};
