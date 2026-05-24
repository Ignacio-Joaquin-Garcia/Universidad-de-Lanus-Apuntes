#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

struct Persona;
typedef struct Persona * PersonaPtr;

PersonaPtr crearPersonaParametros(char nombre[50]);
void mostrarPersonaGenerico(void * dato);

ListaGenericaPtr getListaMotivos(PersonaPtr p);
void setListaMotivos(PersonaPtr p, ListaGenericaPtr m);


#endif // PERSONAS_H_INCLUDED
