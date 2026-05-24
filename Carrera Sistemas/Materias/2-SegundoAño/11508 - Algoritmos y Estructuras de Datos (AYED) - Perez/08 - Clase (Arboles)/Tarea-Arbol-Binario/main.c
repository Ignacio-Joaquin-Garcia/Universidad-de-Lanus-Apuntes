#include <stdio.h>
#include <stdlib.h>

#include "Persona.h"
#include "Arbol.h"

void mostrarFloatGenerico(void * dato){
    if( dato == NULL ){
        printf("Dato Nulo\n");
        return;
    }
    float num = *(float *) dato;
    printf("%.2f, ", num);
}
int busquedaFloatGenerico(void * datoNodo, void * datoBuscado){
    float numNodo = *(float *) datoNodo;
    float numBuscado = *(float *) datoBuscado;
    if(numNodo == numBuscado){
        return 0;
    } else{
        if(numNodo > numBuscado){
            return -1;
        } else{
            return 1;
        }
    }
}

int main()
{
    ///Arbol de Floats
    //Los float enrealidad se deberian hacer en un archivo separado y con punteros para hacer malloc y una liberacion de memoria correcta manejada por el arbol
    float f1 = 3.14, f2 = 2, f3 = 4.1, f4 = 1.2, f5 = 1.6, f6 = 2.1;
    NodoPtr arbol = crearNodo(&f1);

    insertarArbol(arbol, &f2, busquedaFloatGenerico);
    insertarArbol(arbol, &f3, busquedaFloatGenerico);
    insertarArbol(arbol, &f4, busquedaFloatGenerico);
    insertarArbol(arbol, &f5, busquedaFloatGenerico);
    insertarArbol(arbol, &f6, busquedaFloatGenerico);

    mostrarArbolPreorden(arbol, mostrarFloatGenerico);

    NodoPtr nodoBuscado = buscarBinario(arbol, &f4, busquedaFloatGenerico);
    printf("\n\nBusqueda Binaria: ");
    mostrarFloatGenerico(getDato(nodoBuscado));
    printf("\n");

    eliminarDatoArbol(arbol, &f6, busquedaFloatGenerico);
    mostrarArbolPreorden(arbol, mostrarFloatGenerico);

    ///Arbol de Personas
    PersonaPtr p1 = crearPersonaParametros("Igna", 20);
    PersonaPtr p2 = crearPersonaParametros("Pepe", 25);
    PersonaPtr p3 = crearPersonaParametros("Rama", 15);
    PersonaPtr p4 = crearPersonaParametros("Mati", 21);
    PersonaPtr p5 = crearPersonaParametros("Carlos", 19);
    PersonaPtr p6 = crearPersonaParametros("Pedro", 30);
    PersonaPtr p7 = crearPersonaParametros("Juan", 5);
    PersonaPtr p8 = crearPersonaParametros("Jose", 45);
    PersonaPtr p9 = crearPersonaParametros("Pepito", 6);
    PersonaPtr p10 = crearPersonaParametros("Pepas", 22);

    NodoPtr arbolPersonas = crearNodo(p1);

    insertarArbol(arbolPersonas, p2, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p3, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p4, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p5, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p6, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p7, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p8, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p9, busquedaPersonaGenerico);
    insertarArbol(arbolPersonas, p10, busquedaPersonaGenerico);

    printf("\n\n\n");
    mostrarArbolPreorden(arbolPersonas, mostrarPersonaGenerico);

    eliminarDatoArbol(arbolPersonas, p3, busquedaPersonaGenerico);
    printf("\n\n\n");
    mostrarArbolPreorden(arbolPersonas, mostrarPersonaGenerico);



    return 0;
}
