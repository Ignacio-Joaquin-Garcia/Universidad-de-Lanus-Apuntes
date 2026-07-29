#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Funciones de Inicializacion
int checkIngresoDatos(int superiorAEsteNumero, char textoIngreso[100], char textoAyuda[100]);
int generarAleatorios(int min, int max);
float generarAleatorioConComa(int min, int max);
void cargarMatrizGanaciasEmpresas(int filas, int columnas, float matriz[filas][columnas], int min, int max);
void mostrarMatriz(int filas, int columnas, float matriz[filas][columnas]);
//Funciones de Estadisticas
float totalGanadoPorEmpresa(int filas, int columnas, float matriz[filas][columnas]);  //A
float promedioGeneralGanaciasPorMes(int filas, int columnas, float matriz[filas][columnas]);  //B
void gananciaMesEmpresas(int filas, int columnas, float matriz[filas][columnas], char meses[12][15]);  //B
float totalGanadoGeneral(int filas, int columnas, float matriz[filas][columnas]);  //C

float mayorGananciaEmpresaIndividual(int filas, int columnas, float matriz[filas][columnas], int mayorMenor);  //D y E
int busquedaEmpresaGananciaM(int filas, int columnas, float matriz[filas][columnas], float mayorGananciaEmpresaIndividual, int mayorMenor);  //D y E
int mesMayorGanancia(int filas, int columnas, float matriz[filas][columnas], float mayorGananciaEmpresaIndividual, int empresa, int mayorMenor);  //D y E

void promedioGananciasPorBimestre(int filas, int columnas, float matriz[filas][columnas]);  //F

int main()
{
    ///LIBRERIAS
    srand(time(0));
    ///DEFINICION e INICIALIZACION
    int filas = 4;
    int columnas = 12;
    float matriz[filas][columnas];

    int minAleatorio = checkIngresoDatos(-1, "\nIngrese NUMERO MINIMO ENTERO para generar su matriz Aleatoria de numeros decimales(sepa que su numero se generara con coma y puede exeder el n ingresado): ", "Por favor ingrese un numero valido MAYOR a 0: ");
    int maxAleatorio = checkIngresoDatos(minAleatorio, "\nIngrese NUMERO MAXIMO ENTERO para generar su matriz Aleatoria de numeros decimales(sepa que su numero se generara con coma y puede exeder el n ingresado): ", "Por favor ingrese un numero valido MAYOR al anterior Ingresado en el numero MINIMO: ");


    cargarMatrizGanaciasEmpresas(filas, columnas, matriz, minAleatorio, maxAleatorio);
    mostrarMatriz(filas, columnas, matriz);

    char vectorMeses[12][15] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}; //D y E

    float gananciaAnoEmpresa; //A
    float promedioGeneral;  //B
    float totalGananciasEmpresas;  //C
    float mayorGanaciaDeTodasLasEmpresas;  //D
    int empresaDeLaMayorGanacia; //D
    int mesDeLaMayorGanancia;  //D

    float menorGanaciaDeTodasLasEmpresas;  //E
    int empresaDeLaMenorGanacia; //E
    int mesDeLaMenorGanancia;  //E


    ///PROCESO
    //B)
    promedioGeneral = promedioGeneralGanaciasPorMes(filas, columnas, matriz);
    //C)
    totalGananciasEmpresas = totalGanadoGeneral(filas, columnas, matriz);
    //D
    mayorGanaciaDeTodasLasEmpresas = mayorGananciaEmpresaIndividual(filas, columnas, matriz, 0);
    empresaDeLaMayorGanacia = busquedaEmpresaGananciaM(filas,columnas,matriz, mayorGanaciaDeTodasLasEmpresas, 0);
    mesDeLaMayorGanancia = mesMayorGanancia(filas, columnas, matriz, mayorGanaciaDeTodasLasEmpresas, (empresaDeLaMayorGanacia), 0);
    //E)
    menorGanaciaDeTodasLasEmpresas = mayorGananciaEmpresaIndividual(filas, columnas, matriz, 1);
    empresaDeLaMenorGanacia = busquedaEmpresaGananciaM(filas,columnas,matriz, mayorGanaciaDeTodasLasEmpresas, 1);
    mesDeLaMenorGanancia = mesMayorGanancia(filas, columnas, matriz, mayorGanaciaDeTodasLasEmpresas, (empresaDeLaMayorGanacia), 1);

    ///SALIDA
    for(int i=0;i<filas;i++){
        gananciaAnoEmpresa = totalGanadoPorEmpresa(i, columnas, matriz);
        printf("\nel TOTAL GANADO por la EMPRESA %d en un año es de: $%.2f", i+1, gananciaAnoEmpresa);
    }
    printf("\n");
    printf("\nEl PROMEDIO GENERAL ganado por MES entre todas las empresas es de: $%.2f", promedioGeneral);
    gananciaMesEmpresas(filas, columnas, matriz, vectorMeses);
    printf("\n");
    printf("\nEl TOTAL GANADO por todas las empresas es de: $%.2f", totalGananciasEmpresas);
    printf("\n");
    printf("\nLa MAYOR ganancia la hizo la EMPRESA %d, ganando en total: $%.2f.\nSu mayor ganancia fue en el MES de: %s, con una GANANCIA de: $%.2f\n", empresaDeLaMayorGanacia+1, mayorGanaciaDeTodasLasEmpresas, vectorMeses[mesDeLaMayorGanancia],matriz[empresaDeLaMayorGanacia][mesDeLaMayorGanancia]);
    printf("\nLa MENOR ganancia la hizo la EMPRESA %d, ganando en total: $%.2f.\nSu menor ganancia fue en el MES de: %s, con una GANANCIA de: $%.2f\n", empresaDeLaMenorGanacia+1, menorGanaciaDeTodasLasEmpresas, vectorMeses[mesDeLaMenorGanancia],matriz[empresaDeLaMenorGanacia][mesDeLaMenorGanancia]);
    printf("\n");
    promedioGananciasPorBimestre(filas,columnas,matriz);
    printf("\n");

    return 0;
};

