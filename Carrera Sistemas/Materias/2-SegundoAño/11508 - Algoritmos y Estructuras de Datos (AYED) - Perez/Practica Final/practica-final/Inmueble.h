#ifndef INMUEBLE_H_INCLUDED
#define INMUEBLE_H_INCLUDED

struct Inmueble;
typedef struct Inmueble * InmueblePtr;

///Constructor y Destructor
InmueblePtr crearInmuebleParametros(int valor, int anoConstruccion, char direccion[50], char dueno[50]);
void liberarInmueble(InmueblePtr in);

///Genericos
void mostrarInmuebleGenerico(void * dato);
int busquedaValorInmuebleGenerico(void * izq, void * der);

///TDA
//Getters
int getValor(InmueblePtr in);
int getAnoConstruccion(InmueblePtr in);
char * getDireccion(InmueblePtr in);
char * getDueno(InmueblePtr in);

//Setters
void setValor(InmueblePtr in, int valor);
void setAnoConstruccion(InmueblePtr in, int anoConstruccion);
void setDireccion(InmueblePtr in, char direccion[50]);
void setDueno(InmueblePtr in, char dueno[50]);

#endif // INMUEBLE_H_INCLUDED
