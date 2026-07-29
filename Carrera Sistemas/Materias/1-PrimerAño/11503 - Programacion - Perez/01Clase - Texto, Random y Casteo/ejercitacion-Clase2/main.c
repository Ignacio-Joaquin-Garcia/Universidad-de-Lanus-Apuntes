#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///EJERCICIO 9 BLOQUE 1
    //Definicion
    float weight;
    float height;
    float corporalWeight;

    //Inicializacion
    printf("\nCual es tu peso?\n");
    scanf("%f", &weight);
    printf("\nCual es tu altura?\n");
    scanf("%f", &height);

    //Proceso
    corporalWeight = (weight / (height * height));




    //Salida
    printf("Tu peso corporal es de: %.2f", corporalWeight);

    if(corporalWeight < 18.5){
        printf("\nPeso Inferior al Normal!\n\n");
    }
    if((corporalWeight >= 18.5) && (corporalWeight <= 24.9)){
        printf("\nNormal\n\n");
    }
    if((corporalWeight >= 25) && (corporalWeight <= 29.9)){
        printf("\nPeso Superior al Normal\n\n");
    }
    if(corporalWeight > 30){
        printf("\nObesidad\n\n");
    }


    ///EJERCICIO 15 BLOQUE 1
    int num;
    double factorial;
    double multiplicado = 1;
    printf("\n\n\nIngrese un Numero para calcular su factorial\n");
    scanf("%d", &num);
    if(num <= 0){
        num = num * -1;
        for(int i = 1;i<=num;i++){
            multiplicado = i * multiplicado;
        }
        factorial = multiplicado * -1;
    } else{
        for(int i = 1;i<=num;i++){
            multiplicado = i * multiplicado;
        }
        factorial = multiplicado;
    }
    printf("\nEl numero factorial es: %.0lf\n",factorial);


    return 0;
}
