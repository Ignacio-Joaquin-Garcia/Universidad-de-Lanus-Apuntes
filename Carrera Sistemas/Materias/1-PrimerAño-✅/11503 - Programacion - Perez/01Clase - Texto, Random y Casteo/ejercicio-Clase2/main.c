#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    ///Definicion
    int notaExamen;
    int hayNotasParaAnadir = 1;
    int cantNotasAleatoriaAnadir;
    int hayNotasAleatorias = 0;

    int acumPromedio = 0;
    int contador = 0;
    float promedio;

    float notaMinimaAprobacion;
    int aprobados = 0;
    int desaprobados = 0;

    int acumPromedioPares = 0;
    int contadorPares = 0;
    float promedioPares;
    int contadorImpares = 0;

    int mejorNota;
    int indiceM;
    int peorNota;
    int indiceP;

    ///Inicializacion

    ///Proceso
    printf("Bienvenido al cargador de examenes!! Primero setee algunos ajustes antes de empezar a cargar notas\n\n");
    printf("\tCon que nota minima aprueban los estudiantes su materia?\n\t");
    scanf("%f", &notaMinimaAprobacion);


    printf("\n\n\nIngresar nota (0-10, -1: no Ingresar mas notas, 11: Ingreso nota aleatoria): ");
    scanf("%d", &notaExamen);
    printf("\nNota Ingresada: %d", notaExamen);

    while (hayNotasParaAnadir == 1){
        while(!(notaExamen >= -1 && notaExamen <= 11)){
            printf("\nPor Favor Ingresar una nota valida: ");
            scanf("%d", &notaExamen);
            printf("\nNota Ingresada: %d", notaExamen);
        }
        if(notaExamen == -1){
           hayNotasParaAnadir = 0;
        } else{
            //Condicional de Ingreso Random
            if(notaExamen == 11){
                printf("\nCuantas Notas Aleatorias quiere añadir?");
                scanf("%d", &cantNotasAleatoriaAnadir);
                printf("Ingresando %d notas Aleatorias...", cantNotasAleatoriaAnadir);
                hayNotasAleatorias = 1;
            } else{
                cantNotasAleatoriaAnadir = 1; //para que el bucle se ejecute aunque no se hayan ingresado notas aleatorias
                hayNotasAleatorias = 0;
            }
            //Analisis Principal
            for(int i = 0;i<cantNotasAleatoriaAnadir;i++){
                if(hayNotasAleatorias == 1){
                    notaExamen = 0 + rand() % (10 + 1 - 0);
                    printf("%d..", notaExamen);
                }
                //Promedio

                acumPromedio = acumPromedio + notaExamen;
                contador = contador + 1; //Contador Principal

                //Condicional de cant aprobados
                if(notaExamen >= notaMinimaAprobacion){
                    aprobados = aprobados + 1;
                } else{
                    desaprobados = desaprobados + 1;
                }

                //Condicional de pares e impares
                if((notaExamen % 2 == 0) && (notaExamen >= notaMinimaAprobacion)){
                    acumPromedioPares = acumPromedioPares + notaExamen;
                    contadorPares = contadorPares + 1;
                }
                if(notaExamen % 2 != 0){
                    contadorImpares = contadorImpares + 1;
                }

                //Condicional mejor y peor nota
                if((notaExamen > mejorNota) || (contador == 1)){
                    mejorNota = notaExamen;
                    indiceM = contador;
                }
                if((notaExamen < peorNota) || (contador == 1)){
                    peorNota = notaExamen;
                    indiceP = contador;
                }
            }
            printf("\nIngresar nota (0-10, -1: no Ingresar mas notas, 11: Ingreso nota aleatoria): ");
            scanf("%d", &notaExamen);
            printf("\nNota Examen: %d", notaExamen);
        }
    }

    if(contador > 0){
        if(acumPromedio != 0){
            promedio = ((float)acumPromedio) / contador;
        };
    }else{
        printf("\n\nNo Hubieron notas");
    };
    if(contadorPares > 0){
        if(acumPromedioPares > 0){
            promedioPares = ((float)acumPromedioPares) / contadorPares;
        };
    }else{
        printf("\n\nNo Hubieron notas pares y aprobadas");
    };



    ///Salida

    printf("\n\nEl promedio de las notas ingresadas es de: %.2f", promedio);
    printf("\nLa cantidad de notas ingresadas es de: %d", contador);

    printf("\n\nAprobaron: %d, y desaprobaron: %d", aprobados, desaprobados);

    //Ausentes
    printf("\n\nLa Cantidad de notas impares es de: %d", contadorImpares);

    printf("\n\nEl Promedio de notas pares y aprobadas es de: %.2f", promedioPares);

    printf("\n\nLa mejor nota fue de: %d, ingresado como la %d nota", mejorNota, indiceM);
    printf("\nLa peor nota fue de: %d, ingresado como la %d nota", peorNota, indiceP);

    return 0;
}
