#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"
#include "funciones.h"

//Necesario
ListaPtr crearLista(){
    ListaPtr l = (ListaPtr) malloc(sizeof(struct Lista));
    l->primero = NULL;
    return l;
};

//Basicas
void mostrarLista(ListaPtr l){
    printf("--LISTA--\n");
    NodoPtr actual = l->primero;
    while(actual != NULL){
        mostrarNodo(actual);
        actual = actual->siguiente;
    }
    printf("\n");
};
void liberarLista(ListaPtr l){
    NodoPtr actual = l->primero;
    NodoPtr aux = actual;
    while(actual != NULL){
        aux = actual;
        actual = actual->siguiente;
        free(aux);
    }
    l->primero = NULL;
};
int obtenerTamano(ListaPtr l){
    int tam = 0;
    if(l->primero != NULL){
        NodoPtr actual = l->primero;
        while(actual != NULL){
            actual = actual->siguiente;
            tam++;
        }
    }
    return tam;
};
void printTamano(ListaPtr l){
    printf("Tamano Lista: %d\n", obtenerTamano(l));
};

//Insertar
void insertarPrimero(ListaPtr l, int dato){
    l->primero = crearNodo(dato, l->primero);
};
void insertarUltimo(ListaPtr l, int dato){
    NodoPtr actual = l->primero;
    if(actual == NULL){
        insertarPrimero(l, dato);
    } else{
        NodoPtr aux;
        while(actual != NULL){
            aux = actual;
            actual = actual->siguiente;
        };
        aux->siguiente = crearNodo(dato, NULL);
    }
};
void insertarPos(ListaPtr l, int dato, int posAInsertar){
    int tamLista = obtenerTamano(l);
    if((posAInsertar > tamLista) || (posAInsertar < 0)){
        printf("\nERROR: no se puede ingresar %d en una pos inexistente\n\n", dato);
    } else{
        if(posAInsertar == 0){
            insertarPrimero(l, dato);
        } else{
            if(posAInsertar == tamLista){
               insertarUltimo(l, dato);
           } else {
                NodoPtr actual = l->primero;
                for(int i = 0; i<posAInsertar-1; i++){
                    actual = actual->siguiente;
                }
                NodoPtr nodoInsertar = crearNodo(dato, actual->siguiente);
                actual->siguiente = nodoInsertar;
           }
        }
    }
};

void insertarAleatorioPos(ListaPtr l, int posAInsertar, int min, int max){
    int numRandom = generaraAleatorio(min, max);
    insertarPos(l, numRandom, posAInsertar);
};
//Eliminar
void eliminarPrimero(ListaPtr l){
    NodoPtr actual = l->primero;
    l->primero = actual->siguiente;
    free(actual);
};
void eliminarUltimo(ListaPtr l){
    NodoPtr actual = l->primero;
    int tamLista = obtenerTamano(l);
    for(int i = 0; i<tamLista-2; i++){
        actual = actual->siguiente;
    };
    free(actual->siguiente);
    actual->siguiente = NULL;
};
void eliminarPos(ListaPtr l, int posAELiminar){
    NodoPtr actual = l->primero;
    int tamLista = obtenerTamano(l);
    if((posAELiminar >= tamLista) || (posAELiminar < 0)){
        printf("\nERROR: no se puede eliminar en una pos inexistente\n\n");
    } else{
        if(posAELiminar == 0){
            eliminarPrimero(l);
        } else{
            for(int i = 0; i<posAELiminar-1; i++){
                actual = actual->siguiente;
            };
            NodoPtr aux = actual;
            actual = actual->siguiente;
            aux->siguiente = actual->siguiente;
            free(actual);
        };
    };
};

