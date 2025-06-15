Algoritmo sin_titulo
	//Definiciones
	Definir matriz Como Entero;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	
	Definir sol Como Entero;
	Definir luna Como entero;
	Definir resultado Como entero;
	Definir vectorPromedio Como entero;
	Definir sumaT Como Entero;
	Definir acum Como Entero;
	
	Definir numEncontrado Como Logico;
	
	//Inicializacion
	filas<-5;
	columnas<-5;
	Dimension matriz[filas,columnas];
	Dimension vectorPromedio[columnas];
	
	//Creacion de valores matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			matriz[f,c]<-(f+c)^4;
		FinPara
	FinPara
	
	//Imprimimos matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			si c=(columnas-1) Entonces
				Escribir matriz[f,c];
			SiNo
				si matriz[f,c]<10 Entonces
					Escribir Sin Saltar matriz[f,c], "    | ";
				FinSi
				si matriz[f,c]>=10 y matriz[f,c]<100 Entonces
					Escribir Sin Saltar matriz[f,c], "   | ";
				FinSi
				si matriz[f,c]>=100 y matriz[f,c]<1000 Entonces
					Escribir Sin Saltar matriz[f,c], "  | ";
				FinSi
				si matriz[f,c]>=1000 Entonces
					Escribir Sin Saltar matriz[f,c], " | ";
				FinSi
			FinSi
		FinPara
	FinPara
	
	//Recorremos matriz para encontrar sol(mayorNumero)
	sol<-0;
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			si matriz[f,c] > sol Entonces
				sol<-matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Proceso para encontrar la luna
	sumaT<-0;
	acum<-0;
	Para c<-0 Hasta columnas-1 Hacer //Promedio por columnas
		para f<-0 Hasta filas-1 Hacer
			sumaT<-sumaT+matriz[f,c];
			acum<-acum+1;
		FinPara
		vectorPromedio[c]<- trunc(sumaT/acum);
		sumaT<-0;
		acum<-0;
	FinPara
	
	Escribir "";
	Escribir Sin Saltar "Vector Promedio: ";
	Para c<-0 Hasta columnas-1 Hacer //Escribimos vector promedio
		Escribir Sin Saltar vectorPromedio[c] "    ";
	FinPara
	Escribir "";
	
	//encontramos primer numero de 3 cifras en vectorPromedio
	c<-0;
	numEncontrado<-Falso;
	Mientras (c<columnas-1) y NO(numEncontrado) Hacer 
		si vectorPromedio[c] >=100
			numEncontrado <- Verdadero;
			luna <- vectorPromedio[c];
		FinSi
		c<-c+1;
	FinMientras
	
	//Salida
	Escribir "Sol: ", sol;
	Escribir "Luna: ", luna;
	
	resultado<-sol-luna;
	Escribir "Resultado: ", resultado;
FinAlgoritmo
