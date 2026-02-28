#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int numAleatorio(int min, int max);

int * crearVector(int t);
void liberarVector(int * vector);
void cargarVectorRandom(int * vector, int t);
int cargarVectorTeclado(int * vector);
int cargarVectorArchivo(int * vector, char archivo[50]);
void mostrarVector(int * vector, int t);
int busquedaBinaria(int * vector, int t, int numeroBuscado);
void ordenarBurbuja(int * vector, int t);
void ordenarShell(int * vector, int t);

int main()
{
    srand(time(0));
    int * vector;
    int n = 20;
    vector = crearVector(n);

    n = cargarVectorArchivo(vector, "vector.txt");
    mostrarVector(vector, n);
    ordenarShell(vector, n);
    mostrarVector(vector, n);
    int indiceBuscado = busquedaBinaria(vector, n, 8888);
    printf("Numero buscado: %d encontrado en la posicion: %d", vector[indiceBuscado], indiceBuscado);

    return 0;
}
int numAleatorio(int min, int max){
    int aleatorio = min + rand() % (max+1-min);
    return aleatorio;
};

int * crearVector(int t){
    int * p = (int *) malloc(t * sizeof(int));
    return p;
};
void liberarVector(int * vector){
    free(vector);
};
void cargarVectorRandom(int * vector, int t){
    for(int i = 0; i<t;i++){
        vector[i] = numAleatorio(0, 10);
    }
};
int cargarVectorTeclado(int * vector){
    printf("\n--Carga de Vector por Teclado--");
    int num;
    int tam = 0;
    printf("\nIngrese numero a cargar en el vector: ");
    scanf("%d", &num);
    vector[tam] = num;
    tam++;
    int ingresarVector;
    printf("\nQuiere seguir anadiendo numeros al vector (1-Si / 0-No): ");
    scanf("%d", &ingresarVector);
    while(!(ingresarVector == 1 || ingresarVector == 0)){
        printf("\nIngresar un valor correcto! (1-Si / 0-No): ");
        scanf("%d", &ingresarVector);
    }
    while (ingresarVector){
        printf("\nIngrese numero a cargar en el vector: ");
        scanf("%d", &num);
        vector[tam] = num;
        tam++;
        printf("\nQuiere seguir anadiendo numeros al vector (1-Si / 0-No): ");
        scanf("%d", &ingresarVector);
        while(!(ingresarVector == 1 || ingresarVector == 0)){
            printf("\nIngresar un valor correcto! (1-Si / 0-No): ");
            scanf("%d", &ingresarVector);
        }
    }
    return tam;
};
int cargarVectorArchivo(int * vector, char archivo[50]){
    FILE * archivoCarga = fopen(archivo, "r");
    char texto[20];
    int i = 0;
    while(!feof(archivoCarga)){
        fgets(texto,20,archivoCarga);
        if(!strcmp(texto, "\n")){
            continue;
        }
        vector[i] = atoi(texto);
        i++;
    }
    fclose(archivoCarga);
    return i;
};

void mostrarVector(int * vector, int t){
    printf("\n--Vector--");
    for(int i = 0; i<t;i++){
        printf("\n%d: %d", i, vector[i]);
    }
    printf("\n{");
    for(int i = 0; i<t;i++){
        printf("%d, ", vector[i]);
    }
    printf("}\n\n");
};

int busquedaBinaria(int * vector, int t, int numeroBuscado){
    int indiceNumBuscado = -1;
    int medio;
    int izquierda = 0;
    int derecha = t-1;
    int numEncontrado = 0;
    while((!numEncontrado) && (izquierda<=derecha)){
        medio = floor((izquierda+derecha) / 2);
        if(vector[medio] == numeroBuscado){
            numEncontrado = 1;
            indiceNumBuscado = medio;
        } else{
            if(numeroBuscado < vector[medio]){
                derecha = medio-1;
            } else{
                izquierda = medio+1;
            }
        }
    }
    return indiceNumBuscado;
};
void ordenarBurbuja(int * vector, int t){
    int aux;
    for(int i = 0; i<t-1; i++){
        for(int j=i+1;j<t;j++){
            if(vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
};
void ordenarShell(int * vector, int t){
    int aux;
    int m = t/2;
    while(m !=0){
        int cambio = 1;
        while(cambio){
            cambio = 0;
            int i = 0;
            while(i < t-m){
                if(vector[i] > vector[i+m]){
                    aux=vector[i];
                    vector[i] = vector[i+m];
                    vector[i+m] = aux;
                }
                i++;
            }
        }
        m=m/2;
    }
};
