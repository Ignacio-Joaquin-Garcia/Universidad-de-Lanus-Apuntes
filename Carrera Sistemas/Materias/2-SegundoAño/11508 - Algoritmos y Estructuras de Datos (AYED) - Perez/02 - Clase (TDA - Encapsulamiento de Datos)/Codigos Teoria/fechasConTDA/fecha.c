#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"


struct Fecha {
    int anio;
    int mes;
    int dia;
    DiaSemana diaSemana;
};




//Constructor y destructor
FechaPtr crearFecha(int d, int m, int a){

    FechaPtr f = (FechaPtr) malloc(sizeof(struct Fecha));

    f->anio = a;
    f->dia = d;
    f->mes  = m;
    //Calcular el dia de la semana
    f->diaSemana = determinarDiaDeLaSemana(d,m,a);

    return f;

};
void destruirFecha(FechaPtr fecha){

    free(fecha);

};

//Getters and setters
int getDia(FechaPtr fecha){

           return fecha->dia;
};

int getMes(FechaPtr fecha){
 return fecha->mes;
 };

int getAnio(FechaPtr fecha){

     return fecha->anio;
};
int getDiaSemana(FechaPtr fecha){

     return fecha->diaSemana;

};

void setDia(FechaPtr fecha, int d){

    fecha->dia = d;

};
void setMes(FechaPtr fecha, int m){

    fecha->mes = m;

};;
void setAnio(FechaPtr fecha, int a){

    fecha->anio= a;

};

void setDiaSemana(FechaPtr fecha, int diaS){

    fecha->diaSemana = diaS;

};;


void mostrarFecha(FechaPtr fecha){

    printf("\n------- DIA: %s ---------\n", nombreDiaSemana(fecha->diaSemana) );
    printf("----- FECHA: %d/%d/%d -----\n", fecha->anio, fecha->mes, fecha->dia);

};

// Funciones para manipular fechas
FechaPtr fechaSumarDias(FechaPtr fecha, int dias);
int fechaComparar(FechaPtr fecha1, FechaPtr fecha2);
int fechaDiasEntre(FechaPtr fecha1, FechaPtr fecha2);

// Función para determinar el día de la semana utilizando el algoritmo de Zeller
DiaSemana determinarDiaDeLaSemana(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int K = year % 100;
    int J = year / 100;

    int dia_semana = (day + ((13 * (month + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    switch (dia_semana) {
        case 0:
            return DOMINGO;
        case 1:
            return LUNES;
        case 2:
            return MARTES;
        case 3:
            return MIERCOLES;
        case 4:
            return JUEVES;
        case 5:
            return VIERNES;
        case 6:
            return SABADO;
    }
    //No entro al switch, igual imposible por congruencia
    return -1;
}



// Función para retornar el nombre del día de la semana
char* nombreDiaSemana(int num_dia) {
    switch (num_dia) {
        case 0:
            return "Domingo";
        case 1:
            return "Lunes";
        case 2:
            return "Martes";
        case 3:
            return "Miércoles";
        case 4:
            return "Jueves";
        case 5:
            return "Viernes";
        case 6:
            return "Sábado";
        default:
            return "Día inválido";
    }
}
