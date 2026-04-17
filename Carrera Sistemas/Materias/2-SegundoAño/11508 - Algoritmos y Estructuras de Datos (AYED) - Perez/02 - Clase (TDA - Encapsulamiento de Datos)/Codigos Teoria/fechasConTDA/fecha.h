#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED



typedef enum {DOMINGO,LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO} DiaSemana;

struct Fecha;

typedef struct Fecha * FechaPtr;

//Constructor y destructor
FechaPtr crearFecha(int d, int m, int a);
void destruirFecha(FechaPtr fecha);

//Getters and setters
int getDia(FechaPtr fecha);
int getMes(FechaPtr fecha);
int getAnio(FechaPtr fecha);
int getDiaSemana(FechaPtr fecha);

void setDia(FechaPtr fecha, int d);
void setMes(FechaPtr fecha, int m);
void setAnio(FechaPtr fecha, int a);
void setDiaSemana(FechaPtr fecha, int diaS);


//Mostrar
void mostrarFecha(FechaPtr fecha);

// Funciones para manipular fechas
FechaPtr fechaSumarDias(FechaPtr fecha, int dias);
int fechaComparar(FechaPtr fecha1, FechaPtr fecha2);
int fechaDiasEntre(FechaPtr fecha1, FechaPtr fecha2);


//Algoritmo de Zeller sin librerias
DiaSemana determinarDiaDeLaSemana(int day, int month, int year);

// Función para retornar el nombre del día de la semana
char* nombreDiaSemana(int num_dia);

#endif // FECHA_H_INCLUDED
