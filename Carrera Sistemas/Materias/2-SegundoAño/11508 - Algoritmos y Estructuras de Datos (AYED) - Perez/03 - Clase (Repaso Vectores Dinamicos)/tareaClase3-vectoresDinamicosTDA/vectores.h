#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

struct Vector;
typedef struct Vector * VectorPtr;

//Constructor
VectorPtr crearVector(int tam);
//Destructor
void liberarVector(VectorPtr v);

//Carga
void cargarVectorParametros(int vCarga[], int tamVectorCarga, VectorPtr v);
void cambiarTamVector(VectorPtr v, int nuevoTam);
void cargarVectorAleatorio(VectorPtr v, int minimo, int maximo);
//Muestreo
void mostrarVector(VectorPtr v);
void mostrarVectorInvertido(VectorPtr v);
//Orden y Busqueda
void ordenarVector(VectorPtr v);
int busquedaSecuencialVector(VectorPtr v, int numBuscado);
int busquedaBinariaVector(VectorPtr v, int numBuscado);
//Utiles
int contarParesEnVector(VectorPtr v);
int calcularModuloVector(VectorPtr v);
int buscarMaximoVector(VectorPtr v);
int buscarMinimoVector(VectorPtr v);
int sumaDeVectores(VectorPtr v1, VectorPtr v2);
void multiplicacionEscalarVector(VectorPtr v1, int escalar);

//Utiles
int generarNumAleatorio(int minimo, int maximo);

//Getters
int getTam(VectorPtr v);
int * getVector(VectorPtr v);
//Setters
bool setTam(VectorPtr v, int tam);
bool setVector(VectorPtr v, int vCarga[], int tamVCarga);

#endif // VECTORES_H_INCLUDED
