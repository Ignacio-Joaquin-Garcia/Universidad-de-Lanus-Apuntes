#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avion.h"
#include "pasajero.h"
#include "destino.h"
#include "lista.h"

struct Avion{
  char tipo[20];
  int matricula;
  int capacidad;

  ListaPtr listaPasajeros;

  ListaPtr destinos;
};

ListaPtr getListaPasajeros(AvionPtr a){

    return a->listaPasajeros;
}

AvionPtr crearAvion(char* tipo, int matricula, int capacidad){
    AvionPtr a = (AvionPtr) malloc(sizeof(struct Avion));

    strcpy(a->tipo, tipo);
    a->matricula = matricula;
    a->capacidad = capacidad;

    a->listaPasajeros = crearLista();

    //a->listaDestinos = crearLista();


    return a;
}

char* getTipo(AvionPtr a){
    return a->tipo;
}
int getMatricula(AvionPtr a){
    return a->matricula;
}
int getCapacidad(AvionPtr a){
    return a->capacidad;
}

void setTipo(AvionPtr a, char* tipo){
    strcpy(a->tipo, tipo);
}
void setMatricula(AvionPtr a, int matricula){
    a->matricula = matricula;
}
void setCapacidad(AvionPtr a, int capacidad){
    a->capacidad = capacidad;
}


int agregarPasajero(AvionPtr a, PasajeroPtr p) {
    int ret = 1;
    if (a->capacidad == 0) {
        printf("\nNo hay mas asientos disponibles para agregar al pasajero %s\n", getApellido(p));
        ret = 0;
    } else {
        insertarUltimo(a->listaPasajeros, p);
        a->capacidad = a->capacidad - 1;
    }

    return ret;
};




void mostrarAvion(AvionPtr a){
    printf("\n---------AVION---------\n");
    printf("\nTIPO: %s -- MATRICULA: %d -- CAPACIDAD: %d\n", a->tipo, a->matricula, a->capacidad);

    ///Iterar la lista de pasajeros while
    mostrarListaGenerica(a->listaPasajeros, &mostrarPsajeroDatoPtr);


}


void mostrarAvionDatoPtr(void * a){


    AvionPtr avion = (AvionPtr )a;

    mostrarAvion(avion);
}




void eliminarPasajerosVentanilla(AvionPtr a) {
    NodoPtr actual = getPrimero(a->listaPasajeros);
    NodoPtr anterior = NULL;
    int pos = 0;

    while (actual != NULL) {
        PasajeroPtr p = (PasajeroPtr)getDato(actual);
        if (getVentanilla(p) == 'S') {
            if (anterior == NULL) {
                eliminarPrimero(a->listaPasajeros);
                actual = getPrimero(a->listaPasajeros);
            } else {
                NodoPtr siguiente = getSiguiente(actual);
                eliminarPosicion(a->listaPasajeros, pos);
                actual = siguiente;
                continue;
            }
            a->capacidad++;
        } else {
            anterior = actual;
            actual = getSiguiente(actual);
            pos++;
        }
    }
}


void liberarAvion(AvionPtr a){
    free(a);
}

