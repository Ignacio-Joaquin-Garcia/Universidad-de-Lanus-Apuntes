#ifndef CANALINFANTIL_H_INCLUDED
#define CANALINFANTIL_H_INCLUDED

#include "personaje.h"
#include "caricatura.h"
struct CanalInfantil{
    char nombre[100];
    char web[100];
    int anoCreacion;
    struct Caricatura poseeCaricaturas[100];
};
struct CanalInfantil crearCanalParametros(char nombre[100], char web[100], int anoCreacion);
void mostrarCanalInfantil(struct CanalInfantil ci);
struct CanalInfantil eliminarPorAltura(int cantCaricaturas, int altura, struct CanalInfantil ci);
PersonajePtr busquedaBinaria(float alturaBuscada, int caricaturaBuscar, struct CanalInfantil ci);

#endif // CANALINFANTIL_H_INCLUDED
