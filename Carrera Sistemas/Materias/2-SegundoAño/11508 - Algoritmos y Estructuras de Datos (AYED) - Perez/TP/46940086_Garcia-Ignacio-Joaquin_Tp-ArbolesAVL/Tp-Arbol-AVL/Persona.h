#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct Persona;
typedef struct Persona * PersonaPtr;

PersonaPtr crearPersonaParametros(char nombre[45], int edad);
void liberarPersona(PersonaPtr p);

void mostrarPersona(PersonaPtr p);
void mostrarPersonaGenerico(void * dato);
int busquedaPersonaGenerico(void * datoNodo, void * datoBuscado);


///Getters
char * getNombre(PersonaPtr p);
int getEdad(PersonaPtr p);
///Setters
void setNombre(PersonaPtr p, char nombre[45]);
void setEdad(PersonaPtr p, int edad);

#endif // PERSONA_H_INCLUDED
