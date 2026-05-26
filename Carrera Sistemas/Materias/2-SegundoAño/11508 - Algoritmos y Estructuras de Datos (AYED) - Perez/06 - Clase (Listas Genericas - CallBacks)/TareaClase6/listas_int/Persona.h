#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct Persona;
typedef struct Persona * PersonaPtr;

PersonaPtr crearPersonaParametros(char nombre[45], int edad);
void mostrarPersona(PersonaPtr p);

///Genericas
void mostrarPersonaGenerica(void * dato);
bool funcionOrdenarPersonasGenerica(void * d1, void * d2);
bool funcionCompararGenerica(void * d1, void * d2);
int funcionCompararBinarioGenerica(void * d1, void * d2);

#endif // PERSONA_H_INCLUDED
