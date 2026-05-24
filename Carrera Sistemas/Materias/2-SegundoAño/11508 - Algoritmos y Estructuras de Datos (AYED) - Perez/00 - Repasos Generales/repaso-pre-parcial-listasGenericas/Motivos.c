#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListasGenericas.h"
#include "Persona.h"

struct Motivos{
    int id;
    char descripcion[50];
};
typedef struct Motivos * MotivosPtr;

MotivosPtr crearMotivosParametros(int id, char descripcion[50]){
    MotivosPtr m = malloc(sizeof(struct Motivos));

    m->id = id;
    strcpy(m->descripcion, descripcion);

    return m;
};
void mostrarMotivosGenericos(void * dato){
    MotivosPtr m = (MotivosPtr) dato;
    printf("\n\t\t--Motivos--");
    printf("\n\t\t\tId: %d", m->id);
    printf("\n\t\t\tDescripcion: %s", m->descripcion);
};
