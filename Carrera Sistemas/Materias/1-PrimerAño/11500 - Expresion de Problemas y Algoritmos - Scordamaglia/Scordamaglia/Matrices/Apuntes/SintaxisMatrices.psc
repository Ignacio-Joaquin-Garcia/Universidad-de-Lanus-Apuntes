Algoritmo Sintaxis_Matrices
	Definir matriz como Entero;
	Definir i como Entero;
	Definir j como Entero;
	Definir filas como Entero;	
	Definir columnas como Entero;	
	//Pendiente dimensionar matriz por consola
	filas <- 4;
	columnas <- 5;
	
	//Dimensionar matriz
	Dimension matriz[filas, columnas];
	
	//CARGA DE LA MATRIZ con valores aleatorios entre 0 y 9
	Para i <- 0 Hasta filas-1 Con paso 1
		Para j <- 0 Hasta columnas-1 Con paso 1
			matriz[i, j] <- Aleatorio(0, 9);
		FinPara
	FinPara
	
	//SALIDA
	Para i <- 0 Hasta filas-1 Con paso 1
		Para j <- 0 Hasta columnas-1 Con paso 1
			Si j < (columnas-1)
				Escribir Sin Saltar matriz[i,j], "   ";
			SiNo
				Escribir matriz[i,j];
			FinSi
		FinPara
	FinPara
	
	
FinAlgoritmo

