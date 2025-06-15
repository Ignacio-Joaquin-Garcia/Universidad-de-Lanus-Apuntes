Algoritmo sin_titulo
	//Definicion
	Definir matriz Como Entero;
	Definir filas Como Entero;
	definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	
	Definir arregloM como entero;
	definir i Como Entero;
	definir j Como Entero;
	Definir aux Como Entero;
	
	//Inicializacion
	filas <- 5;
	columnas <- 5;
	
	Dimension matriz[filas,columnas];
	Dimension arregloM[(filas*columnas)];
	
	//Generamos matriz con valores aleatorios
	para f<-0 hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			matriz[f,c] <- Aleatorio(0,50);
		FinPara
	FinPara
	
	//Imprimimos matriz
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si (matriz[f,c] >= 10) y  c<>columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], " | ";
			sino
				si c<>columnas-1 Entonces
					Escribir Sin Saltar matriz[f,c], "  | ";
				SiNo
					Escribir matriz[f,c];
				FinSi
			FinSi
		FinPara
	FinPara
	
	
	//Proceso 
	//Transformar matriz a array
	i<-0;
	para f<-0 hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			arregloM[i] <- matriz[f,c];
			i<-i+1;
		FinPara
	FinPara
	//Imprimir array
	Escribir Sin Saltar "Array Transformado: ";
	Para i<-0 Hasta (filas*columnas)-1 Hacer
		si i<>((filas*columnas)-1) Entonces
			Escribir Sin Saltar arregloM[i], " | ";
		SiNo
			Escribir arregloM[i];
		FinSi
	FinPara
	
	//Ordenando al Array Matriz mediante metodo insercion
	Para i<-0 Hasta (filas*columnas)-2 Hacer
		Para j<-1 Hasta (filas*columnas)-1 Hacer
			si (arregloM[j-1] > arregloM[j]) Entonces
				aux<- arregloM[j-1];
				arregloM[j-1]<-arregloM[j];
				arregloM[j]<-aux;
			FinSi
		FinPara
	FinPara
	Escribir Sin Saltar "Array Ordenado: ";
	Para i<-0 Hasta (filas*columnas)-1 Hacer
		si i<>((filas*columnas)-1) Entonces
			Escribir Sin Saltar arregloM[i], " | ";
		SiNo
			Escribir arregloM[i];
		FinSi
	FinPara
	
	//Recreamos devuelta la Matriz
	i<-0;
	para f<-0 hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			matriz[f,c] <- arregloM[i];
			i<-i+1;
		FinPara
	FinPara
	//Imprimimos matriz ordenada
	Escribir "Matriz Ordenada: ";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si (matriz[f,c] >= 10) y  c<>columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], " | ";
			sino
				si c<>columnas-1 Entonces
					Escribir Sin Saltar matriz[f,c], "  | ";
				SiNo
					Escribir matriz[f,c];
				FinSi
			FinSi
		FinPara
	FinPara
	
	
FinAlgoritmo
