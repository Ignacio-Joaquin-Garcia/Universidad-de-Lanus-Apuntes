#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Utiles.h"

#include "Alumnos.h"
#include "Inmueble.h"
#include "Lista.h"
#include "Cola.h"

#include "ArbolBinario.h"

int main()
{
    srand(time(0));

    printf("Num Random: %d\n", generarNumRandom(0, 10));
    printf("Num Random: %d\n", generarNumRandom(0, 10));
    printf("Num Random: %d\n", generarNumRandom(0, 10));
    printf("Num Random: %d\n", generarNumRandom(0, 10));
    printf("Num Random: %d\n", generarNumRandom(0, 10));

    /// Listas Genericas
    // ALUMNOS
    AlumnoPtr a1 = crearAlumnoParametros("Pepe", 11111111, 1.50);
    AlumnoPtr a2 = crearAlumnoParametros("Carlos", 22222222, 5);
    AlumnoPtr a3 = crearAlumnoParametros("Juan", 33333333, 3.75);
    AlumnoPtr a4 = crearAlumnoParametros("Mati", 44444444, 2);
    AlumnoPtr a5 = crearAlumnoParametros("Rama", 55555555, 6);

    ListaPtr listaAlumnos = crearLista();

    insertarPrimero(listaAlumnos, a1);
    insertarPrimero(listaAlumnos, a2);
    insertarPrimero(listaAlumnos, a3);
    insertarPrimero(listaAlumnos, a4);
    insertarPrimero(listaAlumnos, a5);

    mostrarListaGenerico(listaAlumnos, mostrarAlumnoGenerico);
    printf("Tam Lista: %d\n\n", tamLista(listaAlumnos));

    ListaPtr listaAlumnosOrdenada = duplicarYOrdenar(listaAlumnos, busquedaPromedioAlumnoGenerico);
    mostrarListaGenerico(listaAlumnosOrdenada, mostrarAlumnoGenerico);

    // INMUEBLES
    InmueblePtr in1 = crearInmuebleParametros(1000, 2005, "Burzaco", "Pedro");
    InmueblePtr in2 = crearInmuebleParametros(5, 2015, "Lomas", "Carlos");
    InmueblePtr in3 = crearInmuebleParametros(100, 2025, "Lanus", "Juan");
    InmueblePtr in4 = crearInmuebleParametros(200, 2000, "Temperley", "Mati");
    InmueblePtr in5 = crearInmuebleParametros(1, 2006, "Longchamps", "Rama");
    InmueblePtr in6 = crearInmuebleParametros(0, 1990, "Constitucion", "Igna");

    ListaPtr listaInmuebles = crearLista();

    insertarUltimo(listaInmuebles, in1);
    insertarUltimo(listaInmuebles, in2);
    insertarUltimo(listaInmuebles, in3);
    insertarUltimo(listaInmuebles, in4);
    insertarUltimo(listaInmuebles, in5);
    insertarPos(listaInmuebles, in6, 3);

    mostrarListaGenerico(listaInmuebles, mostrarInmuebleGenerico);

    ListaPtr listaInmueblesOrdenada = duplicarYOrdenar(listaInmuebles, busquedaValorInmuebleGenerico);
    mostrarListaGenerico(listaInmueblesOrdenada, mostrarInmuebleGenerico);

    NodoPtr datoBuscado = busquedaSecuencialGenerico(listaInmueblesOrdenada, in3, busquedaValorInmuebleGenerico);
    printf("Nodo Buscado: \n");
    mostrarInmuebleGenerico(getDato(datoBuscado));

    /// Listas Especiales
    // Colas
    ColaPtr colaBanco = crearCola();
    encolar(colaBanco, a1);
    encolar(colaBanco, a2);
    encolar(colaBanco, a3);

    NodoPtr desencolado = desencolar(colaBanco);
    mostrarNodoGenerico(desencolado, mostrarAlumnoGenerico);
    desencolado = desencolar(colaBanco);
    mostrarNodoGenerico(desencolado, mostrarAlumnoGenerico);
    desencolado = desencolar(colaBanco);
    mostrarNodoGenerico(desencolado, mostrarAlumnoGenerico);
    desencolado = desencolar(colaBanco);
    mostrarNodoGenerico(desencolado, mostrarAlumnoGenerico);


    // Pilas



    /// Arboles
    // ARBOLES BINARIOS
    printf("-- Arboles Binarios --\n");
    NodoArbolPtr raizArbol = crearNodo(a1);

    insertarEnArbol(raizArbol, a2, busquedaPromedioAlumnoGenerico);
    insertarEnArbol(raizArbol, a3, busquedaPromedioAlumnoGenerico);
    insertarEnArbol(raizArbol, a4, busquedaPromedioAlumnoGenerico);
    insertarEnArbol(raizArbol, a5, busquedaPromedioAlumnoGenerico);

    inOrden(raizArbol, mostrarAlumnoGenerico);

    printf("(buscarBinario)-> Busqueda de Nodo Juan segun promedio: \n");
    NodoArbolPtr nodoBuscado = buscarBinario(raizArbol, a3, busquedaPromedioAlumnoGenerico);
    mostrarAlumnoGenerico(getDatoArbol(nodoBuscado));

    // ARBOLES AVL




    return 0;
}
