#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///Definicion
    char gender;
    char name[25];


    ///Proceso
    printf("\nCual es tu genero?\n");
    gender = getchar();

    printf("Genero = %c",gender);

    printf("\nCual es tu Nombre?\n");
    scanf("%s", &name);
    /*
    getchar();
    fgets(name,sizeof(name),stdin);
    */
    ///Salida
    printf("\n\n\nBienvenido %s, tu genero es: %c!!", name, gender);


    return 0;
}
