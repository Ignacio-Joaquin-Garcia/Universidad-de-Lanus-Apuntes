Algoritmo sin_titulo
//Definiciones
	definir matriz Como Entero;
	Definir filas, columnas, f ,c Como Entero;
	Definir acum, promedio Como Entero;
	Definir indice, minNumber Como Entero;
	Definir aux Como Entero;
//Inicializacion
	Escribir "Ingrese cantidad filas de la matriz:";
	Leer filas;
	Escribir "Ingrese cantidad columnas de la matriz:";
	Leer columnas;
	
	Dimension matriz[filas,columnas];
	
	//Generamos matriz con numeros aleatorios 
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			matriz[f,c]<-Aleatorio(0,9);
		FinPara
	FinPara
	
	//Mostramos matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			si c<>columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], " | ";
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Proceso 
	Para f<-0 Hasta filas-1 Hacer
		minNumber<-1000000;
		indice<-0;
		acum<-0;
		para c<-0 Hasta columnas-1 Hacer
			acum <-acum + matriz[f,c];
			si matriz[f,c] < minNumber Entonces
				minNumber <- matriz[f,c];
				indice<-c;
			FinSi
		FinPara
		promedio<-trunc(acum/c);
		Escribir "El promedio de la fila ", f, " es de: ", promedio;
		
		Escribir "El menor numero de la fila ", f, " es ", minNumber, " en el indice ", indice;  
	FinPara
	
	//Intercambiamos la ultimas columnas por la primer columna
	c<-0;
	Para f<-0 Hasta columnas-1 Hacer
		aux <- matriz[f,columnas-1];
		matriz[f,columnas-1] <- matriz[f,c];
		matriz[f,c] <- aux;
	FinPara

	//Mostramos matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			si c<>columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], " | ";
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	
FinAlgoritmo
