Algoritmo EjemploMatrices
	
	Definir matriz Como Entero;
	Definir tamanio Como Entero;
	Definir i Como Entero;
	Definir j Como Entero;
	Definir aux como Entero;
	Definir suma como Entero;
	Definir max como Entero;
	Definir min como Entero;
	Definir numBuscado como Entero;
	Definir encontrado Como Logico;
	
	suma <- 0;
	tamanio <- 4;
	Dimension matriz[tamanio, tamanio];
	
	Para i <- 0 Hasta tamanio-1 Con paso 1
		Para j <- 0 Hasta tamanio-1 Con paso 1
			matriz[i, j] <- Aleatorio(0, 5);
		FinPara
	FinPara
	
	Para i <- 0 Hasta tamanio-1 Con paso 1
		Para j <- 0 Hasta tamanio-1 Con paso 1
			Si j < (tamanio-1)
				Escribir Sin Saltar matriz[i,j], "   ";
			SiNo
				Escribir matriz[i,j];
			FinSi
		FinPara
	FinPara
	
	Escribir "--------------------------------------";
	//2
	aux <- matriz[2,2];
	//2				//5
	matriz[2,2] <- matriz[1,1];
	
	matriz[1,1] <- aux;
	
	Para i <- 0 Hasta tamanio-1 Con paso 1
		Para j <- 0 Hasta tamanio-1 Con paso 1
			Si j < (tamanio-1)
				Escribir Sin Saltar matriz[i,j], "   ";
			SiNo
				Escribir matriz[i,j];
			FinSi
		FinPara
	FinPara
	
	//SUMA
	Para i <- 0 Hasta tamanio-1 Con paso 1
		Para j <- 0 Hasta tamanio-1 Con paso 1
			suma <- suma + matriz[i, j];
		FinPara
	FinPara
	
	Escribir "La suma de los elementos de la matriz es: ", suma;
	
	//MAX Y MIN
	max <- matriz[0, 0];
	min <- matriz[0, 0];
	Para i <- 0 Hasta tamanio-1 Con paso 1
		//Nueva fila (resetear variables numericas o booleanas)
		
		Para j <- 0 Hasta tamanio-1 Con paso 1
			si (matriz[i, j] > max)
				max <- matriz[i, j];
			FinSi
			
			si (matriz[i, j]  < min)
				min <- matriz[i, j] ;
			FinSi
		FinPara
		
		//Resultados por fila
		
	FinPara
	
	Escribir "Maximo: ", max;
	Escribir "Minimo: ", min;
	
	Escribir "Ingrese un numero para buscar: ";
	Leer numBuscado;
	
	//BUSCAR TODAS LAS APARICIONES
//	Para i <- 0 Hasta tamanio-1 Con paso 1
//		Para j <- 0 Hasta tamanio-1 Con paso 1
//			SI (numBuscado = matriz[i, j])
//				Escribir "Encontr? el numero buscado en los indices ", i, ",", j;
//			FinSi
//		FinPara
//	FinPara
	
	encontrado <- FALSO;
	
	i <- 0;
	MIENTRAS (NO encontrado Y i <= tamanio-1)
		j <- 0;
		MIENTRAS (NO encontrado Y j <= tamanio-1)
			SI (numBuscado < matriz[i, j])
				Escribir "Encontr? el numero buscado en los indices ", i, ",", j;
				encontrado <- VERDADERO;
			FinSi
			j <- j + 1;
		FinMientras
		i <- i + 1;
	FinMientras
	
	Escribir "Se encontr? el numero? ", encontrado;
	
	
FinAlgoritmo