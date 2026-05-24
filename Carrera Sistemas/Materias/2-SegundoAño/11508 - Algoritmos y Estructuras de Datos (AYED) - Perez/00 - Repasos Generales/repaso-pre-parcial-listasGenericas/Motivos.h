#ifndef MOTIVOS_H_INCLUDED
#define MOTIVOS_H_INCLUDED

struct Motivos;
typedef struct Motivos * MotivosPtr;

MotivosPtr crearMotivosParametros(int id, char descripcion[50]);
void mostrarMotivosGenericos(void * dato);

#endif // MOTIVOS_H_INCLUDED
