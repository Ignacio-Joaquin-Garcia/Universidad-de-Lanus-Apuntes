#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "titulos.h"

///FUNCIONES TITULOS
TitulosPtr crearTituloParametros(int idTitulo, char nombreTitulo[50]){
    TitulosPtr t = (TitulosPtr) malloc(sizeof(struct Titulos));
    t->idTitulo = idTitulo;
    strcpy(t->nombreTitulo, nombreTitulo);
    return t;
};
void mostrarTitulo(TitulosPtr t){
    printf("--Titulo--\n");
    printf("\tId: %d\n", t->idTitulo);
    printf("\tNombre Titulo: %s\n", t->nombreTitulo);
};
TitulosPtr cargarTituloVacio(TitulosPtr t){
    t = crearTituloParametros(-1, "VACIO");
    return t;
};
