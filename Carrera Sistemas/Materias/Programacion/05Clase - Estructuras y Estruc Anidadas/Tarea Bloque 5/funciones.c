#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "funciones.h"

int generarAleatorio(int min, int max){
    int aleatorio = min + rand() % (max+1-min);
    return aleatorio;
};
void crearAnimalesAleatorios(struct Animales arrayAnimales[], int t){
    //Db Data
    char nombresAnimalesAleatoriosPosibles[5][25];
    char descripcionAnimalesAleatoriosPosibles[5][200];
    strcpy(nombresAnimalesAleatoriosPosibles[0], "Elefante");
    strcpy(descripcionAnimalesAleatoriosPosibles[0], "Los elefantes o elefantidos son una familia de mamiferos placentarios del orden proboscideos");
    strcpy(nombresAnimalesAleatoriosPosibles[1], "Burro");
    strcpy(descripcionAnimalesAleatoriosPosibles[1], "El burro, asno, jumento, borrico o pollino (Equus africanus asinus) es un animal domestico de la familia de los equidos.");
    strcpy(nombresAnimalesAleatoriosPosibles[2], "Gato");
    strcpy(descripcionAnimalesAleatoriosPosibles[2], "Los elefantes o elefantidos son una familia de mamiferos placentarios del orden proboscideos");
    strcpy(nombresAnimalesAleatoriosPosibles[3], "Puma");
    strcpy(descripcionAnimalesAleatoriosPosibles[3], "El puma, leon de montana o leon americano (Puma concolor) es un mamifero carnivoro de la familia Felidae nativo de America");
    strcpy(nombresAnimalesAleatoriosPosibles[4], "Perro");
    strcpy(descripcionAnimalesAleatoriosPosibles[4], "El perro (Canis familiaris o Canis lupus familiaris, dependiendo de si se lo considera una especie o una subespecie del lobo), llamado perro domestico");


    int nAleatorio;
    for(int i = 0; i<t;i++){
        nAleatorio = generarAleatorio(0,4);
        int peso = (float) generarAleatorio(0,160) + (float)(generarAleatorio(0, 99) / 100);
        struct Animales e = crearAnimalManual(nombresAnimalesAleatoriosPosibles[nAleatorio], descripcionAnimalesAleatoriosPosibles[nAleatorio], generarAleatorio(0, 120), peso);
        arrayAnimales[i] = e;
    };
};
struct Animales crearAnimalPorTeclado(){
    struct Animales e;
    printf("\nIngrese el nombre del Animal: ");
    fflush(stdin);
    gets(e.nombreAnimal);

    printf("\nIngrese la descripcion del Animal: ");
    fflush(stdin);
    gets(e.descripcionAnimal);

    printf("\nIngrese la edad del animal en anios: ");
    scanf("%d", &e.edad);

    printf("\nIngrese el peso del animal (ej: 88.97): ");
    scanf("%f", &e.peso);

    return e;
};
int validarNum(char texto[150]){
    int num;
    printf("%s", texto);
    scanf("%d", &num);
    while(num<0){
        printf("\nPor favor ingrese un numero mayor a 0: ");
        scanf("%d", &num);
    }
    return num;
};
struct Animales crearAnimalManual(char animal[25], char descripcion[100], int edad, float peso){
    struct Animales e;
    strcpy(e.nombreAnimal, animal);
    strcpy(e.descripcionAnimal, descripcion);
    e.edad = edad;
    e.peso = peso;
    return e;
};
void mostrarAnimal(struct Animales e){
    printf("\n\n------ANIMAL------");
    printf("\n\tnombre: %s", e.nombreAnimal);
    printf("\n\tdescripcion: %s", e.descripcionAnimal);
    printf("\n\tedad: %d", e.edad);
    printf("\n\tpeso: %.2f", e.peso);
    printf("\n\n");
};
void mostrarAnimales(struct Animales e[], int t){
    for(int i = 0; i<t;i++){
        printf("\n\n------ANIMAL------");
        printf("\n\tnombre: %s", e[i].nombreAnimal);
        printf("\n\tdescripcion: %s", e[i].descripcionAnimal);
        printf("\n\tedad: %d", e[i].edad);
        printf("\n\tpeso: %.2f", e[i].peso);
        printf("\n\n");
    }
};
void ordenarPorPeso(struct Animales a[], int tam){
    struct Animales aux;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (a[j].peso > a[j + 1].peso) {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
};
