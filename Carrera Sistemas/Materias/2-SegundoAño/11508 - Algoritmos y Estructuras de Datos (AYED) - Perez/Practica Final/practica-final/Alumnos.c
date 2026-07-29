#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumnos.h"

struct Alumno{
    char nombre[50];
    int dni;
    float promedio;
};

///Creador Y Destructor
AlumnoPtr crearAlumnoParametros(char nombre[50], int dni, float promedio){
    AlumnoPtr a = (AlumnoPtr) malloc(sizeof(struct Alumno));

    strcpy(a->nombre, nombre);
    a->dni = dni;
    a->promedio = promedio;

    return a;
};
void liberarAlumno(AlumnoPtr a){
    free(a);
};


///Utiles Genericos
void mostrarAlumnoGenerico(void * dato){
    AlumnoPtr a = (AlumnoPtr) dato;

    printf("\t--Alumno--\n");
    printf("\t\tNombre: %s\n", a->nombre);
    printf("\t\tDNI: %d\n", a->dni);
    printf("\t\tPromedio: %.2f\n", a->promedio);
};
int busquedaPromedioAlumnoGenerico(void * datoIzq, void * datoDer){
    AlumnoPtr aIzq = (AlumnoPtr) datoIzq;
    AlumnoPtr aDer = (AlumnoPtr) datoDer;

    if (aIzq->promedio == aDer->promedio){
        return 0;
    } else{
        if(aIzq->promedio < aDer->promedio){
            return -1;
        }else{
            return 1;
        }
    }
};


///TDA
//Getters
char * getNombre(AlumnoPtr a){
    return a->nombre;
};
int getDni(AlumnoPtr a){
    return a->dni;
};
float getPromedio(AlumnoPtr a){
    return a->promedio;
};

//Setters
void setNombre(AlumnoPtr a, char nombre[50]){
    strcpy(a->nombre, nombre);
};
void setDni(AlumnoPtr a, int dni){
    a->dni = dni;
};
void setPromedio(AlumnoPtr a, float promedio){
    a->promedio = promedio;
};
