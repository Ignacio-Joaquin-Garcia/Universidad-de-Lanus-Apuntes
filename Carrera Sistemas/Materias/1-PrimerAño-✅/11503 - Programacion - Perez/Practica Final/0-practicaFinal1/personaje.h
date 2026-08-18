#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED


struct Personaje{
    char nombre[100];
    char tipo[100];
    float altura;
};
typedef struct Personaje * PersonajePtr;

PersonajePtr crearPersonajeParametros(char nombre[100], char tipo[100], float altura);
void mostrarPersonaje(PersonajePtr);
PersonajePtr crearPersonajeVacio();
void crearPersonajesVacios(PersonajePtr contenedorPersonajes[100]);
void mostrarPersonajes(PersonajePtr contenedorPersonajes[100]);
#endif // PERSONAJE_H_INCLUDED
