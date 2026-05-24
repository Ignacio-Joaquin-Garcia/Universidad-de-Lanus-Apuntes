#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

int main()
{



     ArbolAVL un_arbol = NULL;



    insertar(&un_arbol ,1);

    insertar(&un_arbol ,55);

    insertar(&un_arbol ,24);

    insertar(&un_arbol ,12);

    insertar(&un_arbol ,13);


    mostrar(un_arbol);
    printf("\n\n");




    return 0;
}
