#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED


//La struct deja de estar implementada en el .h
struct PersonaE;

typedef struct PersonaE * PersonaPtr; //->nombre
//Getters y setters
int getDNI(PersonaPtr p);
char* getNombre(PersonaPtr p);


void setDNI(PersonaPtr p, int nuevoDNI);
void setNombre(PersonaPtr p, char nuevoNombre[15]);


//




//Constructores
PersonaPtr crearPersonaTeclado(); //Teclado

PersonaPtr crearPersona(int d, char n[15]);

PersonaPtr crearPersonaYCarton(int d, char n[15], char dir[15]);

//Destructor
void destruirPersona(PersonaPtr p);

//Mostrar
void mostrarPersona(PersonaPtr p);


///Agregar cosas...
//agregarCarton
//cargarCarton
//crearPersona(dir)


void mostrarPersonaDatoPtr (void * p);

int compararPersonasDatoPtr(void * p1, void * p2);

#endif // PERSONA_H_INCLUDED
