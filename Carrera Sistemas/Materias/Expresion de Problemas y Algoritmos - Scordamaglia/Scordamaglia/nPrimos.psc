Algoritmo sin_titulo
	Definir vector Como Entero;
	Definir vectorP Como Entero;
	Definir i Como Entero;
	Definir j Como Entero;
	Definir num Como Real;
	Definir acum Como Entero;
	Definir primos Como Entero;
	
	Dimension vector[5];
	Dimension vectorP[5];
	primos<-0;
	Escribir Sin Saltar"{";
	Para i<-0 hasta 4 Hacer
		vector[i] <- Aleatorio(0,99);
		vectorP[i]<-0;
		acum<-0;
		para j<-1 hasta vector[i] Hacer
			num <- vector[i];
			si (num mod j) = 0 Entonces
				acum<- acum+1;
			FinSi
		FinPara
		si (acum = 2) Entonces
			primos<-primos+1;
			vectorP[i]<-vector[i];
		FinSi
		Escribir Sin Saltar vector[i], ", ";
	FinPara
	Escribir "}";
	Escribir "Cant numeros primos en vector: ", primos;
	Escribir "{";
	Para i<-0 hasta 4 Hacer
		Escribir Sin Saltar vectorP[i], ", ";
	FinPara
	Escribir "}";
FinAlgoritmo
