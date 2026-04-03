#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "Carton.h"

///Carton
bool verificarNumeroIngresado(int numeros[], int i){
    bool numValido = true;
    if(numeros[i] < 0 || numeros[i] > 99){
        printf("\nError al ingresar numero, Recuerdo valores entre 0 a 99\n");
        return false;
    }
    for(int j = 0; j<i; j++){
        if(numeros[j] == numeros[i]){
            printf("\nError al ingresar numero, Recuerdo NO ingresar numeros repetidos\n");
            return false;
        }
    };
    return numValido;
};
int pedirNumerosPorTeclado(int i){
    printf("\nIngresar el Numero %d del carton: ", i+1);
    int n;
    scanf("%d", &n);
    return n;
};
CartonPtr crearCartonParametros(int valor, char fechaEmision[20], char fechaJuego[20], char direccionAgencia[50]){
    CartonPtr c = malloc(sizeof(struct Carton));
    c->cantidadAciertos = -1;
    c->valor = valor;
    strcpy(c->fechaEmision, fechaEmision);
    strcpy(c->fechaJuego, fechaJuego);
    strcpy(c->direccionAgencia, direccionAgencia);

    //Validacion e Ingreso de Numeros en Carton
    for(int i = 0; i<8; i++){
        do{
            c->numeros[i] = pedirNumerosPorTeclado(i);
        } while(!verificarNumeroIngresado(c->numeros, i));
    }

    //Orden de Numeros
    ordenarShell(8, c->numeros);

    return c;
};
CartonPtr crearCartonVacio(){
    CartonPtr c = malloc(sizeof(struct Carton));
    c->cantidadAciertos = -1;
    c->valor = -1;
    strcpy(c->fechaEmision, "VACIO");
    strcpy(c->fechaJuego, "VACIO");
    strcpy(c->direccionAgencia, "VACIO");
    for(int i = 0; i < 8; i++){
        c->numeros[i] = -1;
    }
    return c;
}
void mostrarCarton(CartonPtr c){
    if(c->numeros[0] != -1){
        printf("\n\t\t---CARTON---");
        printf("\n\t\t\tAgencia Emision: %s", c->direccionAgencia);
        printf("\n\t\t\tFecha Emision: %s", c->fechaEmision);
        printf("\n\t\t\tFecha Juego: %s", c->fechaJuego);
        printf("\n\t\t\tValor Carton: $%d", c->valor);

        printf("\n\t\t\tNumeros Carton: [");
        for(int i = 0; i < 8; i++){

            if(i != 7){
                printf("%d, ", c->numeros[i]);
            } else{
                printf("%d]\n\n", c->numeros[i]);
            }
        };
    };
};



