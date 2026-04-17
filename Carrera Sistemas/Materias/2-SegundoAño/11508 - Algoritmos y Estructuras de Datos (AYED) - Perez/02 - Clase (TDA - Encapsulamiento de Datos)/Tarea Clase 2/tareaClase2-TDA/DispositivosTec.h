#ifndef DISPOSITIVOSTEC_H_INCLUDED
#define DISPOSITIVOSTEC_H_INCLUDED

struct DispositivosTec;
typedef struct DispositivosTec * DispositivosTecPtr;

DispositivosTecPtr crearDispositivoTecParametros(char tipo[50], char marca[50], int precio, char memoria[50]);
void mostrarDispositivoTec(DispositivosTecPtr d);


//Setters
bool setTipo(DispositivosTecPtr d, char tipo[50]);
bool setMarca(DispositivosTecPtr d, char marca[50]);
bool setPrecio(DispositivosTecPtr d, int precio);
bool setMemoria(DispositivosTecPtr d, char memoria[50]);
//Getters
int getPrecio(DispositivosTecPtr d);
char * getTipo(DispositivosTecPtr d);
char * getMarca(DispositivosTecPtr d);
char * getMemoria(DispositivosTecPtr d);


#endif // DISPOSITIVOSTEC_H_INCLUDED
