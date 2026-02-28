#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "titulos.h"

struct Jugador{
    int idJugador;
    char nombreJugador[50];
    TitulosPtr * poseeTitulos;
};
typedef struct Jugador * JugadorPtr;

///FUNCIONES JUGADOR
TitulosPtr * crearVectorTitulos(int tTitulos);
void liberarVector(TitulosPtr * vector);
TitulosPtr * redimensionarVectorTitulosManteniendoDatos(TitulosPtr * vectorViejo, int tViejo, int tNuevo);

JugadorPtr crearJugadorParametros(int idJugador, char nombreJugador[50], int tTitulos);
void mostrarJugador(JugadorPtr j, int tTitulos);
void mostrarJugadorConVacios(JugadorPtr j, int tTitulos);
JugadorPtr ordenarPorTitulos(JugadorPtr jugador, int tTitulos);

#endif // JUGADOR_H_INCLUDED
