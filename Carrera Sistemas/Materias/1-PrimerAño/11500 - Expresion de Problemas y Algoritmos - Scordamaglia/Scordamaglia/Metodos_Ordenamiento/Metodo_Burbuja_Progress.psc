Algoritmo Metodo_Ordenamiento_Burbuja
	//Definicion
	Definir vector Como Entero;
	Definir long Como Entero;
	definir i Como Entero;
	Definir j Como Entero;
	Definir n Como Entero;
	
	Definir contadorPasadas Como Entero;
	Definir aux Como Entero;
	Definir cambio Como Logico;
	
	//Inicialiazcion
	long<-50;
	Dimension vector[long];
	para i<-0 Hasta long-1 Hacer
		vector[i]<-Aleatorio(1,100);
	FinPara
	Escribir Sin Saltar "Vector Original: "; 
	
	para i<-0 Hasta long-1 Hacer //Lo escribimos
		si i<>long-1 Entonces
			Escribir Sin Saltar vector[i], " | ";
		SiNo
			Escribir vector[i];
		FinSi
	FinPara
	
	contadorPasadas<-1;
	i<-0;
	j<-1;
	cambio<-Verdadero;
	Escribir "";
	Escribir "Vector en Proceso de Ordenamiento: "; 
	Mientras cambio Hacer
		cambio<-Falso;
		Mientras (i<long-1) Hacer
			si vector[i] > vector[j] entonces 
				aux<-vector[i];
				vector[i]<-vector[j];
				vector[j]<-aux;
				cambio<-Verdadero;
			FinSi
			i<-i+1;
			j<-j+1;
		FinMientras
		
		Escribir Sin Saltar "Vector pasada ", contadorPasadas, " :"; 
		para n<-0 Hasta long-1 Hacer //Lo escribimos
			si n<>long-1 Entonces
				Escribir Sin Saltar vector[n], " | ";
			SiNo
				Escribir vector[n];
			FinSi
		FinPara
		contadorPasadas<- contadorPasadas+1;
		
		i<-0;
		j<-1;
	FinMientras
	Escribir "";
	
	Escribir Sin Saltar "Vector Ordenado: "; 
	para i<-0 Hasta long-1 Hacer //Lo escribimos
		si i<>long-1 Entonces
			Escribir Sin Saltar vector[i], " | ";
		SiNo
			Escribir vector[i];
		FinSi
	FinPara
FinAlgoritmo
