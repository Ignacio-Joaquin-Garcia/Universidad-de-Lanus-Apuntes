Algoritmo sin_titulo
	definir cantidad, tamano, auxTam, contCant, contXTam, contG, cantAcum, minTam, minFab, tam300 como entero;
	definir i como entero;
	definir veces como entero;
	definir prom Como Real;
	contCant<-0;
	contXTam<-0;
	contG<-0;
	cantAcum<-0;
	Leer veces;
	Para i<-1 Hasta veces Hacer
		Leer cantidad, tamano;
		auxTam <- tamano;
		Mientras tamano=auxTam Hacer
			contCant <- contCant+1;
			contXTam <- contXTam+cantidad;
			contG <- contG+1;
			cantAcum <- cantAcum+cantidad;
			Si contG=1 Entonces
				minTam <- tamano;
				minFab <- cantAcum;
			FinSi
			Si cantAcum < minFab Entonces
				minTam <- tamano;
				minFab <- cantAcum;
			FinSi
			Leer cantidad,tamano;
		FinMientras
		prom <- contXTam / contCant;
		Escribir "promedio del tamaño: ", prom;
		contCant <- 0;
		Si contXTam > 300 Entonces
			tam300 <- tam300 + 1;
		FinSi
		contXTam <- 0;
	FinPara
	Escribir "los tamaños con cantidades > 300 son: ", tam300, " y el tamaño con menor fab es: ", minTam, " con una cantidad de: ", minFab;
FinAlgoritmo
