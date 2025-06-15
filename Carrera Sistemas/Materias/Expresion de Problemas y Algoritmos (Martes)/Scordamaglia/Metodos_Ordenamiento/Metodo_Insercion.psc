Algoritmo Metodo_Ordenamiento_Insercion
	//Definiciones
	Definir vector Como Entero;
	Definir longVector Como Entero;
	Definir insert Como Entero;
	Definir i Como Entero;
	Definir j Como Entero;
	Definir n Como Entero;
	Definir aux Como Entero;
	Definir huboCambio Como Logico;
	
	//Inicializacion
	longVector <- 6;
	Dimension vector[longVector];
	Para i<-0 Hasta longVector-1 Hacer
		vector[i] <- Aleatorio(0,99);
	FinPara
	huboCambio <- Falso;
	
	//Salida sin Ordenar
	Escribir Sin Saltar "Vector sin ordenar: ";
	Para i<-0 Hasta longVector-1 Hacer
		si i=0 Entonces
			Escribir Sin Saltar "{";
		FinSi
		Escribir Sin Saltar vector[i], ", ";
		si i=longVector-1 Entonces
			Escribir "}";
		FinSi
	FinPara
	
	Escribir "Vector en Proceso de Ordenamiento: ";
	//Proceso 
	Para i<-0 Hasta longVector-2 Hacer
		//Ordenamiento
		si vector[i] > vector[i+1] Entonces
			aux<- vector[i+1];
			vector[i+1] <- vector[i];
			vector[i]<- aux;
			huboCambio<-Verdadero;
		FinSi
		insert<-i;
		Mientras (insert > 0) y huboCambio Hacer
			si vector[insert-1] > vector[insert] Entonces
				aux<- vector[insert];
				vector[insert] <- vector[insert-1];
				vector[insert-1]<- aux;
			FinSi
			insert <- insert-1;
		FinMientras
		
		//Salida demostrativa
		Escribir Sin Saltar "{";
		Para j<-0 hasta i+1 Hacer
			escribir Sin Saltar vector[j],  ", ";
		FinPara
		Escribir Sin Saltar "//";
		Para n<-j hasta longVector-1 Hacer
			escribir Sin Saltar vector[n],  ", ";
		FinPara
		Escribir "}";
		huboCambio <- Falso;
	FinPara
	
	//Salida Ordenada
	Escribir Sin Saltar"Vector Ordenado: ";
	Para i<-0 Hasta longVector-1 Hacer
		si i=0 Entonces
			Escribir Sin Saltar "{";
		FinSi
		Escribir Sin Saltar vector[i], ", ";
		si i=longVector-1 Entonces
			Escribir "}";
		FinSi
	FinPara
FinAlgoritmo
