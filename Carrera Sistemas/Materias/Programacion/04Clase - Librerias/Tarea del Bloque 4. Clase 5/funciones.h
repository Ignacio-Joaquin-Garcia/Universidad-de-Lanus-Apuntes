///------ARCHIVO FUNCIONES.H------
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int generarAleatorio(int min, int max);
void generarArreglo(int tam, int vector[]);
void mostrarArreglo(int tam, int vector[], char nombreVector[10]);
int eliminarDuplicadosVector(int tam, int vectorCopiar[], int nuevoVector[]);
void ordenarArreglo(int tam, int vector[]);
void busquedaBinaria(int tam, int vector[], int numBuscado);
void concatenarVectores(int tam1, int vector1[], int tam2, int vector2[], int vectorConcatenado[]);

#endif // FUNCIONES_H_INCLUDED
