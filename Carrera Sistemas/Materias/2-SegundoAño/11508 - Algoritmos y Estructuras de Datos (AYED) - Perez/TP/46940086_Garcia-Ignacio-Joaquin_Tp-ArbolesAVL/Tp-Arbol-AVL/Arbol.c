#include <stdio.h>
#include <stdlib.h>

#include "Arbol.h"

struct Nodo{
    NodoPtr izquierda;
    NodoPtr derecha;
    DatoPtr dato;
};

NodoPtr crearNodo(DatoPtr dato){
    NodoPtr n = (NodoPtr) malloc(sizeof(struct Nodo));

    if(dato != NULL){
         n->dato = dato;
    }
    n->derecha = NULL;
    n->izquierda = NULL;

    return n;
};

void liberarNodo(NodoPtr nodo){
    free(nodo->dato);
    free(nodo);
}


void insertarArbol(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(nodo == NULL){
        nodo = crearNodo(dato);
        return;
    }

    if(busquedaGenerico(nodo->dato, dato) < 0){
        if(nodo->izquierda == NULL){
            nodo->izquierda = crearNodo(dato);
        } else{
            insertarArbol(nodo->izquierda, dato, busquedaGenerico);
        }
    } else{
        if(nodo->derecha == NULL){
            nodo->derecha = crearNodo(dato);
        } else{
            insertarArbol(nodo->derecha, dato, busquedaGenerico);
        }
    }
};

void mostrarArbolPreorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarNodoGenerico(nodo->dato);
        printf("\n");
        mostrarArbolPreorden(nodo->izquierda, mostrarNodoGenerico);
        mostrarArbolPreorden(nodo->derecha, mostrarNodoGenerico);
    };
};
void mostrarArbolInorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarArbolInorden(nodo->izquierda, mostrarNodoGenerico);
        mostrarNodoGenerico(nodo->dato);
        printf("\n");
        mostrarArbolInorden(nodo->derecha, mostrarNodoGenerico);
    };
};
void mostrarArbolPostorden(NodoPtr nodo, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarArbolPostorden(nodo->izquierda, mostrarNodoGenerico);
        mostrarArbolPostorden(nodo->derecha, mostrarNodoGenerico);
        mostrarNodoGenerico(nodo->dato);
        printf("\n");
    };
};
void mostrarArbolAcostado(NodoPtr nodo, int nivel, void (*mostrarNodoGenerico)(DatoPtr)){
    if(nodo != NULL){
        mostrarArbolAcostado(nodo->derecha, nivel + 1, mostrarNodoGenerico);
        for(int i = 0; i < nivel; i++){
            printf("\t\t");
        }
        mostrarNodoGenerico(nodo->dato);
        printf("\n");
        mostrarArbolAcostado(nodo->izquierda, nivel + 1, mostrarNodoGenerico);
    }
}


NodoPtr buscarBinario(NodoPtr nodo, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(nodo == NULL){ return NULL; };
    if(busquedaGenerico(nodo->dato, dato) == 0){
        return nodo;
    } else{
        if(busquedaGenerico(nodo->dato, dato) < 0){
            return buscarBinario(nodo->izquierda, dato, busquedaGenerico);
        } else{
            return buscarBinario(nodo->derecha, dato, busquedaGenerico);
        }
    }
};

