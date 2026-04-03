#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED

#include "Funciones.h"
///Carton
struct Carton{
    int valor;
    char fechaEmision[20];
    char fechaJuego[20];
    char direccionAgencia[50];
    int numeros[8];
    int cantidadAciertos;
};
typedef struct Carton * CartonPtr;

CartonPtr crearCartonVacio();
CartonPtr crearCartonParametros(int valor, char fechaEmision[20], char fechaJuego[20], char direccionAgencia[50]);
bool verificarNumeroIngresado(int numeros[], int i);
int pedirNumerosPorTeclado(int i);
void mostrarCarton(CartonPtr c);

#endif // CARTON_H_INCLUDED
