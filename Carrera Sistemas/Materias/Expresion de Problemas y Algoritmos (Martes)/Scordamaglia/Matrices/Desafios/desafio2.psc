Algoritmo sin_titulo
	//Definicion
	definir matriz Como Entero;
	Definir filas como Entero;
	Definir columnas Como Entero;
	Definir f como Entero;
	Definir c Como Entero;
	
	Definir dia Como Entero;
	Definir acumDia Como Entero;
	
	Definir matrixAux Como Entero;
	Definir vectorSumaPorFila Como Entero;
	
	//Inicializacion
	filas<-5;
	columnas<-7;
	Dimension matriz[filas,columnas];
	Dimension matrixAux[filas,columnas];
	Dimension vectorSumaPorFila[filas];
	
	
	//Generacion Matriz
	dia<-0;
	acumDia<-0;
	Para f<-0 hasta filas-1 Hacer
		para c<-0 hasta columnas-1 Hacer
			si (f=0 y (c>=0) y c<=1) Entonces
				matriz[f,c] <- 0;
			SiNo
				si (f=4 y (c>=5) y c<=6) Entonces
					matriz[f,c] <- 0;
				SiNo
					dia<-dia+1;
					acumDia<- acumDia+dia;
					matriz[f,c] <- acumDia;
				FinSi
			FinSi
		FinPara
	FinPara
	
	//Escribimos matriz
	Para f<-0 hasta filas-1 Hacer
		para c<-0 hasta columnas-1 Hacer
			si c<>columnas-1 Entonces
				si matriz[f,c] <10 Entonces
					Escribir Sin Saltar matriz[f,c], "    | ";
				FinSi
				si (matriz[f,c] >= 10) y (matriz[f,c] < 100) Entonces
					Escribir Sin Saltar matriz[f,c], "   | ";
				FinSi
				si (matriz[f,c] >= 100) y (matriz[f,c] < 1000) Entonces
					Escribir Sin Saltar matriz[f,c], "  | ";
				FinSi
				si (matriz[f,c] >= 1000) y (matriz[f,c] < 10000) Entonces
					Escribir Sin Saltar matriz[f,c], " | ";
				FinSi
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Generamos Matrix Auxiliar con 1 donde el num de Matrix sea multiplo de 2 y de 3
	Para f<-0 hasta filas-1 Hacer
		para c<-0 hasta columnas-1 Hacer
			si matriz[f,c]=0 Entonces
				matrixAux[f,c]<-0;
			sino
				si ((matriz[f,c] mod 2) = 0) y ((matriz[f,c] mod 3) = 0) Entonces
					matrixAux[f,c]<-1;
				SiNo
					matrixAux[f,c]<-0;
				FinSi
			FinSi
		FinPara
	FinPara
	
	//Imprimir matrix Auxiliar
	Escribir "";
	Escribir "Matrix Auxiliar: ";
	Para f<-0 hasta filas-1 Hacer
		para c<-0 hasta columnas-1 Hacer
			si c<>columnas-1 Entonces
				Escribir Sin Saltar matrixAux[f,c], " | ";
			SiNo
				Escribir matrixAux[f,c];
			FinSi
		FinPara
	FinPara
	
	//Generamos Vector Resultados
	Para f<-0 hasta filas-1 Hacer
		vectorSumaPorFila[f]<-0;
		para c<-0 hasta columnas-1 Hacer
			vectorSumaPorFila[f]<-vectorSumaPorFila[f] + matrixAux[f,c];
		FinPara
	FinPara
	//Imprimimos vector
	Escribir "";
	Escribir Sin Saltar "Codigo Secreto: ";
	Para f<-0 hasta filas-1 Hacer
		Escribir Sin Saltar vectorSumaPorFila[f];
	FinPara
	Escribir "";
FinAlgoritmo
