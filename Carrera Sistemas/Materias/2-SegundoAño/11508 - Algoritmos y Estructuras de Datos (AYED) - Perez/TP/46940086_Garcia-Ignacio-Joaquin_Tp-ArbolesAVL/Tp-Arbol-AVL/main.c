#include <stdio.h>
#include <stdlib.h>

#include "Float.h"
#include "Persona.h"
#include "Arbol.h"



int main()
{
    ///Arbol de Floats Sin Balanceo
    printf("----Ejemplos de la Libreria sin Balanceos----\n\n");
    printf("----Floats----\n");
    FloatPtr f1 = crearFloatParametros(0.245);
    FloatPtr f2 = crearFloatParametros(2);
    FloatPtr f3 = crearFloatParametros(1);
    FloatPtr f4 = crearFloatParametros(3.14);
    FloatPtr f5 = crearFloatParametros(5.6);
    FloatPtr f6 = crearFloatParametros(100.1);

    NodoPtr arbol = crearNodo(f1);

    insertarArbol(arbol, f2, busquedaFloatGenerico);
    insertarArbol(arbol, f3, busquedaFloatGenerico);
    insertarArbol(arbol, f4, busquedaFloatGenerico);
    insertarArbol(arbol, f5, busquedaFloatGenerico);
    insertarArbol(arbol, f6, busquedaFloatGenerico);

    printf("Muestra de la creacion del arbol en PreOrden:\n\n");
    mostrarArbolPreorden(arbol, mostrarFloatGenerico);
    printf("Muestra de la creacion del arbol en InOrden:\n\n");
    mostrarArbolInorden(arbol, mostrarFloatGenerico);
    printf("Muestra de la creacion del arbol en PostOrden:\n\n");
    mostrarArbolPostorden(arbol, mostrarFloatGenerico);
    printf("Muestra de la creacion del arbol Acostado:\n\n");
    mostrarArbolAcostado(arbol, 0, mostrarFloatGenerico);
    printf("Factor de Balance del nodo arbol (%.2f): %d\n", *(FloatPtr) getDato(arbol), balanceo(buscarBinario(arbol, getDato(arbol), busquedaFloatGenerico)));

    NodoPtr nodoBuscado = buscarBinario(arbol, f4, busquedaFloatGenerico);
    printf("\n\nBusqueda Binaria del nodo f4: ");
    mostrarFloatGenerico(getDato(nodoBuscado));
    printf("\n\n");

    printf("Eliminacion de dato + muestra del arbol real acostado para mejor visualizacion y debuggeo\n\n");
    eliminarDatoArbol(arbol, f4, busquedaFloatGenerico);
    mostrarArbolAcostado(arbol, 0, mostrarFloatGenerico);
    printf("Factor de Balance del nodo arbol (%.2f): %d\n", *(FloatPtr) getDato(arbol), balanceo(buscarBinario(arbol, getDato(arbol), busquedaFloatGenerico)));


    ///Arbol de Personas Sin Balanceo
    printf("----Personas----\n");
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

    printf("\nMuestra del arbol Personas InOrden\n");
    mostrarArbolInorden(arbolPersonas, mostrarPersonaGenerico);

    printf("\nMuestra del arbol Personas con dato eliminado Acostado\n\n");
    eliminarDatoArbol(arbolPersonas, p3, busquedaPersonaGenerico);
    mostrarArbolAcostado(arbolPersonas, 0, mostrarPersonaGenerico);



    ///Prueba de Floats Balanceado + Estadisticas
    printf("\n\n----Ejemplos de la Libreria con Balanceos----\n\n");
    printf("----Floats Balanceado----\n");
    f4 = crearFloatParametros(3.14); // Dato eliminado anteriormente
    NodoPtr arbolFloatBalanceado = crearNodo(f1);

    insertarArbolBalanceado(&arbolFloatBalanceado, f2, busquedaFloatGenerico);
    insertarArbolBalanceado(&arbolFloatBalanceado, f3, busquedaFloatGenerico);
    insertarArbolBalanceado(&arbolFloatBalanceado, f4, busquedaFloatGenerico);
    insertarArbolBalanceado(&arbolFloatBalanceado, f5, busquedaFloatGenerico);
    insertarArbolBalanceado(&arbolFloatBalanceado, f6, busquedaFloatGenerico);

    mostrarArbolAcostado(arbolFloatBalanceado, 0, mostrarFloatGenerico);

    printf("Arbol con dato: %.2f eliminado\n\n", *f4);
    eliminarDatoArbolBalanceado(arbolFloatBalanceado, f4, busquedaFloatGenerico);
    mostrarArbolAcostado(arbolFloatBalanceado, 0, mostrarFloatGenerico);

    printf("\nAltura del Arbol: %d\n", alturaArbol(arbolFloatBalanceado));
    printf("Altura del Nodo f6 (%.2f): %d\n", *f6, alturaArbol(buscarBinario(arbolFloatBalanceado, f6, busquedaFloatGenerico)));
    printf("Peso del Arbol: %d\n", obtenerPeso(arbolFloatBalanceado));
    printf("Cantidad Total de Hojas del Arbol: %d\n", obtenerCantidadTotalHojas(arbolFloatBalanceado));
    printf("Factor de Balance del nodo arbol (%.2f): %d\n", *(FloatPtr) getDato(arbolFloatBalanceado), balanceo(buscarBinario(arbolFloatBalanceado, getDato(arbol), busquedaFloatGenerico)));
    printf("Nivel del primer nodo a la derecha del arbol (%.2f): %d\n", *(FloatPtr) getDato(getDerecha(arbolFloatBalanceado)), obtenerNivel(arbolFloatBalanceado, getDerecha(arbolFloatBalanceado)));
    printf("Nodo Minimo del Arbol: %.2f\n", *(FloatPtr) getDato(obtenerMinNodo(arbolFloatBalanceado)));
    printf("Nodo Maximo del Arbol: %.2f\n\n", *(FloatPtr) getDato(obtenerMaxNodo(arbolFloatBalanceado)));

    ///Prueba de Personas Balanceado + Estadisticas
    printf("\n\n----Personas Balanceado----\n\n");
    p3 = crearPersonaParametros("Rama", 15); // Dato eliminado anteriormente
    NodoPtr arbolPersonasBalanceado = crearNodo(p1);

    insertarArbol(arbolPersonasBalanceado, p2, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p3, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p4, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p5, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p6, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p7, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p8, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p9, busquedaPersonaGenerico);
    insertarArbol(arbolPersonasBalanceado, p10, busquedaPersonaGenerico);

    mostrarArbolAcostado(arbolPersonasBalanceado, 0, mostrarPersonaGenerico);

    printf("\n\n\nArbol con Persona: ");
    mostrarPersona(p3);
    printf(" eliminada\n\n\n");
    eliminarDatoArbolBalanceado(arbolPersonasBalanceado, p3, busquedaPersonaGenerico);
    mostrarArbolAcostado(arbolPersonasBalanceado, 0, mostrarPersonaGenerico);

    printf("\nAltura del Arbol: %d\n", alturaArbol(arbolPersonasBalanceado));

    printf("Altura del Nodo p5 (%s): %d\n", getNombre(p5), alturaArbol(buscarBinario(arbolPersonasBalanceado, p5, busquedaPersonaGenerico)));
    printf("Peso del Arbol: %d\n", obtenerPeso(arbolPersonasBalanceado));
    printf("Cantidad Total de Hojas del Arbol: %d\n", obtenerCantidadTotalHojas(arbolPersonasBalanceado));
    printf("Factor de Balance del nodo arbol: %d\n", balanceo(arbolPersonasBalanceado));
    printf("Nivel del primer nodo a la derecha del arbol (%s): %d\n", getNombre(getDato(getDerecha(arbolPersonasBalanceado))), obtenerNivel(arbolPersonasBalanceado, getDerecha(arbolPersonasBalanceado)));
    printf("Nodo Minimo del Arbol (Segun Edad): %s\n", getNombre(getDato(obtenerMinNodo(arbolPersonasBalanceado))));
    printf("Nodo Maximo del Arbol (Segun Edad): %s\n\n", getNombre(getDato(obtenerMaxNodo(arbolPersonasBalanceado))));

    return 0;
}
