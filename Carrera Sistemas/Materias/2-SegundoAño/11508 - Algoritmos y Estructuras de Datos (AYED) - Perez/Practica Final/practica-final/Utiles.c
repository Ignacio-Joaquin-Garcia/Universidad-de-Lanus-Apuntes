#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Utiles.h"

int generarNumRandom(int numMin, int numMax){
    int numAleatorio = numMin + rand() % (numMax + 1 - numMin);
    return numAleatorio;
};
