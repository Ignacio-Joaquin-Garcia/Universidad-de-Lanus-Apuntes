Algoritmo sin_titulo
	//Definicion
	Definir matriz Como Entero;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	
	//Inicializacion
	filas <- 2;
	columnas <- 10;
	Dimension matriz[filas, columnas];
	
	//Iniciamos valores de la matriz 
	para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			matriz[f,c] <- Aleatorio(0,10);
		FinPara
	FinPara
	
	//Mostramos la Matriz
	Escribir "Matriz Original";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				si matriz[f,c] >= 10 Entonces
					Escribir Sin Saltar matriz[f,c], " |  ";
				SiNo
					Escribir Sin Saltar matriz[f,c], "  |  ";
				FinSi
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Proceso 
	//Setear ambos valores a 0 en matriz si son iguales
	Para c<-0 Hasta columnas-1 Hacer
		si matriz[0,c] = matriz[1,c] Entonces
			matriz[0,c]<-0;
			matriz[1,c]<-0;
		FinSi
	FinPara
	//Mostramos Matriz
	Escribir "";
	Escribir "Matriz con valores cambiados";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				si matriz[f,c] >= 10 Entonces
					Escribir Sin Saltar matriz[f,c], " |  ";
				SiNo
					Escribir Sin Saltar matriz[f,c], "  |  ";
				FinSi
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
FinAlgoritmo
