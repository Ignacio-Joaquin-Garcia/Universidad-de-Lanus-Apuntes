#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct Receta{
    int paso;
    char descripcion[100];
};
typedef struct Receta * RecetaPtr;

///FUNCIONES RECETA
RecetaPtr crearRecetaParametros(int paso, char descripcion[100]);
void mostrarReceta(RecetaPtr r);
RecetaPtr crearRecetaRandom();

struct Comida{
    char nombre[50];
    int identificador;
    RecetaPtr * arrayRecetas;
};
typedef struct Comida * ComidaPtr;

///FUNCIONES COMIDA
RecetaPtr * crearArrayRecetas(int t);
void mostrarArrayRecetas(RecetaPtr * r, int t);
void liberarArrayRecetas(RecetaPtr * r);
RecetaPtr * cambiarTamRecetasManteniendoDatos(RecetaPtr * r, int tamViejo, int nuevoTam);

ComidaPtr crearComidaParametros(char nombre[50], int identificador, int tRecetas);
void mostrarComida(ComidaPtr c, int t);
void ordenarRecetasComida(RecetaPtr * arrayRecetas, int t);
int busquedaBinariaReceta(RecetaPtr * arrayRecetas, int t, int pasoBuscado);

///FUNCIONES NORMALES
int generarRandom(int min, int max);

///FUNCIONES ARCHIVO
void crearArchivoConComidas(char nombreArchivo[30], ComidaPtr c, int tRecetas);
ComidaPtr obtenerDatoComidaArchivo(char nombreArchivo[30]);

int main()
{
    srand(time(0));
    int tamRecetas = 3;
    ComidaPtr comida1 = crearComidaParametros("Patys", 1, tamRecetas);


    comida1->arrayRecetas[0] = crearRecetaRandom();
    comida1->arrayRecetas[1] = crearRecetaRandom();
    comida1->arrayRecetas[2] = crearRecetaRandom();
    mostrarComida(comida1, tamRecetas);

    comida1->arrayRecetas = cambiarTamRecetasManteniendoDatos(comida1->arrayRecetas, tamRecetas, 10);
    tamRecetas = 10;
    for(int i = 0;i<10-3;i++){
       comida1->arrayRecetas[i+3] = crearRecetaRandom();
    }
    mostrarComida(comida1, tamRecetas);
    ordenarRecetasComida(comida1->arrayRecetas, tamRecetas);
    mostrarComida(comida1, tamRecetas);

    int pasoBuscado;
    printf("\nQue paso queres buscar?: ");
    scanf("%d", &pasoBuscado);
    printf("\nPaso Buscado: %d", pasoBuscado);
    int indiceEncontrado = busquedaBinariaReceta(comida1->arrayRecetas, tamRecetas, pasoBuscado);
    printf("\n\nIndice Encontrado: %d", indiceEncontrado);

    crearArchivoConComidas("comidas.txt", comida1, tamRecetas);

    return 0;
}

///FUNCIONES RECETA
RecetaPtr crearRecetaParametros(int paso, char descripcion[100]){
    RecetaPtr r = (RecetaPtr) malloc(sizeof(struct Receta));
    r->paso = paso;
    strcpy(r->descripcion, descripcion);
    return r;
};
void mostrarReceta(RecetaPtr r){
    printf("\n\t--Receta--");
    printf("\n\tPaso Receta: %d", r->paso);
    printf("\n\tDescripcion Receta: %s\n", r->descripcion);
};
RecetaPtr crearRecetaRandom(){
    RecetaPtr recetaRandom = (RecetaPtr) malloc(sizeof(struct Receta));
    recetaRandom->paso = generarRandom(0, 100);
    strcpy(recetaRandom->descripcion,"RANDOM");
    return recetaRandom;
};


