Algoritmo Metodo_Ordenamiento_Shell
	//Definicion
	Definir vector Como Entero;
	Definir longVector Como Entero;
	Definir i Como Entero;
	Definir j Como Entero;
	definir n Como Entero;
	definir salto Como Entero;
	Definir mitadVector Como Entero;
	definir cambio Como Logico;
	definir aux Como Entero;
	
	//Inicializacion
	longVector <- 6;
	Dimension vector[longVector];
	Escribir Sin Saltar "Vector sin Modificar: {";
	Para i<-0 Hasta longVector-1 Hacer
		vector[i] <- Aleatorio(0,99);
		Escribir Sin Saltar vector[i], ", ";
	FinPara
	Escribir "}";
	
	//Proceso 
	salto <- trunc(longVector / 2);
	i<-0;
	Mientras (i < (longVector - salto)) y (salto <> 0) Hacer
		cambio <- Falso;
		Para j<-0 hasta (longVector - salto)-1 Hacer
			si (vector[j]) > (vector[j+salto]) Entonces
				aux <- vector[j+salto];
				vector[j+salto] <- vector[j];
				vector[j] <- aux;
				cambio <- Verdadero;
			FinSi
			Escribir Sin Saltar "Vector Modificado: {";
			Para n<-0 Hasta longVector-1 Hacer
				Escribir Sin Saltar vector[n], ", ";
			FinPara
			Escribir "}";
		FinPara
		si cambio = Falso Entonces
			salto <- trunc(salto / 2);
		FinSi
		i<-i+1;
	FinMientras

	//Salida
	Escribir Sin Saltar "{";
	Para i<-0 Hasta longVector-1 Hacer
		Escribir Sin Saltar vector[i], ", ";
	FinPara
	Escribir "}";
FinAlgoritmo
