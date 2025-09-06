#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Declaracion Funciones
int generarAleatorio(int min, int max);
int generarAleatorioImp3OPar2();

int scanearValor(char textoPrint[100]);
void consoleLog(int n, char textoAgregado[100]);

int formaCargaVector();
void cargarValoresVector(int tam, int a[], int formaCargaVector, int numVector);
void mostrarVector(int tam, int a[], int numVector);

int contarParesEnVector(int tam, int a[]);
int calculoPromedioImpares(int tam, int a[]);
int contarNumSupAValor(int tam, int a[], int requisito);
int buscarRepetidosEntreArreglos(int tam1, int a1[], int tam2, int a2[]);
void compararArreglos(int tam1, int a1[], int tam2, int a2[]);

void procesoEstadisticasVector(int tam, int a[], int requisito,int numVector);

int main()
{
    ///Librerias
    srand(time(0));

    ///Definicion e Inicializacion
    int leng = scanearValor("Ingrese cantidad de Valores a Agregar de manera Aleatoria en el Vector 1");
    int leng2 = scanearValor("Ingrese cantidad de Valores a Agregar de manera Aleatoria en el Vector 2");
    int vector[leng];
    int vector2[leng2];

    //Estadisticas
    int requisito1 = scanearValor("Ingrese valor que el numero tiene que superar para contarlo en el vector 1");
    int requisito2 = scanearValor("Ingrese valor que el numero tiene que superar para contarlo en el vector 2");

    int cantRepetidosEntreArreglos;

    ///Proceso

    //Necesarios del vector
    int formaCargaVectores = formaCargaVector();
    cargarValoresVector(leng, vector, formaCargaVectores, 1);
    mostrarVector(leng, vector, 1);
    cargarValoresVector(leng2, vector2, formaCargaVectores, 2);
    mostrarVector(leng2, vector2, 2);

    ///"Salida"
    printf("\n\n");

    //Calculo Estadisticas Individuales
        //Estadisticas Individuales de los Vectores
        procesoEstadisticasVector(leng, vector, requisito1, 1);
        procesoEstadisticasVector(leng2, vector2, requisito2, 2);

    //Calculos Estadisticas Entre Vectores
    printf("\n\n\tEstadisticas Compatidas entre Vectores\n\n");
    cantRepetidosEntreArreglos = buscarRepetidosEntreArreglos(leng, vector, leng2, vector2);
    consoleLog(cantRepetidosEntreArreglos, "Cantidad de Numeros Repetidos entre los Arreglos es de");
    compararArreglos(leng, vector, leng2, vector2);

    printf("\n\n");
    return 0;
}

///Implementacion Funciones
int generarAleatorio(int min, int max){
    int resultado = min  + rand() % (max + 1 -(min));
    return resultado;
}
int generarAleatorioImp3OPar2(){
    int cumpleRequisitos = 0;
    while (cumpleRequisitos != 1){

        int randomParOImpar = generarAleatorio(10,999);
        if(randomParOImpar <=99){
            if(randomParOImpar % 2 == 0){
                cumpleRequisitos = 1;
                return randomParOImpar;
            }
        } else{
            if(randomParOImpar % 2 != 0){
                cumpleRequisitos = 1;
                return randomParOImpar;
            }
        }
    }
    return 0;
};
int scanearValor(char textoPrint[25]){
    int n;
    printf("\n%s: ",textoPrint);
    scanf("%d", &n);
    while(n <= 0){
        printf("\nIngrese un valor Valido!!\n");
        scanf("%d", &n);
    }
    return n;
};
void consoleLog(int n, char textoAgregado[100]){
    int cantCaracteres = sizeof(textoAgregado);
    if(cantCaracteres > 0){
        printf("\n%s: %d \n", textoAgregado, n);
    } else{
        printf("\nValor: %d \n", n);
    }
};
int formaCargaVector(){
    printf("\n¿Como quiere cargar los vectores de manera Aleatoria(0) o por teclado(1)?\n");
    int formaCargaVectores;
    scanf("%d", &formaCargaVectores);
    while(formaCargaVectores != 0 && formaCargaVectores != 1){
        printf("\nIngrese un valor valido. Aleatorio o por Teclado (0/1) respectivamente: ");
        scanf("%d", &formaCargaVectores);
    }
    return formaCargaVectores;
};
void cargarValoresVector(int tam, int a[], int formaCargaVector, int numVector){
    if(formaCargaVector == 0){
        for(int i = 0;i<tam;i++){
            a[i] = generarAleatorioImp3OPar2();
        };
    } else{
        for(int i = 0;i<tam;i++){
            printf("\nIngrese valor %d del vector %d: ", i+1, numVector);
            int valorTeclado;
            scanf("%d", &valorTeclado);
            a[i] = valorTeclado;
        };
    };
};
void mostrarVector(int tam, int a[], int numVector){
    printf("\n\nVector %d: [", numVector);
    for(int i = 0;i<tam;i++){
        if(i != (tam-1)){
            printf("%d, ", a[i]);
        } else{
            printf("%d]\n", a[i]);
        }
    }
};
int contarParesEnVector(int tam, int a[]){
    int pares = 0;
    for(int i = 0;i<tam;i++){
        if(a[i] % 2 == 0){
            pares++;
        }
    }
    return pares;
};
int calculoPromedioImpares(int tam, int a[]){
    int acumImpares = 0;
    int contador = 0;
    for(int i = 0;i<tam;i++){
        contador = contador + 1;
        if((a[i] % 2) != 0){
            acumImpares = acumImpares + a[i];
        }
    }
    if(acumImpares > 0){
        int promedioImp = acumImpares / contador;
        return promedioImp;
    } else{
        return 0;
    }
};
int contarNumSupAValor(int tam, int a[], int requisito){
    int cantCumplieron = 0;
    for(int i = 0;i<tam;i++){
        if(a[i] > requisito){
            cantCumplieron = cantCumplieron + 1;
        }
    }
    return cantCumplieron;
};
int buscarRepetidosEntreArreglos(int tam1, int a1[], int tam2, int a2[]){
    int cantRepetidos = 0;
    for(int i = 0;i<tam1;i++){
        for(int j = 0;j<tam2;j++){
            if(a1[i] == a2[j]){
                cantRepetidos++;
            }
        }
    }
    return cantRepetidos;
};
void compararArreglos(int tam1, int a1[], int tam2, int a2[]){
    int vectoresExactamenteIguales = 1;
    if(tam1 == tam2){
        for(int i = 0;i<tam1;i++){
            for(int j = 0;j<tam2;j++){
                if(a1[i] != a2[j]){
                    vectoresExactamenteIguales = 0;
                }
            }
        }
    } else{
        vectoresExactamenteIguales = 0;
    }

    if(vectoresExactamenteIguales == 1){
        printf("\nLos Vectores son Exactamente Iguales");
    } else{
        printf("\nLos Vectores son Diferentes");
    };
};
void procesoEstadisticasVector(int tam, int a[], int requisito,int numVector){
    printf("\n\n\tEstadisticas Vector %d\n\n", numVector);
    int paresVector = contarParesEnVector(tam, a);
    consoleLog(paresVector, "Pares Totales");

    int promedioImpares = calculoPromedioImpares(tam, a);
    consoleLog(promedioImpares, "El Promedio del Valor de Numeros Impares es de");

    int numSuperiorARequisito = contarNumSupAValor(tam,a,requisito);
    printf("\nLa cantidad de numeros que superaron %d son: %d\n", requisito, numSuperiorARequisito);
};

