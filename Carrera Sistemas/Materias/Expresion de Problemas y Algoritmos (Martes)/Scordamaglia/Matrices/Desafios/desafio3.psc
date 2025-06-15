Algoritmo sin_titulo
	//Definicion
	Definir matriz Como Entero;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	
	Definir acum Como Entero;
	Definir cambioDireccion como logico;
	
	Definir sumaNPares Como Entero;
	Definir sumaNImpares Como Entero;
	Definir resultado Como Entero;
	
	//Inicializacion
	filas<-7;
	columnas<-7;
	
	Dimension matriz[filas, columnas];
	
	//Generamos valores de la matriz
	cambioDireccion<-Falso;
	acum<-0;
	Para f<-0 Hasta filas-1 Hacer
		//Declaramos un cambio de direccion para movimiento de columnas estilo serpiente
		si cambioDireccion Entonces
			cambioDireccion<-Falso;
		SiNo
			cambioDireccion<-Verdadero;
		FinSi
		c<-0;
		Mientras (cambioDireccion) y (c<columnas) Hacer
			acum<-acum+1;
			matriz[f,c]<-acum;
			c<-c+1;
		FinMientras
		c<-columnas-1;
		Mientras NO(cambioDireccion) y (c>=0) Hacer
			acum<-acum+1;
			matriz[f,c]<-acum;
			c<-c-1;
		FinMientras
	FinPara
	
	//Escribimos Matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				si matriz[f,c] < 10 Entonces
					Escribir Sin Saltar matriz[f,c], "  | ";
				SiNo
					Escribir Sin Saltar matriz[f,c], " | ";
				FinSi
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Proceso 
	//Suma de numero pares en la matriz e impares
	sumaNPares<-0;
	sumaNImpares<-0;
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 Hasta columnas-1 Hacer
			si (c mod 2) = 0 Entonces
				sumaNPares<-sumaNPares+matriz[f,c];
			SiNo
				sumaNImpares<-sumaNImpares+matriz[f,c];
			FinSi
		FinPara
	FinPara
	//Calculo codigo secreto
	resultado<-sumaNPares-sumaNImpares;
	//Salida
	Escribir "El resultado es: ", resultado;
FinAlgoritmo
