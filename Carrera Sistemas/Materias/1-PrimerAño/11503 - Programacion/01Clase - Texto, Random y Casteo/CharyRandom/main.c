#include <stdio.h>
#include <stdlib.h>

int main()
{
    char rta[3];

    printf("\nQuiere generar 10 numeros Random? (Si/No)\n");
    scanf("%s", rta);

    printf("\nLa Respuesta es: %s", rta);

    if(rta == "si"){
        printf("\n\nCondicional Exitoso\n");
    }



    return 0;
}
