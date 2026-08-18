Algoritmo sin_titulo
	//Definicion
	Definir vector Como Entero;
	Definir long Como Entero;
	Definir i Como Entero;
	definir j Como Entero;
	Definir n Como Entero;
	Definir aux Como Entero;
	Definir salto Como Entero;
	Definir cambio Como Logico;
	
	//Incializacion
	long<-7;
	Dimension vector[long];
	
	vector[0]<-2;
	vector[1]<-6;
	vector[2]<-3;
	vector[3]<-8;
	vector[4]<-6;
	vector[5]<-2;
	vector[6]<-0;
	
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
	salto<-trunc(long/2);
	Escribir "salto: ", salto;
	
	j<-0;
	Mientras salto<>0 Hacer
		cambio<-Verdadero;
		Mientras cambio Hacer
			cambio<-Falso;
			i<-0;
			Mientras (i< (long-salto)) Hacer
				si vector[i] > vector[i+salto] Entonces
					Escribir vector[i], ">", vector[i+salto], "Si entonces Cambio (", vector[i], ",",vector[i+salto] ,")";
				SiNo
					Escribir vector[i], ">", vector[i+salto], " No";
				FinSi

				si vector[i+salto] < vector[i] Entonces
					aux<-vector[i];
					vector[i]<- vector[i+salto];
					vector[i+salto]<-aux;
					cambio<-Verdadero;
				FinSi
				i<-i+1;
			FinMientras
			
			//Imprimimos vector
			Escribir Sin Saltar "vector pasada ", j, ": {";
			Para n<-0 Hasta long-1 Hacer
				si n<>long-1 Entonces
					Escribir Sin Saltar vector[n], ", ";
				SiNo
					Escribir vector[n], "}";
				FinSi
			FinPara
			Escribir "salto: ", salto;
			Escribir "";
		FinMientras
		salto<-trunc(salto/2);
		Escribir "salto: ", salto;
		j<-j+1;
	FinMientras
	
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




