#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Inmueble.h"

struct Inmueble{
    int valor;
    int anoConstruccion;
    char direccion[50];
    char dueno[50];
};

///Constructor y Destructor
InmueblePtr crearInmuebleParametros(int valor, int anoConstruccion, char direccion[50], char dueno[50]){
    InmueblePtr in = (InmueblePtr) malloc(sizeof(struct Inmueble));

    in->valor = valor;
    in->anoConstruccion = anoConstruccion;
    strcpy(in->direccion, direccion);
    strcpy(in->dueno, dueno);

    return in;
};
void liberarInmueble(InmueblePtr in){
    free(in);
};

///Genericos
void mostrarInmuebleGenerico(void * dato){
    InmueblePtr in = (InmueblePtr) dato;

    printf("\t--Inmueble--\n");
    printf("\t\tDueno: %s\n", in->dueno);
    printf("\t\tValor: %d\n", in->valor);
    printf("\t\tAno de Construccion: %d\n", in->anoConstruccion);
    printf("\t\tDireccion: %s\n", in->direccion);
};
int busquedaValorInmuebleGenerico(void * izq, void * der){
    InmueblePtr inIzq = (InmueblePtr) izq;
    InmueblePtr inDer = (InmueblePtr) der;

    if(inIzq->valor == inDer->valor){
        return 0;
    } else{
        if(inIzq->valor < inDer->valor){
            return -1;
        } else{
            return 1;
        }
    }
};



///TDA
//Getters
int getValor(InmueblePtr in){
    return in->valor;
};
int getAnoConstruccion(InmueblePtr in){
    return in->anoConstruccion;
};
char * getDireccion(InmueblePtr in){
    return in->direccion;
};
char * getDueno(InmueblePtr in){
    return in->dueno;
};

//Setters
void setValor(InmueblePtr in, int valor){
    in->valor = valor;
};
void setAnoConstruccion(InmueblePtr in, int anoConstruccion){
    in->anoConstruccion = anoConstruccion;
};
void setDireccion(InmueblePtr in, char direccion[50]){
    strcpy(in->direccion, direccion);
};
void setDueno(InmueblePtr in, char dueno[50]){
    strcpy(in->dueno, dueno);
};