//Obtener
int obtenerPrimero(ListaPtr l){
    return l->primero->dato;
};
int obtenerUltimo(ListaPtr l){
    NodoPtr actual = l->primero;
    int tamLista = obtenerTamano(l);
    for(int i = 0; i<tamLista-1; i++){
        actual = actual->siguiente;
    }
    return actual->dato;
};
int obtenerPos(ListaPtr l, int pos){
    int tamLista = obtenerTamano(l);
    int dato;
    if((pos >= tamLista) || (pos < 0)){
        printf("\nERROR: no se puede obtener una pos inexistente\n\n");
        dato = -1;
    } else{
        if(pos == 0){
            dato = obtenerPrimero(l);
        } else{
            NodoPtr actual = l->primero;
            for(int i = 0; i<pos; i++){
                actual = actual->siguiente;
            }
            dato = actual->dato;
        }
    }
    return dato;
};
int obtenerMinimo(ListaPtr l){
    int tamLista = obtenerTamano(l);
    NodoPtr actual = l->primero;
    int minimo = actual->dato;
    for(int i = 0; i<tamLista-1;i++){
        actual = actual->siguiente;
        if(minimo > actual->dato){
            minimo = actual->dato;
        }
    }
    return minimo;
};
int obtenerMaximo(ListaPtr l){
    int tamLista = obtenerTamano(l);
    NodoPtr actual = l->primero;
    int maximo = actual->dato;
    for(int i = 0; i<tamLista-1;i++){
        actual = actual->siguiente;
        if(maximo < actual->dato){
            maximo = actual->dato;
        }
    }
    return maximo;
};

//Modificacion
void modificarPrimero(ListaPtr l, int datoCambio){
    l->primero->dato = datoCambio;
};
void modificarUltimo(ListaPtr l, int datoCambio){
    NodoPtr actual = l->primero;
    int tamLista = obtenerTamano(l);
    for(int i = 0; i<tamLista-1;i++){
        actual = actual->siguiente;
    };
    actual->dato = datoCambio;
};
void modificarPos(ListaPtr l, int posAModificar, int datoCambio){
    int tamLista = obtenerTamano(l);
    if(posAModificar >=0 && posAModificar<tamLista){
        NodoPtr actual = l->primero;
        for(int i = 0; i<posAModificar;i++){
            actual = actual->siguiente;
        };
        actual->dato = datoCambio;
    } else{
        printf("\nERROR: no se puede modificar una pos inexistente\n\n");
    }

};

//Utiles
void ordenarLista(ListaPtr l){
    NodoPtr actual = l->primero;
    int tamLista = obtenerTamano(l);
    NodoPtr aux = actual;
    for(int i = 0; i<tamLista;i++){
        for(int j = i+1; j<tamLista;j++){
            aux = aux->siguiente;
            if(aux->dato < actual->dato){
                int numAux = aux->dato;
                aux->dato = actual->dato;
                actual->dato = numAux;
            }
        }
        actual = actual->siguiente;
        aux = actual;
    }
};
void buscarElemento(ListaPtr l, int elementoBuscado){
    NodoPtr actual = l->primero;
    int tamLista = obtenerTamano(l);
    int encontrado = 0;
    int iElemento = -1;
    int i = 0;
    while((i<tamLista) && (!encontrado)){
        if(actual->dato == elementoBuscado){
            encontrado = 1;
            iElemento = i;
        }
        actual = actual->siguiente;
        i++;
    }
    if(encontrado == 1){
        printf("\tELemento encontrado en la pos: %d\n", iElemento);
    } else{
        printf("\tElemento no Encontrado en la lista\n");
    }
};
void busquedaBinariaElemento(ListaPtr l, int elementoBuscado){
    int numEncontrado = 0;
    int indice = -1;
    int tamLista = obtenerTamano(l);

    int derecha = tamLista-1;
    int izquierda = 0;

    while(!numEncontrado && (izquierda<=derecha)){
        int mitad = ((izquierda + derecha)/2);
        NodoPtr actual = l->primero;
        for(int i = 0; i<mitad;i++){
            actual = actual->siguiente;
        }
        if (actual->dato == elementoBuscado){
            numEncontrado = 1;
            indice = mitad;
        } else{
            if (elementoBuscado < actual->dato){
                derecha = mitad - 1;
            } else{
                izquierda = mitad + 1;
            }
        }
    }
    if(numEncontrado){
        printf("\n\tNum %d Encontrado en pos: %d\n", elementoBuscado, indice);
    }else{
        printf("\n\tNum %d NO Encontrado en la Lista\n", elementoBuscado);
    }
};

int estaVacia(ListaPtr l){
    int estaVacia = 0;
    if(l->primero == NULL){
        estaVacia = 1;
    }
    return estaVacia;
};
void printEstaVacia(ListaPtr l){
    int vacia = estaVacia(l);
    if(vacia == 1){
        printf("Esta Vacia: TRUE\n");
    } else{
        printf("Esta Vacia: FALSE\n");
    }

};

