#include <stdio.h>
#include <stdlib.h>

void brujeria(int n);
void brujeria2(int v[], int t);

int main(){
	int numero = 11; //(4 bytes)

	//& -> en que posicion esta la variable?
	printf("-> %d\n", numero);
	printf("-> %p\n", &numero);


	//1) * Definir un puntero
	//2) * Desreferenciacion
	int * puntero; //Un puntero es una flecha que indica una posicion
	puntero = &numero; //Puntero apunta a la direccion de memoria de numero

	printf("--> %p\n", puntero);
	printf("--> %d\n", *puntero);

	int numEj;
	//Las funciones adminten parametros = se pueden enviar por "valor" o REFERENCIA(&)
	brujeria(numEj); //le envia un valor basura
	printf("Brujeria 1:--> %d\n", numEj);

	int tam = 5;
	int v[tam];
	brujeria2(v, tam);
	printf("Brujeria 2:-->%d, %d, %d, %d, %d\n", v[0], v[1], v[2], v[3], v[4]);

	char palabra[4] = "abc";
    int * ipalabra = palabra; //Le esta diciendo que lo que hay en palabra es un int
    printf("Palabra como int: %d \n", *ipalabra);

	return 0;
}

void brujeria(int n){
	n = 101;
}
void brujeria2(int v[], int t){
	v[2] = 2;
}
