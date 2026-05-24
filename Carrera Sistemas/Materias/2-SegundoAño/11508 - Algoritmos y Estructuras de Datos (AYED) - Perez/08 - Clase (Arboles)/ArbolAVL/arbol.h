#ifndef __ARBOL_H__
#define __ARBOL_H__
#include <stdio.h>
#include <stdlib.h>

struct ArbolE;


typedef struct ArbolE * ArbolAVL;


int insertar(ArbolAVL * un_arbol, int);
int buscar(ArbolAVL un_arbol, int);
int eliminar(ArbolAVL * un_arbol, int);
void mostrar(ArbolAVL un_arbol);

int altura_arbolavl(ArbolAVL un_arbol);


int balanceo(ArbolAVL un_arbol);
void balancear_arbolavl(ArbolAVL * un_arbol);
int rotar_derecha(ArbolAVL * un_arbol);
int rotar_izq(ArbolAVL * un_arbol);

int reordenar(ArbolAVL * un_arbol, ArbolAVL * aux_arbol);

#endif
