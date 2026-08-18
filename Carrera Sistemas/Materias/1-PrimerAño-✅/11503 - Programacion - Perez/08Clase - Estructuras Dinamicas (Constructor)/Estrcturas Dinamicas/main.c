#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/// Funciones de Vehiculo
struct Vehiculo{
    char color[25];
    int anio;
    int precio;
    char patente[9];
};

typedef struct Vehiculo * VehiculoPtr;

void cargarVehiculoParametros(VehiculoPtr v, char color[25], int anio, int precio, char patente[9]);
void mostrarVehiculo(VehiculoPtr v);
VehiculoPtr crearVehiculoVacio();


///Funciones de Persona
VehiculoPtr * crearVector(int t);

struct Persona{
    char nombre[25];
    int dni;
    VehiculoPtr * poseeVehiculo;
    int capVehiculos;
};

typedef struct Persona * PersonaPtr;

void cargarPersonaParametros(PersonaPtr p, char nombre[25], int dni, int capVehiculos);
void mostrarPersona(PersonaPtr p, int capVehiculos);
void ordernarVehiculosPorPrecio(PersonaPtr p);
VehiculoPtr buscarVehiculoPatente(PersonaPtr p, char patenteB[10]);

int main()
{




    ///DEFINICION E INICIALIZACION
    VehiculoPtr aux = malloc(sizeof(struct Vehiculo));
    VehiculoPtr fordFocus = malloc(sizeof(struct Vehiculo));
    cargarVehiculoParametros(fordFocus, "Azul", 2006, 3500000, "AB 123 CD");
    VehiculoPtr fiatUno = malloc(sizeof(struct Vehiculo));
    cargarVehiculoParametros(fiatUno, "Gris", 1995, 2000000, "AD 123 CD");
    VehiculoPtr fiatToro = malloc(sizeof(struct Vehiculo));
    cargarVehiculoParametros(fiatToro, "Rojo", 2017, 260000000, "AE 123 CD");

    PersonaPtr p1 = malloc(sizeof(struct Persona));
    p1->capVehiculos = 5;
    cargarPersonaParametros(p1, "Igna", 46940086, p1->capVehiculos);

    char patenteBuscar[10];
    ///PROCESO







    ///SALIDA

    mostrarVehiculo(fordFocus);
    p1->poseeVehiculo[0] = fordFocus;
    p1->poseeVehiculo[1] = fiatUno;
    p1->poseeVehiculo[2] = fiatToro;
    mostrarPersona(p1, p1->capVehiculos);

    printf("\n\n--Ordenador Por Precio--");
    ordernarVehiculosPorPrecio(p1);
    mostrarPersona(p1, p1->capVehiculos);

    strcpy(patenteBuscar, "AB 123 CD");
    printf("\n\n--Buscar por patente: %s", patenteBuscar);
    aux = buscarVehiculoPatente(p1, patenteBuscar);
    mostrarVehiculo(aux);

    strcpy(patenteBuscar, "ZW 456 BD");
    printf("\n\n--Buscar por patente: %s", patenteBuscar);
    aux = buscarVehiculoPatente(p1, patenteBuscar);
    mostrarVehiculo(aux);

    //Agregarle a la persona mas de 5 Vehiculos y comprobar que funcione
    printf("\n\n\n");
    p1->poseeVehiculo[3] = fordFocus;
    p1->poseeVehiculo[4] = fiatUno;

    free(p1->poseeVehiculo);
    free(p1);
    p1 = malloc(sizeof(struct Persona));
    p1->capVehiculos = 10;
    cargarPersonaParametros(p1, "Igna", 46940086, p1->capVehiculos);
    p1->poseeVehiculo[0] = fiatUno;
    mostrarPersona(p1, p1->capVehiculos);

    return 0;
}

///Funciones Vehiculo
void cargarVehiculoParametros(VehiculoPtr v, char color[25], int anio, int precio, char patente[9]){
    strcpy(v->color, color);
    v->anio = anio;
    v->precio = precio;
    strcpy(v->patente, patente);
};
void mostrarVehiculo(VehiculoPtr v){
    printf("\n\t---Vehiculo---");
    printf("\n\t\tcolor: %s", v->color);
    printf("\n\t\tanio: %d", v->anio);
    printf("\n\t\tprecio: %d", v->precio);
    printf("\n\t\tpatente: %s", v->patente);
};
VehiculoPtr crearVehiculoVacio(){
    VehiculoPtr v = malloc(sizeof(struct Vehiculo));
    strcpy(v->color, "VACIO");
    v->anio = -1;
    v->precio = -1;
    strcpy(v->patente, "VACIO");
    return v;
};
VehiculoPtr buscarVehiculoPatente(PersonaPtr p, char patenteB[10]){
    int patenteEncontrada = 0;
    int indicePatente = -1;
    for(int i = 0; i<5;i++){
        if (strcmp(p->poseeVehiculo[i]->patente, patenteB) == 0){
            patenteEncontrada = 1;
            indicePatente = i;
        }
    }
    VehiculoPtr buscado = malloc(sizeof(struct Vehiculo));
    if (patenteEncontrada == 1){
        buscado = p->poseeVehiculo[indicePatente];
    } else{
        cargarVehiculoParametros(buscado, "NO ENCONTRADO", 0, 0, "NO ENCONTRADO");
    }
    return buscado;
};


///Funciones Persona

VehiculoPtr * crearVector(int t){
    VehiculoPtr * pVector = malloc (t * (sizeof(VehiculoPtr)));
    return pVector;
};

void cargarPersonaParametros(PersonaPtr p, char nombre[25], int dni, int capVehiculos){
    strcpy(p->nombre, nombre);
    p->dni = dni;
    p->poseeVehiculo = crearVector(capVehiculos);
    for(int i = 0; i<capVehiculos;i++){
        p->poseeVehiculo[i] = crearVehiculoVacio();
    }
};
void mostrarPersona(PersonaPtr p, int capVehiculos){
    printf("\n---Persona---");
    printf("\nnombre: %s", p->nombre);
    printf("\ndni: %d", p->dni);
    for(int i = 0; i<capVehiculos;i++){
        if(p->poseeVehiculo[i]->anio != -1){
            mostrarVehiculo(p->poseeVehiculo[i]);
        }
    }
};
void ordernarVehiculosPorPrecio(PersonaPtr p){
    VehiculoPtr aux;
    for(int i = 0; i<5-1;i++){
        for(int j = 0; j<5-1; j++){
            if(p->poseeVehiculo[j]->precio < p->poseeVehiculo[j+1]->precio){
                aux = p->poseeVehiculo[j];
                p->poseeVehiculo[j] =  p->poseeVehiculo[j+1];
                p->poseeVehiculo[j+1] = aux;
            }
        }
    }
};

