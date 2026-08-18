Algoritmo desafio3c2
	
	//Inicializacion 
	Definir numAleatorio Como Entero;
	Definir num Como Entero;
	Definir numEncontrado Como Logico;
	Definir aux Como Entero;
	Definir i Como Entero;
	Definir j Como Entero;
	
	Definir ordAscendente Como Entero;
	Definir ordDescendente Como Entero;
	Definir numAscendente Como Entero;
	Definir numDescendente Como Entero;
	
	//Definicion
	Dimension num[3];
	Dimension ordAscendente[3];
	Dimension ordDescendente[3];
	numEncontrado<-Falso;
	
	//Inicializamos Arreglos
	Para i<-0 hasta 2 Hacer
		ordAscendente[i]<-0;
		ordDescendente[i]<-0;
	FinPara
	
	//Proceso 
	numAleatorio<- Aleatorio(100,998);
	Para i<-0 Hasta 999 Con Paso 111 Hacer //Nos Aseguramos que toque un numero con 2 digitos diferentes
		si (numAleatorio = i) Entonces
			numAleatorio<- Aleatorio(100,998);
		FinSi
	FinPara
	
	Mientras NO(numEncontrado) Hacer
		//Declaramos Digitos a Ordenar
		num[0]<- Trunc(numAleatorio / 100);
		num[1]<- trunc((numAleatorio mod 100) / 10);
		num[2]<- numAleatorio mod 10;
		Para i<-0 hasta 2 Hacer
			ordAscendente[i]<-num[i];
			ordDescendente[i]<-num[i];
			Escribir num[i];
		FinPara
		
		//Ordenamos de forma Ascendente y Descendente los digitos
		Para i<-0 hasta 1 Hacer
			Para j<-(i+1) hasta 2 Hacer
				si (ordAscendente[j] < ordAscendente[i])  Entonces
					aux<-ordAscendente[i];
					ordAscendente[i]<-ordAscendente[j];
					ordAscendente[j]<-aux;
				FinSi
				si (ordDescendente[j] > ordDescendente[i]) Entonces
					aux<-ordDescendente[i];
					ordDescendente[i]<-ordDescendente[j];
					ordDescendente[j]<-aux;
				FinSi
			FinPara
		FinPara
		
		//Volvemos los digitos a centenas y decimas
		ordAscendente[0] <- ordAscendente[0] * 100;
		ordAscendente[1] <- ordAscendente[1] * 10;
		numAscendente <- ordAscendente[0] + ordAscendente[1] + ordAscendente[2];
		ordDescendente[0] <- ordDescendente[0] * 100;
		ordDescendente[1] <- ordDescendente[1] * 10;
		numDescendente <- ordDescendente[0] + ordDescendente[1] + ordDescendente[2];
		
		//Analizamos Resultados "Salida"
		Escribir "Numero Descendente: ", numDescendente;
		Escribir "Numero Ascendente: ", numAscendente;
		si numAleatorio = (numDescendente - numAscendente) Entonces
			numEncontrado<-Verdadero;
			Escribir "El numero de Kaprekar es: ", numAleatorio;
		SiNo
			numAleatorio<- numDescendente - numAscendente;
		FinSi
	FinMientras
FinAlgoritmo
