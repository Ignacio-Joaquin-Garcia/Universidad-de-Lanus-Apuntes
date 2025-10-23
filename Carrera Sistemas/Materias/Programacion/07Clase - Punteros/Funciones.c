#include <stdio.h>
#include <stdlib.h>

int scanfVerificado(int minValor, char textoPrint[100], char textoAyuda[100]){
    printf("\n%s: ", textoPrint);
    int vNumerica;
    scanf("%d", &vNumerica);
    while(minValor > vNumerica){
        printf("\n%s: ", textoAyuda);
        scanf("%d", &vNumerica);
    }
    return vNumerica;
};



