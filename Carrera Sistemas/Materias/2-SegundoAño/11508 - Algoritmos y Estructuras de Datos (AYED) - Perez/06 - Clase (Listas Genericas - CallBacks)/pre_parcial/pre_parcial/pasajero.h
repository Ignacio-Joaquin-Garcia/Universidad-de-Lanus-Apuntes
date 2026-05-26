#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED

struct Pasajero;
typedef struct Pasajero * PasajeroPtr;

PasajeroPtr crearPasajero(char* apellido, int dni, char ventanilla);

char* getApellido(PasajeroPtr p);
int getDni(PasajeroPtr p);
char getVentanilla(PasajeroPtr p);

void setApellido(PasajeroPtr p, char* apellido);
void setDni(PasajeroPtr p, int dni);
void setVentanilla(PasajeroPtr p, char ventanilla);

void mostrarPasajero(PasajeroPtr p);
void mostrarPsajeroDatoPtr (void * p);

void liberarPasajero(PasajeroPtr p);

#endif // PASAJERO_H_INCLUDED
