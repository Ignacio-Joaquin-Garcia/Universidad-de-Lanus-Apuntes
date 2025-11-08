#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaraAleatorio(int min, int max){
    int numRandom = min + (rand() % (max + 1 - min));
    return numRandom;
}
