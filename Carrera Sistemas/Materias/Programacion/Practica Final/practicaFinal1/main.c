#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Personaje{
    char nombre[100];
    char tipo[100];
    float altura;
};
struct Personaje crearPersonajeParametros(char nombre[100], char tipo[100], float altura);
void mostrarPersonaje(struct Personaje p);
struct Personaje crearPersonajeVacio();


struct Caricatura{
    char genero[100];
    char nombre[100];
    char paisOrigen[100];
    struct Personaje poseePersonajes[10];
};
struct Caricatura crearCaricaturaParametros(char genero[100], char nombre[100], char paisOrigen[100]);
void mostrarCaricatura(struct Caricatura c);
struct Caricatura ordenarPorAltura(struct Caricatura c);
struct Caricatura ordenarPorNombre(struct Caricatura c);

struct CanalInfantil{
    char nombre[100];
    char web[100];
    int anoCreacion;
    struct Caricatura poseeCaricaturas[100];
};
struct CanalInfantil crearCanalParametros(char nombre[100], char web[100], int anoCreacion);
void mostrarCanalInfantil(struct CanalInfantil ci);

int main()
{
    ///DEFINICIONES E INICIALIZACION
    struct CanalInfantil cartoonNetwork = crearCanalParametros("Cartoon Network", "www.cartoonnetwork.com", 1992);

    cartoonNetwork.poseeCaricaturas[0] = crearCaricaturaParametros("Serie de TV", "Plim Plim", "Argentina");
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[0] = crearPersonajeParametros("Arafa", "Jirafa", 3.55);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[1] = crearPersonajeParametros("Acuarella", "Conejo", 0.45);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[2] = crearPersonajeParametros("Mei-Li", "Gato", 0.65);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[3] = crearPersonajeParametros("Hoggie", "Cerdo", 1.12);
    cartoonNetwork.poseeCaricaturas[0].poseePersonajes[4] = crearPersonajeParametros("Wichiwi", "Pajaro", 0.22);

    cartoonNetwork.poseeCaricaturas[1] = crearCaricaturaParametros("Serie animada", "Bluey", "Australiana");
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[0] = crearPersonajeParametros("Bluey", "Cachorro", 0.95);
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[1] = crearPersonajeParametros("Bingo", "Cachorra", 0.45);
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[2] = crearPersonajeParametros("Bandit", "Perro", 1.23);
    cartoonNetwork.poseeCaricaturas[1].poseePersonajes[3] = crearPersonajeParametros("Chili", "Perra", 1.12);


    ///PROCESO



    ///SALIDA
    mostrarCanalInfantil(cartoonNetwork);

    return 0;
};

///PERSONAJE
struct Personaje crearPersonajeParametros(char nombre[100], char tipo[100], float altura){
    struct Personaje p;
    strcpy(p.nombre, nombre);
    strcpy(p.tipo, tipo);
    p.altura = altura;
    return p;
};
void mostrarPersonaje(struct Personaje p){
    printf("\n\t\t--PERSONAJE--");
    printf("\n\t\t\tNombre: %s", p.nombre);
    printf("\n\t\t\tTipo: %s", p.tipo);
    printf("\n\t\t\tAltura: %.2f", p.altura);
    printf("\n");
};
struct Personaje crearPersonajeVacio(){
    struct Personaje p = crearPersonajeParametros("VACIO", "VACIO", -1);
    return p;
};

///Caricatura
struct Caricatura crearCaricaturaParametros(char genero[100], char nombre[100], char paisOrigen[100]){
    struct Caricatura c;
    strcpy(c.genero, genero);
    strcpy(c.nombre, nombre);
    strcpy(c.paisOrigen, paisOrigen);
    for(int i = 0; i<10;i++){
        c.poseePersonajes[i] = crearPersonajeVacio();
    }
    return c;
};
void mostrarCaricatura(struct Caricatura c){
    printf("\n\t--CARICATURA--");
    printf("\n\t\tGenero: %s", c.genero);
    printf("\n\t\tNombre: %s", c.nombre);
    printf("\n\t\tPais de Origen: %s", c.paisOrigen);
    for(int i = 0; i<10;i++){
        if(c.poseePersonajes[i].altura != -1){
            mostrarPersonaje(c.poseePersonajes[i]);
        }
    }
    printf("\n");
};
struct Caricatura crearCaricaturaVacia(){
    struct Caricatura caricaturaVacia = crearCaricaturaParametros("VACIO", "VACIO", "VACIO");;
    return caricaturaVacia;
};
struct Caricatura ordenarPorAltura(struct Caricatura c){

};
struct Caricatura ordenarPorNombre(struct Caricatura c){

};

///CANAL
struct CanalInfantil crearCanalParametros(char nombre[100], char web[100], int anoCreacion){
    struct CanalInfantil canal;
    strcpy(canal.nombre, nombre);
    strcpy(canal.web, web);
    canal.anoCreacion = anoCreacion;
    for(int i = 0; i<100;i++){
        canal.poseeCaricaturas[i] = crearCaricaturaVacia();
    }
    return canal;
};
void mostrarCanalInfantil(struct CanalInfantil ci){
    printf("\n--CANAL--");
    printf("\n\tNombre: %s", ci.nombre);
    printf("\n\tWeb: %s", ci.web);
    printf("\n\tAno de Creacion: %d", ci.anoCreacion);
    for(int i = 0; i<100;i++){
        if(strcmp(ci.poseeCaricaturas[i].nombre, "VACIO")){
             mostrarCaricatura(ci.poseeCaricaturas[i]);
        }
    }
    printf("\n");
};
