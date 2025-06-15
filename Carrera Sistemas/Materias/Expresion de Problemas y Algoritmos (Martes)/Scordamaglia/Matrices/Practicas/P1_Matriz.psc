Algoritmo sin_titulo
	//Definicion
	Definir matriz Como Entero;
	Definir filas Como Entero;
	Definir columnas Como Entero;	
	Definir f Como Entero;
	Definir c Como Entero;
	
	
	Definir vecParesEnFilas Como Entero;
	Definir vecImparesEnColumnas Como Entero;
	Definir i Como Entero;
	
	//Inicializacion
	filas <- 4;
	columnas <- 5;
	
	Dimension matriz[filas,columnas];
	Dimension vecParesEnFilas[filas];
	Dimension vecImparesEnColumnas[columnas];
	
	//Generar Matriz con Valores Aleatorios entre 0 y 10 
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			matriz[f,c]<-Aleatorio(0,10);
		FinPara
	FinPara
	
	//Escribir Matriz
	Escribir Sin Saltar "";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				si matriz[f,c] > 9 Entonces
					Escribir Sin Saltar matriz[f,c], " | ";
				SiNo
					Escribir Sin Saltar matriz[f,c], "  | ";
				FinSi
			SiNo
				Escribir matriz[f,c]; 
			FinSi
		FinPara
	FinPara
	Escribir "";
	
	//Proceso 
	//Inicializacion de vectores en 0
	Para i<-0 Hasta filas-1 Hacer
		vecParesEnFilas[i] <- 0;
	FinPara
	Para i<-0 Hasta columnas-1 Hacer
		vecImparesEnColumnas[i] <- 0;
	FinPara
	
	//Vector Pares en Filas
	Escribir Sin Saltar "Vector pares en Filas: ";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si (matriz[f,c] mod 2) = 0 Entonces
				vecParesEnFilas[f] <- vecParesEnFilas[f] + 1;
			FinSi
		FinPara
	FinPara
	Para i<-0 Hasta filas-1 Hacer
		si i <> filas-1 Entonces
			Escribir Sin Saltar vecParesEnFilas[i], " | ";
		SiNo
			Escribir Sin Saltar vecParesEnFilas[i];
		FinSi
	FinPara
	Escribir "";
	
	//Vector Impares en columnas
	Escribir Sin Saltar "Vector Impares en Columnas: ";
	Para c<-0 Hasta columnas-1 Hacer
		Para f<-0 Hasta filas-1 Hacer
			si (matriz[f,c] mod 2) = 0 Entonces
				vecImparesEnColumnas[c] <- vecImparesEnColumnas[f] + 1;
			FinSi
		FinPara
	FinPara
	Para i<-0 Hasta columnas-1 Hacer
		si i <> columnas-1 Entonces
			Escribir Sin Saltar vecImparesEnColumnas[i], " | ";
		SiNo
			Escribir Sin Saltar vecImparesEnColumnas[i];
		FinSi
	FinPara
	Escribir "";
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
FinAlgoritmo