NodoPtr eliminarDatoArbol(NodoPtr arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(arbol == NULL){
        printf("El Dato no existe en el arbol!\n");
        return NULL;
    }
    int rta = busquedaGenerico(arbol->dato, dato);

    // buscar izquierda
    if(rta < 0){
        arbol->izquierda = eliminarDatoArbol(arbol->izquierda, dato, busquedaGenerico);
        return arbol;
    }
    // buscar derecha
    if(rta > 0){
        arbol->derecha = eliminarDatoArbol(arbol->derecha, dato, busquedaGenerico);
        return arbol;
    }

    // ENCONTRADO
    int cantHijos = contador2Hijos(arbol);
    switch(cantHijos){
        case 0:{
            liberarNodo(arbol);
            return NULL;
        }
        case 1:{
            if(arbol->izquierda != NULL){
                NodoPtr aux = arbol->izquierda;
                liberarNodo(arbol);
                return aux;
            } else{
                NodoPtr aux = arbol->derecha;
                liberarNodo(arbol);
                return aux;
            }
        }
        case 2:{
            NodoPtr menor = buscarMenorMayores(arbol);

            //Cambio de Punteros a los datos para correcta liberacion de memoria
            DatoPtr aux = arbol->dato;
            arbol->dato = menor->dato;
            menor->dato = aux;

            arbol->derecha = eliminarDatoArbol(arbol->derecha, menor->dato, busquedaGenerico);
            return arbol;
        }
    }
    return arbol;
};
int contador2Hijos(NodoPtr arbol){
    if(arbol == NULL){
        return -1;
    }
    int hijos = 0;
    if(arbol->izquierda != NULL){
        hijos++;
    }
    if(arbol->derecha != NULL){
        hijos++;
    }
    return hijos;
}
NodoPtr buscarMenorMayores(NodoPtr arbol){
    if(arbol == NULL || arbol->derecha == NULL){
        return NULL;
    }
    NodoPtr actual = arbol->derecha;
    while(actual->izquierda != NULL){
        actual = actual->izquierda;
    }
    return actual;
 }

///Arboles AVL
int alturaArbol(NodoPtr arbol){
    int alturaIzq = 0;
    int alturaDer = 0;

    if(arbol == NULL){ return 0; };

    alturaIzq = alturaArbol(arbol->izquierda);
    alturaDer = alturaArbol(arbol->derecha);

    if (alturaDer > alturaIzq){
        return alturaDer + 1; }
    else{
        return alturaIzq + 1;
    }

};
int balanceo(NodoPtr arbol){
    int altura = 0;
    if(arbol == NULL){ return 0; }
    altura = alturaArbol(arbol->derecha) - alturaArbol(arbol->izquierda);
    return altura;
};
int rotarDer(NodoPtr * arbol){
    NodoPtr auxiliar = NULL;
    NodoPtr raiz = NULL;
    NodoPtr raizNueva = NULL;

    if(arbol == NULL || *arbol == NULL || (*arbol)->izquierda == NULL){ return 0; };

    raiz = (*arbol);
    raizNueva = (*arbol) -> izquierda;
    auxiliar = (*arbol) -> izquierda -> derecha;

    (*arbol) = raizNueva;
    raizNueva -> derecha = raiz;
    raiz -> izquierda = auxiliar;
    return 1;
};
int rotarIzq(NodoPtr * arbol){
    NodoPtr auxiliar = NULL;
    NodoPtr raiz = NULL;
    NodoPtr raizNueva = NULL;

    if(arbol == NULL || *arbol == NULL || (*arbol)->derecha == NULL){ return 0; };

    raiz = *arbol;
    raizNueva = (*arbol) -> derecha;
    auxiliar = (*arbol) -> derecha -> izquierda;

    *arbol = raizNueva;
    (*arbol) -> izquierda = raiz;
    raiz -> derecha = auxiliar;

    return 1;
};
int reOrdenar(NodoPtr * arbol, NodoPtr * auxArbol){
    if ((*arbol)->derecha == NULL){
        (*auxArbol)->dato = (*arbol)->dato;
        *arbol = (*arbol)->izquierda;
    }else
        reOrdenar(&(*arbol)->derecha, auxArbol);
    return 1;
};
void balancearArbol(NodoPtr * arbol){
    int auxBalance = 0;
    if(arbol == NULL || *arbol == NULL){ return; };
    auxBalance = balanceo(*arbol);
    if(auxBalance > 1){
        if(balanceo((*arbol)->derecha) >= 1){
            rotarIzq(arbol);
        }
        else{
            rotarDer(&((*arbol)->derecha));
            rotarIzq(arbol);
        }
    }
    else if(auxBalance < -1){
        if(balanceo((*arbol)->izquierda) <= -1){
            rotarDer(arbol);
        }
        else{
            rotarIzq(&((*arbol)->izquierda));
            rotarDer(arbol);
        }
    }
};

