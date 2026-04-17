#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "Persona.h" //Herencia de Persona

struct Empleado;
typedef struct Empleado * EmpleadoPtr;

EmpleadoPtr crearEmpleadoParametros(char nombre[50], char apellido[50], int dni, int edad, char legajo[50], int sueldo, char empresa[50]);
void mostrarEmpleado(EmpleadoPtr e);


//Setters
bool setLegajo(EmpleadoPtr e, char legajo[50]);
bool setEmpresa(EmpleadoPtr e, char empresa[50]);
bool setSueldo(EmpleadoPtr e, int sueldo);
bool setPersona(EmpleadoPtr e, PersonaPtr p);
//Getters
char * getLegajo(EmpleadoPtr e);
char * getEmpresa(EmpleadoPtr e);
int getSueldo(EmpleadoPtr e);
PersonaPtr getPersona(EmpleadoPtr e);

#endif // EMPLEADO_H_INCLUDED
