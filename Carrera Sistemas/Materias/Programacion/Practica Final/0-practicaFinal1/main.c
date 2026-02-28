#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "personaje.h"
#include "caricatura.h"
#include "canalInfantil.h"
#include "nodo.h"
#include "lista.h"
int main()
{
    ///DEFINICIONES E INICIALIZACION
    struct CanalInfantil cartoonNetwork = crearCanalParametros("Cartoon Network", "www.cartoonnetwork.com", 1992);

    cartoonNetwork.poseeCaricaturas[0] = crearCaricaturaParametros("Serie de TV", "Plim Plim", "Argentina");
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[0] = crearPersonajeParametros("Arafa", "Jirafa", 3.55);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[1] = crearPersonajeParametros("Acuarella", "Conejo", 0.45);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[2] = crearPersonajeParametros("Mei-Li", "Gato", 0.65);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[3] = crearPersonajeParametros("Hoggie", "Cerdo", 1.12);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[4] = crearPersonajeParametros("Wichiwi", "Pajaro", 0.22);

    cartoonNetwork.poseeCaricaturas[1] = crearCaricaturaParametros("Serie animada", "Bluey", "Australiana");
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[0] = crearPersonajeParametros("Bluey", "Cachorro", 0.95);
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[1] = crearPersonajeParametros("Bingo", "Cachorra", 0.45);
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[2] = crearPersonajeParametros("Bandit", "Perro", 1.23);
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[3] = crearPersonajeParametros("Chili", "Perra", 1.12);


    ///PROCESO

    mostrarCanalInfantil(cartoonNetwork);
    cartoonNetwork.poseeCaricaturas[0] = ordenarPorAltura(cartoonNetwork.poseeCaricaturas[0]);
    cartoonNetwork.poseeCaricaturas[1] = ordenarPorNombre(cartoonNetwork.poseeCaricaturas[1]);
    printf("\n---Ordenados por nombre: Bluey y por altura: PlimPllim---\n");
    mostrarCanalInfantil(cartoonNetwork);

    printf("\n---Busqueda de Personaje Hoggie por medio de su altura---\n");
    PersonajePtr personajeBuscado = busquedaBinaria(1.12, 0, cartoonNetwork);
    mostrarPersonaje(personajeBuscado);

    printf("\n---Personajes que miden menos de 1 Eliminados---\n");
    cartoonNetwork = eliminarPorAltura(2, 1, cartoonNetwork);
    mostrarCanalInfantil(cartoonNetwork);

    printf("\n---Calculo de promedio de alturas con todos los personajes en el mismo arreglo");
    ListaPtr contenedorPersonajes = crearLista();
    anadirCaricaturaALaLista(contenedorPersonajes, cartoonNetwork.poseeCaricaturas[0]);
    anadirCaricaturaALaLista(contenedorPersonajes, cartoonNetwork.poseeCaricaturas[1]);
    mostrarLista(contenedorPersonajes);
    float promedioAltura = calculoPromedioAlturaPersonajes(contenedorPersonajes);
    printf("\nEl promedio de la altura de todos los personajes es de: %.2f\n", promedioAltura);


    ///SALIDA

    return 0;
};


