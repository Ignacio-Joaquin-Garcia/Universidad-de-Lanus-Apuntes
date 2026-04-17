#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

struct Matriz;
typedef struct Matriz * MatrizPtr;

//Constructor
MatrizPtr crearMatriz(int f, int c);
//Destructor
void liberarMatriz(MatrizPtr m);
//Dinamismo
MatrizPtr cambiarTamMatriz(MatrizPtr m, int fNuevo, int cNuevo);
//Carga
void cargarMatrizParametros(MatrizPtr m, int fCarga, int cCarga, int matrizCarga[fCarga][cCarga]);
void cargarMatrizAleatoria(MatrizPtr m);
//Muestreo
void mostrarMatriz(MatrizPtr m);
//Estadisticas
int buscarMaximoMatriz(MatrizPtr m);
int buscarMinimoMatriz(MatrizPtr m);
int promedioMatriz(MatrizPtr m);
int sumaDeMatriz(MatrizPtr m);
long long productoDeMatriz(MatrizPtr m);

//Getters
int getColumnas(MatrizPtr m);
int getFilas(MatrizPtr m);
//Setter
bool setColumnas(MatrizPtr m, int columnas);
bool setFilas(MatrizPtr m, int filas);
bool setMatriz(MatrizPtr m, int fMatriz, int cMatriz, int matriz[fMatriz][cMatriz]);


#endif // MATRICES_H_INCLUDED