void insertarArbolBalanceado(NodoPtr *arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if (*arbol == NULL) {
        *arbol = (NodoPtr) malloc(sizeof(struct Nodo));
        if (*arbol == NULL){ return; }
        (*arbol)->dato      = dato;
        (*arbol)->izquierda = NULL;
        (*arbol)->derecha   = NULL;
        return;
    }

    if (busquedaGenerico((*arbol)->dato, dato) < 0) {
        insertarArbolBalanceado(&((*arbol)->izquierda), dato, busquedaGenerico);
    } else {
        insertarArbolBalanceado(&((*arbol)->derecha), dato, busquedaGenerico);
    }
    balancearArbol(arbol);
}
NodoPtr eliminarDatoArbolBalanceado(NodoPtr arbol, DatoPtr dato, int (*busquedaGenerico)(DatoPtr, DatoPtr)){
    if(arbol == NULL){
        printf("El Dato no existe en el arbol!\n");
        return NULL;
    }
    int rta = busquedaGenerico(arbol->dato, dato);

    // buscar izquierda
    if(rta < 0){
        arbol->izquierda = eliminarDatoArbolBalanceado(arbol->izquierda, dato, busquedaGenerico);
        return arbol;
    }
    // buscar derecha
    if(rta > 0){
        arbol->derecha = eliminarDatoArbolBalanceado(arbol->derecha, dato, busquedaGenerico);
        return arbol;
    }

    // ENCONTRADO
    int cantHijos = contador2Hijos(arbol);
    switch(cantHijos){
        case 0:{
            liberarNodo(arbol);
            return NULL;
        }
        case 1:{
            if(arbol->izquierda != NULL){
                NodoPtr aux = arbol->izquierda;
                liberarNodo(arbol);
                return aux;
            } else{
                NodoPtr aux = arbol->derecha;
                liberarNodo(arbol);
                return aux;
            }
        }
        case 2:{
            NodoPtr menor = buscarMenorMayores(arbol);

            //Cambio de Punteros a los datos para correcta liberacion de memoria
            DatoPtr aux = arbol->dato;
            arbol->dato = menor->dato;
            menor->dato = aux;

            arbol->derecha = eliminarDatoArbolBalanceado(arbol->derecha, menor->dato, busquedaGenerico);
        }
    }
    balancearArbol(&arbol);
    return arbol;
}
//Metricas Arboles
int obtenerPeso(NodoPtr arbol){
    if(arbol == NULL){
        return 0;
    }

    int pesoIzq = obtenerPeso(arbol->izquierda);
    int pesoDer = obtenerPeso(arbol->derecha);

    return pesoIzq + pesoDer + 1;
};
int obtenerCantidadTotalHojas(NodoPtr arbol){
    if(arbol == NULL){ return 0; };
    if(arbol->izquierda == NULL && arbol->derecha == NULL){
        return 1;
    }
    int hojasIzq = obtenerCantidadTotalHojas(arbol->izquierda);
    int hojasDer = obtenerCantidadTotalHojas(arbol->derecha);

    return hojasIzq + hojasDer;
};
int obtenerNivel(NodoPtr arbol, NodoPtr nodoNivel){
    if(arbol == NULL){
        return -1;
    }
    if(arbol == nodoNivel){
        return 0;
    }
    int nivel = obtenerNivel(arbol->izquierda, nodoNivel);

    if(nivel != -1){
        return nivel + 1;
    }
    nivel = obtenerNivel(arbol->derecha, nodoNivel);
    if(nivel != -1){
        return nivel + 1;
    }
    return -1;
};
NodoPtr obtenerMinNodo(NodoPtr arbol){
    if(arbol->izquierda == NULL){
        return arbol;
    } else{
        return obtenerMinNodo(arbol->izquierda);
    }
};
NodoPtr obtenerMaxNodo(NodoPtr arbol){
    if(arbol->derecha == NULL){
        return arbol;
    } else{
        return obtenerMaxNodo(arbol->derecha);
    }
};





///Getters
DatoPtr getDato(NodoPtr nodo){
    return nodo->dato;
};
NodoPtr getIzquierda(NodoPtr nodo){
    return nodo->izquierda;
};
NodoPtr getDerecha(NodoPtr nodo){
    return nodo->derecha;
};
///Setters
void setDato(NodoPtr nodo, DatoPtr dato){
    nodo->dato = dato;
};
void setIzquierda(NodoPtr nodoCambio, NodoPtr nodo){
    nodoCambio->izquierda = nodo;
};
void setDerecha(NodoPtr nodoCambio, NodoPtr nodo){
    nodoCambio->derecha = nodo;
};