///FUNCIONES COMIDA
RecetaPtr * crearArrayRecetas(int t){
    RecetaPtr * arrayReceta = (RecetaPtr *) malloc(t * sizeof(RecetaPtr));
    return arrayReceta;
};
void mostrarArrayRecetas(RecetaPtr * r, int t){
    for(int i = 0; i<t;i++){
        mostrarReceta(r[i]);
    }
};
void liberarArrayRecetas(RecetaPtr * r){
    free(r);
};
RecetaPtr * cambiarTamRecetasManteniendoDatos(RecetaPtr * r, int tamViejo, int nuevoTam){
    RecetaPtr * rAux = crearArrayRecetas(nuevoTam);
    for(int i = 0; i<tamViejo;i++){
        rAux[i] = r[i];
    }
    free(r);
    return rAux;
};

ComidaPtr crearComidaParametros(char nombre[50], int identificador, int tRecetas){
    ComidaPtr c = (ComidaPtr) malloc(sizeof(struct Comida));
    strcpy(c->nombre, nombre);
    c->identificador = identificador;
    c->arrayRecetas = crearArrayRecetas(tRecetas);
    return c;
};
void mostrarComida(ComidaPtr c, int t){
    printf("\n--Comida--");
    printf("\nNombre: %s", c->nombre);
    printf("\nIdentificador: %d\n", c->identificador);
    int i = 0;
    while(i<t){
        mostrarReceta(c->arrayRecetas[i]);
        i++;
    }
};
void ordenarRecetasComida(RecetaPtr * arrayRecetas, int t){
    RecetaPtr auxReceta;
    for(int i = 0;i<t-1;i++){
        for(int j = i+1;j<t;j++){
            if(arrayRecetas[i]->paso > arrayRecetas[j]->paso){
                auxReceta = arrayRecetas[i];
                arrayRecetas[i] = arrayRecetas[j];
                arrayRecetas[j] = auxReceta;
            }
        }
    }
};
int busquedaBinariaReceta(RecetaPtr * arrayRecetas, int t, int pasoBuscado){
    int indice = -1;
    int numEncontrado = 0;
    int m;
    int izquierda = 0;
    int derecha = t-1;
    while((!numEncontrado) && (izquierda<=derecha)){
        m = ((izquierda+derecha)/2);
        if(arrayRecetas[m]->paso == pasoBuscado){
            numEncontrado = 1;
            indice = m;
        } else{
            if(arrayRecetas[m]->paso < pasoBuscado){
                izquierda = m + 1;
            } else{
                derecha = m - 1;
            }
        }
    }
    return indice;
};

///FUNCIONES NORMALES
int generarRandom(int min, int max){
    int aleatorio = min + rand() % (max+1-min);
    return aleatorio;
};

///FUNCIONES ARCHIVO
void crearArchivoConComidas(char nombreArchivo[30], ComidaPtr c, int tRecetas){
    FILE * archivoComida = fopen(nombreArchivo, "w");

    fprintf(archivoComida, "--Comida--\n");
    fprintf(archivoComida, "Nombre Comida: %s\n", c->nombre);
    fprintf(archivoComida, "Identificador: %d\n", c->identificador);
    for(int i = 0; i<tRecetas;i++){
        fprintf(archivoComida, "\t--Receta--\n");
        fprintf(archivoComida, "\tPaso: %d\n", c->arrayRecetas[i]->paso);
        fprintf(archivoComida, "\tDescripcion: %s\n", c->arrayRecetas[i]->descripcion);
    }

    fclose(archivoComida);
};
ComidaPtr obtenerDatoComidaArchivo(char nombreArchivo[30]){
    ComidaPtr c;
    FILE * archivoComida = fopen(nombreArchivo, "r");

    int i = 0;
    while(!feof(archivoComida)){
        char textoObtenido[100];
        fgets(textoObtenido, 100, archivoComida);
        if(i == 1){
            strcpy(c->nombre, textoObtenido);
        }
        if(i == 2){
            c->identificador = atoi
        }

        i++;
    }

    fclose(archivoComida);
    return ;
};

