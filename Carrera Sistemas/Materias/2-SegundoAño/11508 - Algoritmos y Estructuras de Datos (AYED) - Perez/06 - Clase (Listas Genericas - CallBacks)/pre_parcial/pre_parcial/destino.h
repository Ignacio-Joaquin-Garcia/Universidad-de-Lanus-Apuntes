#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

struct Destino;
typedef struct Destino * DestinoPtr;

DestinoPtr crearDestino(char* ciudad, float latitud, float longitud);

char* getCiudad(DestinoPtr d);
float getLatitud(DestinoPtr d);
float getLongitud(DestinoPtr d);

void setCiudad(DestinoPtr d, char* ciudad);
void setLatitud(DestinoPtr d, float latitud);
void setLongitud(DestinoPtr d, float longitud);

void mostrarDestino(DestinoPtr d);

void liberarDestino(DestinoPtr d);


#endif // DESTINO_H_INCLUDED
