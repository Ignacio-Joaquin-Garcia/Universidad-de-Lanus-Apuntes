Algoritmo Ejemplo_Parcial1
	//Definiciones
	Definir vector Como Entero;
	Definir vectorMaPromedio Como Entero;
	Definir vectorMultiplicado Como Entero;
	Definir longitudVector Como Entero;
	Definir i Como Entero;
	Definir acumulador Como Entero;
	Definir promedio Como Entero;
	Definir valorBuscado Como Entero;
	Definir valorEncontrado Como Logico;
	
	//Inicializacion
	Escribir Sin Saltar"Ingrese longitud del Vector Aleatorio: ";
	Leer longitudVector;
	
	//Dimension Vectores
	Dimension vector[longitudVector];
	Dimension vectorMaPromedio[longitudVector];
	Dimension vectorMultiplicado[longitudVector];
	
	//Inicializacion Vector Principal
	Escribir Sin Saltar"Vector: {";
	Para i<-0 Hasta longitudVector-1 Hacer
		vector[i] <- Aleatorio(1,20);
		Escribir Sin Saltar vector[i], " ,";
	FinPara
	Escribir "}";
	
	//Proceso 
	
	//Punto 1
	//Calculo Promedio
	acumulador<-0;
	Para i<-0 Hasta longitudVector-1 Hacer
		acumulador <- acumulador + vector[i]; 
	FinPara
	promedio <- trunc(acumulador / longitudVector);
	Escribir "";
	Escribir "Promedio: ", promedio;
	//Creacion Nuevo Vector con V Mayores al promedio
	
	Escribir Sin Saltar "Vector Auxiliar: {";
	Para i<-0 Hasta longitudVector-1 Hacer
		si vector[i] > promedio Entonces
			vectorMaPromedio[i] <- vector[i];
		SiNo
			vectorMaPromedio[i] <- 0;
		FinSi
		Escribir Sin Saltar vectorMaPromedio[i], " ,";
	FinPara
	Escribir "}";
	
	//Punto 2
	//Generacion del Vector Multiplicado
	Escribir "";
	Escribir Sin Saltar "Vector Multiplicado: {";
	Para i<-0 Hasta longitudVector-1 Hacer
		si (vector[i] mod 2) = 0 Entonces
			vectorMultiplicado[i] <- vector[i] * 3;
		SiNo
			vectorMultiplicado[i] <- vector[i] * 5;
		FinSi
		Escribir Sin Saltar vectorMultiplicado[i], " ,";
	FinPara
	Escribir "}";
	
	//Busqueda de valor en Vector Multiplicado
	Escribir "Ingrese un valor para buscarlo";
	leer valorBuscado;
	i<-0;
	valorEncontrado<-Falso;
	Mientras NO(valorEncontrado) y (i<longitudVector) Hacer
		si valorBuscado = vectorMultiplicado[i] Entonces
			valorEncontrado<-Verdadero;
			Escribir "Se encontró el nro ", valorBuscado, " en el arreglo";
		FinSi
		i<-i+1;
	FinMientras
	si valorEncontrado = Falso Entonces
		Escribir "NO se encontró el nro ", valorBuscado, " en el arreglo";
	FinSi
	
	
	//Punto 4
	Definir fibonacci Como Entero;
	Dimension fibonacci[10];
	fibonacci[0]<-1;
	fibonacci[1]<-1;
	Para i<-2 hasta 9 Hacer
		fibonacci[i]<- fibonacci[i-2] + fibonacci[i-1];
	FinPara
	Escribir "";
	Escribir "Vector Fibonacci: ";
	Para i<-0 hasta 9 Hacer
		Escribir Sin Saltar fibonacci[i], " ";
	FinPara
	Escribir "";
FinAlgoritmo
