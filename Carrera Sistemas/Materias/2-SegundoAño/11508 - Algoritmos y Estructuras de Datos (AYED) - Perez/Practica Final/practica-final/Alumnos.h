#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED

struct Alumno;
typedef struct Alumno * AlumnoPtr;

///Creador Y Destructor
AlumnoPtr crearAlumnoParametros(char nombre[50], int dni, float promedio);
void liberarAlumno(AlumnoPtr a);


///Utiles Genericos
void mostrarAlumnoGenerico(void * dato);
int busquedaPromedioAlumnoGenerico(void * datoIzq, void * datoDer);

///TDA
//Getters
char * getNombre(AlumnoPtr a);
int getDni(AlumnoPtr a);
float getPromedio(AlumnoPtr a);

//Setters
void setNombre(AlumnoPtr a, char nombre[50]);
void setDni(AlumnoPtr a, int dni);
void setPromedio(AlumnoPtr a, float promedio);


#endif // ALUMNOS_H_INCLUDED
