#ifndef CARICATURA_H_INCLUDED
#define CARICATURA_H_INCLUDED

#include "personaje.h"
struct Caricatura{
    char genero[100];
    char nombre[100];
    char paisOrigen[100];
    PersonajePtr poseePersonajes[10];
};
struct Caricatura crearCaricaturaParametros(char genero[100], char nombre[100], char paisOrigen[100]);
void mostrarCaricatura(struct Caricatura c);
struct Caricatura crearCaricaturaVacia();
struct Caricatura ordenarPorAltura(struct Caricatura c);
struct Caricatura ordenarPorNombre(struct Caricatura c);

#endif // CARICATURA_H_INCLUDED
