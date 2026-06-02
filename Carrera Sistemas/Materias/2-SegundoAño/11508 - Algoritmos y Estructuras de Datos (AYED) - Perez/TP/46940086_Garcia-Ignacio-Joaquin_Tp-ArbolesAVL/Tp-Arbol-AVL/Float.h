#ifndef FLOAT_H_INCLUDED
#define FLOAT_H_INCLUDED

typedef float * FloatPtr;

FloatPtr crearFloatParametros(float fP);
void liberarFloat(FloatPtr f);

void mostrarFloatGenerico(void * dato);
int busquedaFloatGenerico(void * datoNodo, void * datoBuscado);



#endif // FLOAT_H_INCLUDED
