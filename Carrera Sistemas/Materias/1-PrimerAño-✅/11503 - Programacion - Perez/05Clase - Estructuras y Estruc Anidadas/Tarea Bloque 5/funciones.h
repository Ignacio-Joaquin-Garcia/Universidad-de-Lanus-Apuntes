#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct Animales{
    char nombreAnimal[25];
    char descripcionAnimal[200];
    int edad;
    float peso;
};
//Consigna Inicial
struct Animales crearAnimalPorTeclado();
struct Animales crearAnimalManual(char animal[25], char descripcion[200], int edad, float peso);
void mostrarAnimal(struct Animales e);
//Consigna Arrays
void ordenarPorPeso(struct Animales a[], int tam);
//Mi idea
int generarAleatorio(int min, int max);
void crearAnimalesAleatorios(struct Animales arrayAnimales[], int t);
void mostrarAnimales(struct Animales e[], int t);
int validarNum(char texto[150]);

#endif // FUNCIONES_H_INCLUDED
