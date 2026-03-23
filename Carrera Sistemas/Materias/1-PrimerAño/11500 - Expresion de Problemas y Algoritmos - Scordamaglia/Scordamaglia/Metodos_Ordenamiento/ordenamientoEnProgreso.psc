Algoritmo sin_titulo
	//Definicion
	Definir arregloAOrdenar como entero;
	Definir longitudArreglo Como Entero;
	Definir i Como Entero;
	definir aux Como Entero;
	definir bucle Como Entero;
	
	//Inicializacion
	longitudArreglo <- 5;
	Dimension arregloAOrdenar[longitudArreglo];
	arregloAOrdenar[0] <- 5;
	arregloAOrdenar[1] <- 2;
	arregloAOrdenar[2] <- 1;
	arregloAOrdenar[3] <- 8;
	arregloAOrdenar[4] <- 4;
	
	//Proceso 
	bucle <- longitudArreglo-1;
	Mientras bucle<>0 Hacer
		i<-1;
		Mientras i<longitudArreglo Hacer
			si arregloAOrdenar[i]<arregloAOrdenar[i-1] Entonces
				aux<-arregloAOrdenar[i-1];
				arregloAOrdenar[i-1]<-arregloAOrdenar[i];
				arregloAOrdenar[i]<-aux;
				
			FinSi
			i<-i+1;
		FinMientras
		bucle<- bucle-1;
	FinMientras
	
	//Salida
	Para i<-0 hasta longitudArreglo-1 Hacer
		Escribir arregloAOrdenar[i];
	FinPara
FinAlgoritmo
