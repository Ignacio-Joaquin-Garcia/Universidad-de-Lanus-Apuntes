Algoritmo sin_titulo
//Definicion
	Definir vector Como Entero;
	Definir i,j,n Como Entero;
	Definir longVector, fInicializacion Como Entero;
	Definir aux como Entero;
	Definir cambio Como Logico;
	
//Inicializacion
	Escribir "Dimension del vector?";
	Leer longVector;
	Dimension vector[longVector];
	
	Escribir "1) Inicializar el vector por consola:";
	Escribir "2) Inicializar el vector con valores aleatorios en 0 y 9";
	Escribir Sin Saltar "Elegir la opción:";
	Leer fInicializacion;
	si fInicializacion = 1 Entonces
		Para i<-0 Hasta longVector-1 Hacer
			Escribir Sin Saltar"vector[", i, "]?";
			Leer vector[i];
		FinPara
	FinSi
	si fInicializacion = 2 Entonces
		Para i<-0 Hasta longVector-1 Hacer
			vector[i]<-Aleatorio(0,9);
		FinPara
	FinSi
	
	//Impresion vector Original
	Escribir "";
	Escribir "vector original:";
	Escribir Sin Saltar "{";
	Para i<-0 Hasta longVector-1 Hacer
		si i<>longVector-1 Entonces
			Escribir Sin Saltar vector[i], ",";
		SiNo
			Escribir vector[i], "}";
		FinSi
		si i=0 Entonces
			Escribir Sin Saltar "||";
		FinSi
	FinPara
	
	Para i<-1 Hasta longVector-1 Hacer
		Escribir "Elemento a insertar a la izquierda (ordenada): ", vector[i];
		j<-i;
		cambio<-Verdadero;
		Mientras (j>=1 y cambio) Hacer
			si vector[j-1] > vector[j] Entonces
				Escribir "Buscando inserción a la izquierda (ordenada) del elemento: ", vector[j];
				Escribir vector[j], " < ", vector[j-1], " Hay cambio (", vector[j], ",", vector[j-1], ")";
				aux<- vector[j];
				vector[j]<-vector[j-1];
				vector[j-1]<-aux;
				
			SiNo
				cambio<-Falso;
			FinSi
			j<-j-1;
		FinMientras
		//Imprimimos vector
		Escribir Sin Saltar "{";
		Para n<-0 Hasta longVector-1 Hacer
			Escribir Sin Saltar vector[n], ",";
			si n=i Entonces
				Escribir Sin Saltar "||";
			FinSi
		FinPara
		Escribir "}";
	FinPara
FinAlgoritmo
