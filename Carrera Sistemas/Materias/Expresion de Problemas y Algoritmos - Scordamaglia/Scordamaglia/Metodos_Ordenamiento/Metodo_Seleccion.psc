Algoritmo sin_titulo
	//Definicion
	Definir vector Como Entero;
	Definir long Como Entero;
	Definir i Como Entero;
	definir j Como Entero;
	Definir n Como Entero;
	Definir aux Como Entero;
	
	//Incializacion
	long<-6;
	Dimension vector[long];
	
	vector[0]<-4;
	vector[1]<-7;
	vector[2]<--3;
	vector[3]<-2;
	vector[4]<-1;
	vector[5]<-6;
	
	//escribimos el vector
	Escribir Sin Saltar "vector original: {";
	Para i<-0 Hasta long-1 Hacer
		si i<>long-1 Entonces
			Escribir Sin Saltar vector[i], ", ";
		SiNo
			Escribir vector[i], "}";
		FinSi
	FinPara
	Escribir "";

	//Ordenamiento
	Para i<-0 Hasta long-2 Hacer
		Para j<-1+i Hasta long-1 Hacer
			si vector[j] < vector[i] Entonces
				aux<-vector[i];
				vector[i]<- vector[j];
				vector[j]<-aux;
				Escribir "Cambio (", vector[j], ",", vector[i], ")";
			FinSi
		FinPara
		
		Escribir Sin Saltar "Vector dsp de la pasada ", i, ": {";
		Para n<-0 Hasta long-1 Hacer
			si n<>long-1 Entonces
				Escribir Sin Saltar vector[n], ",";
			SiNo
				Escribir vector[n], "}";
			FinSi
			si n=i Entonces
				Escribir Sin Saltar "||";
			FinSi
		FinPara
	FinPara
	
	
	//Salida
	Escribir "";
	Escribir Sin Saltar "vector ordenado ascendente por Selección: {";
	Para i<-0 Hasta long-1 Hacer
		si i<>long-1 Entonces
			Escribir Sin Saltar vector[i], ", ";
		SiNo
			Escribir vector[i], "}";
		FinSi
	FinPara
	
FinAlgoritmo
