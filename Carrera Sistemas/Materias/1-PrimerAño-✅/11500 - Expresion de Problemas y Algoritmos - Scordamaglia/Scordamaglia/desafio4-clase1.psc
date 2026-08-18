Algoritmo des4c1
	//Definiciones
	Definir num1 Como Entero;
	definir num2 Como Entero;
	definir divisoresPropiosN1 Como Entero;
	definir divisoresPropiosN2 Como Entero;
	definir i como entero;
	
	definir numEncontrado Como Logico;
	
	//Inicializacion
	num1<-999;
	num2<-999;
	divisoresPropiosN1<-0;
	divisoresPropiosN2<-0;
	numEncontrado<-Falso;
	
	//Proceso 
	Mientras NO(numEncontrado) Hacer
		num1<- num1 + 1;
		Mientras NO(numEncontrado) y (num2 < 9999) Hacer
			num2<- num2 + 1;
			Para i<-1 hasta num2-1 Hacer
				si (num2 mod i)=0 Entonces
					divisoresPropiosN2<- divisoresPropiosN2 + i; 
				FinSi
			FinPara
			
			si divisoresPropiosN2 = num1 Entonces
				Para i<-1 hasta num1-1 Hacer
					Si (num1 mod i) = 0 Entonces
						divisoresPropiosN1 <- divisoresPropiosN1 + i;
					FinSi
				FinPara
				si divisoresPropiosN1 = num2 Entonces
					numEncontrado<-Verdadero;
					Escribir "El primer par de numeros amigos es: ", num1, " y ", num2;
				FinSi
				divisoresPropiosN1<-0;
			FinSi
			divisoresPropiosN2<-0;
			Escribir "numero1: ", num1, " y numero2: ", num2;
		FinMientras
		num2<-999;
		Escribir "numero1: ", num1, " y numero2: ", num2;
	FinMientras	
FinAlgoritmo
