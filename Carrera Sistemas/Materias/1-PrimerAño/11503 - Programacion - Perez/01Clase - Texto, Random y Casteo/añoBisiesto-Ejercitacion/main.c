#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///Definicion
    int anoBisiestoSaber;
    int esAnoBisiesto = 0;

    int saberTodosAnosBisiestos;

    printf("\nQue Año deseas saber si es Bisiesto?\n");
    scanf("%d", &anoBisiestoSaber);

    printf("Desea ademas saber todos los años Bisiestos hasta el año 5000? (1=SI/2=No)\n");
    scanf("%d", &saberTodosAnosBisiestos);

    ///Proceso

    if((anoBisiestoSaber % 4 == 0) && (!(anoBisiestoSaber % 100 ==0) || ((anoBisiestoSaber % 100 ==0)) && (anoBisiestoSaber % 400 ==0))){
        esAnoBisiesto = 1;
    }

    printf("Todos los Años Bisiestos hasta el 5000 a continuacion:\n");
    if(saberTodosAnosBisiestos == 1){
        for(int i = 0;i<=5000;i++){
            if((i % 4 == 0) && (!(i % 100 ==0) || ((i % 100 ==0)) && (i % 400 ==0))){
                printf("%d \n", i);
            }
        }
    }

    ///Salida
    if(esAnoBisiesto == 1){
        printf("\n\n\nEl Año: %d, ES un Año Bisiesto\n", anoBisiestoSaber);
    } else{
        printf("El año %d NO es Bisiesto", anoBisiestoSaber);
    }




    return 0;
}
