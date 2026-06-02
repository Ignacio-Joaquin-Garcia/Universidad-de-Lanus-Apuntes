#include <stdio.h>
#include <stdlib.h>

#include "Float.h"

FloatPtr crearFloatParametros(float fP){
    FloatPtr f = (FloatPtr) malloc(sizeof(float));
    *f = fP;
    return f;
};
void liberarFloat(FloatPtr f){
    free(f);
};

void mostrarFloatGenerico(void * dato){
    if( dato == NULL ){
        printf("Dato Nulo\n");
        return;
    }
    float num = *(FloatPtr) dato;
    printf("%.2f, ", num);
}
int busquedaFloatGenerico(void * datoNodo, void * datoBuscado){
    FloatPtr numNodo = (FloatPtr) datoNodo;
    FloatPtr numBuscado = (FloatPtr) datoBuscado;
    if(*numNodo == *numBuscado){
        return 0;
    } else{
        if(*numNodo > *numBuscado){
            return -1;
        } else{
            return 1;
        }
    }
}
