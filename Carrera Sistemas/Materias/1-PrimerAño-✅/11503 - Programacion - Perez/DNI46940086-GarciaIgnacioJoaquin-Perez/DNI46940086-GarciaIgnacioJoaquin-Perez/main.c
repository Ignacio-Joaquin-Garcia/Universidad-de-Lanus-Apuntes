#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "titulos.h"
#include "jugador.h"

int main()
{
    TitulosPtr titulo1 = crearTituloParametros(50, "Licenciado Sistemas\n");
    TitulosPtr titulo2 = crearTituloParametros(32, "Licenciado Nutricion\n");

    int tVector = 3;
    JugadorPtr jugador1 = crearJugadorParametros(0, "Pablo", tVector);
    jugador1->poseeTitulos[0] = titulo1;
    jugador1->poseeTitulos[1] = titulo2;
    printf("\n----Jugador Inicial----\n\n");
    mostrarJugador(jugador1, tVector);

    jugador1 = ordenarPorTitulos(jugador1, tVector);
    printf("\n----Jugador con titulos Ordenados----\n\n");
    mostrarJugador(jugador1, tVector);

    jugador1->poseeTitulos = redimensionarVectorTitulosManteniendoDatos(jugador1->poseeTitulos, tVector, 10);
    tVector = 10;
    printf("\n----Print de Vector Redimensionado con Vacios----\n\n");
    mostrarJugadorConVacios(jugador1, tVector);

    jugador1->poseeTitulos[0] = crearTituloParametros(88, "Ingeniero Mecatronia\n");
    jugador1->poseeTitulos[3] = crearTituloParametros(2, "Tecnico1\n");
    jugador1->poseeTitulos[4] = crearTituloParametros(8, "Tecnico2\n");
    jugador1->poseeTitulos[5] = crearTituloParametros(1, "Tecnico3\n");
    jugador1->poseeTitulos[6] = crearTituloParametros(14, "Tecnico4\n");
    jugador1->poseeTitulos[7] = crearTituloParametros(12, "Tecnico5\n");
    jugador1->poseeTitulos[8] = crearTituloParametros(9, "Tecnico6\n");

    printf("\n----Print de Vector Modificado----\n\n");
    mostrarJugador(jugador1, tVector);

    jugador1 = ordenarPorTitulos(jugador1, tVector);
    printf("\n----Jugador con titulos Ordenados x 2----\n\n");
    mostrarJugador(jugador1, tVector);

    return 0;
};
