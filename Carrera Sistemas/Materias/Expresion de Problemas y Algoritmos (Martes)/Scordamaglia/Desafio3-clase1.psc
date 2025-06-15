Algoritmo Des3c1
	//Definiciones
	Definir numAleatorio Como Entero;
	Definir numAlCuadrado Como Entero;
	Definir a, b, c, d Como Entero;
	Definir numComprobar Como Entero;
	
	Definir numEncontrado Como Logico;
	
	//Inicializacion
	numEncontrado <- Falso;
	numAleatorio<-999;
	//Proceso 
	Mientras NO(numEncontrado) Hacer
		//Generamos posibles numeros que al cuadrado no superen 4 cifras
		numAleatorio <- numAleatorio + 1;
		numAlCuadrado <- numAleatorio ^ 2;
		//Creamos los digitos a analizar
		a <- Trunc((numAlCuadrado mod 10000) / 1000);
		b <- Trunc((numAlCuadrado mod 1000) / 100);
		c <- Trunc((numAlCuadrado mod 100) / 10);
		d <- numAlCuadrado mod 10;
		
		//Comprobramos si cumplen la condicion
		numComprobar <- a*1000 + b*100 + c*10 + d;
		si numComprobar = numAleatorio Entonces
			numEncontrado <- Verdadero;
			Escribir "El numero encontrado automorfico es: ", numComprobar;
		FinSi
		Escribir numAleatorio," ", numAlCuadrado," ", a," ", b," ", c," ", d;
	FinMientras
	
	
	
	
FinAlgoritmo
