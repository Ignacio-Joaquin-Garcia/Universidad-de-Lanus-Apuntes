#ifndef TITULOS_H_INCLUDED
#define TITULOS_H_INCLUDED

struct Titulos{
    int idTitulo;
    char nombreTitulo[50];
};
typedef struct Titulos * TitulosPtr;

///FUNCIONES TITULOS
TitulosPtr crearTituloParametros(int idTitulo, char nombreTitulo[50]);
void mostrarTitulo(TitulosPtr t);
TitulosPtr cargarTituloVacio(TitulosPtr t);

#endif // TITULOS_H_INCLUDED