//Inicializacion
int checkIngresoDatos(int superiorAEsteNumero, char textoIngreso[100], char textoAyuda[100]){
    int dato;
    printf("%s", textoIngreso);
    scanf("%d", &dato);
    while(dato <= superiorAEsteNumero){
        printf("\n\t%s", textoAyuda);
        scanf("%d", &dato);
    }
    return dato;
};
int generarAleatorios(int min, int max){
    int numAleatorio = min + rand() % (max+1-min);
    return numAleatorio;
};
float generarAleatorioConComa(int min, int max){
    int numAleatorio = generarAleatorios(min, max);
    float comaAleatoria = ((float)(generarAleatorios(0, 99)) / 100 );
    printf("%d,%.0f...", numAleatorio, comaAleatoria*100);
    float numAleatorioConComa = numAleatorio + comaAleatoria;
    return numAleatorioConComa;
}
void cargarMatrizGanaciasEmpresas(int filas, int columnas, float matriz[filas][columnas], int min, int max){
    printf("\n\nGenerando matriz aleatoria: \n");
    for (int f = 0; f<filas; f++){
        for (int c = 0; c<columnas; c++){
            matriz[f][c] = generarAleatorioConComa(min, max);
        }
    }
    printf("\n");
};
void mostrarMatriz(int filas, int columnas, float matriz[filas][columnas]){
    int empresa = 1;
    printf("\n");
    for (int f = 0; f<filas; f++){
        printf("Empresa %d: [ ", empresa);
        for (int c = 0; c<columnas; c++){
            if(c != columnas-1){
                printf("$%.2f, ", matriz[f][c]);
            } else{
                printf("$%.2f ", matriz[f][c]);
            }
        }
        empresa++;
        printf("]\n");
    }
};
//Estadisticas
float totalGanadoPorEmpresa(int filas, int columnas, float matriz[filas][columnas]){
    float sumaGanancias = 0;
    for(int c = 0;c<columnas;c++){
        sumaGanancias = sumaGanancias + matriz[filas][c];
    }
    return sumaGanancias;
};
float promedioGeneralGanaciasPorMes(int filas, int columnas, float matriz[filas][columnas]){
    float acumTotal = 0;
    int contador = 0;
    for (int f = 0; f<filas; f++){
        for (int c = 0; c<columnas; c++){
            acumTotal = acumTotal + matriz[f][c];
            contador++;
        }
    }
    float promedioTotal;
    if(acumTotal > 0){
        promedioTotal = acumTotal / (float)contador;
    } else {
        promedioTotal = 0;
    }
    return promedioTotal;
};
void gananciaMesEmpresas(int filas, int columnas, float matriz[filas][columnas], char meses[12][15]){
    float sumaEmpresas;
    printf("\nGANANCIAS POR MES:\n");
    for(int c = 0;c<columnas;c++){
        sumaEmpresas = 0;
        for(int f = 0; f<filas;f++){
            sumaEmpresas = sumaEmpresas + matriz[f][c];
        }
        printf("\tGanancia en el mes de %s: $%.2f\n", meses[c], sumaEmpresas);
    }
};
float totalGanadoGeneral(int filas, int columnas, float matriz[filas][columnas]){
    float sumaGananciasTotales = 0;
    for(int f = 0;f<filas;f++){
        for(int c = 0; c<columnas;c++){
            sumaGananciasTotales = sumaGananciasTotales + matriz[f][c];
        }
    }
    return sumaGananciasTotales;
};
float mayorGananciaEmpresaIndividual(int filas, int columnas, float matriz[filas][columnas], int mayorMenor){
    float vectorGananciasEmpresas[filas];
    float acum;
    for(int f = 0; f<filas;f++){
        acum = matriz[f][0];
        for(int c = 1; c<columnas;c++){
            acum = acum + matriz[f][c];
        }
        vectorGananciasEmpresas[f] = acum;
    }
    float mayorGanaciaMes = vectorGananciasEmpresas[0];
    for(int i = 1; i<filas;i++){
        if(mayorMenor == 0){
            if(mayorGanaciaMes < vectorGananciasEmpresas[i]){
                mayorGanaciaMes = vectorGananciasEmpresas[i];
            }
        }
        if(mayorMenor == 1){
            if(mayorGanaciaMes > vectorGananciasEmpresas[i]){
                mayorGanaciaMes = vectorGananciasEmpresas[i];
            }
        }
    }
    return mayorGanaciaMes;
};
int busquedaEmpresaGananciaM(int filas, int columnas, float matriz[filas][columnas], float mayorGananciaEmpresaIndividual, int mayorMenor){
    int indiceGanancia = -1;
    float mayorGanancia;
    float acum;
    for(int f = 0; f<filas;f++){
        acum = matriz[f][0];
        for(int c = 1; c<columnas;c++){
            acum = acum + matriz[f][c];
        }
        if(f==0){
            mayorGanancia = acum;
            indiceGanancia = f;
        } else{
            if(mayorMenor == 0){
                if(mayorGanancia < acum){
                    indiceGanancia = f;
                    mayorGanancia = acum;
                }
            }
            if(mayorMenor == 1){
                if(mayorGanancia > acum){
                    indiceGanancia = f;
                    mayorGanancia = acum;
                }
            }
        }
    }
    if(indiceGanancia == -1){
        printf("\n--->ERROR al encontrar la empresa con mayor ganancia<---\n");
    } else{
        return indiceGanancia;
    }
    return 0;
};
int mesMayorGanancia(int filas, int columnas, float matriz[filas][columnas], float mayorGananciaEmpresaIndividual, int empresa, int mayorMenor){
    int mesMayorGananciaBusqueda = -1;
    float numMayorGananciaBusqueda = matriz[empresa][0];
    for(int c = 0; c<columnas;c++){
        if(mayorMenor == 0){
            if(numMayorGananciaBusqueda < matriz[empresa][c]){
                numMayorGananciaBusqueda = matriz[empresa][c];
                mesMayorGananciaBusqueda = c;
            }
        }
        if(mayorMenor == 1){
            if(numMayorGananciaBusqueda > matriz[empresa][c]){
                numMayorGananciaBusqueda = matriz[empresa][c];
                mesMayorGananciaBusqueda = c;
            }
        }
    };
    if(mesMayorGananciaBusqueda == -1){
        printf("\n--->ERROR al encontrar el mes con mayor ganancia<---\n");
    } else{
        return mesMayorGananciaBusqueda;
    }
    return 0;
};



void promedioGananciasPorBimestre(int filas, int columnas, float matriz[filas][columnas]){
    float promedioBimestre;
    float acum;
    int contadorBimestres;

    float matrizBimestres[filas][6];

    for(int f = 0; f<filas;f++){
        contadorBimestres = 0;
        printf("\nPromedios Bimestrales empresa %d: \n", f+1);
        for(int c = 0; c<columnas; c=c+2){
            for(int i = 0; i<=1;i++){
                if(i==0){
                    acum = matriz[f][c+i];
                } else{
                    acum = acum + matriz[f][c+i];
                }
            }
            if(acum!=0){
                contadorBimestres++;
                promedioBimestre = acum / 2;
                matrizBimestres[f][contadorBimestres-1] = promedioBimestre;
                printf("\tPromedio bimestre %d: $%.2f\n", contadorBimestres, promedioBimestre);
            }
        }
    }

    printf("\n\nQuien gano mas en cada bimestre segun su promedio-->");
    float mayorPromedio;
    int empresaMayorPromedio;
    for(int b = 0; b<6;b++){
        mayorPromedio = matrizBimestres[0][0];
        empresaMayorPromedio = 0;
        for(int f = 0; f<filas; f++){
            if(mayorPromedio < matrizBimestres[f][b]){
                mayorPromedio = matrizBimestres[f][b];
                empresaMayorPromedio = f;
            }
        }
        printf("\n\tBimestre %d, gano la empresa %d con un promedio ganado de: $%.2f", b+1, empresaMayorPromedio+1, mayorPromedio);
    }

};
