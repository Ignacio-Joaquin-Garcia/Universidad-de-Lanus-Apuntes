Algoritmo sin_titulo
	//Definicion
	Definir matriz Como Caracter;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	
	Definir letras Como Caracter;
	Definir tamanoPaBuscada Como Entero;
	Definir letrasPBuscada como caracter;
	Definir i Como Entero;
	Definir acum Como Entero;
	Definir pBuscadaHorizontal Como Logico;
	Definir pBuscadaVertical Como Logico;
	definir l Como caracter;
	//Inicializacion
	filas <- 10;
	columnas <- 10;
	
	Dimension matriz[filas,columnas];
	Dimension letras[26];
	
	//Generamos vector letras del abecedario
	letras[0] <- 'A';
	letras[1] <- 'B';
	letras[2] <- 'C';
	letras[3] <- 'D';
	letras[4] <- 'E';
	letras[5] <- 'F';
	letras[6] <- 'G';
	letras[7] <- 'H';
	letras[8] <- 'I';
	letras[9] <- 'J';
	letras[10] <- 'K';
	letras[11] <- 'L';
	letras[12] <- 'M';
	letras[13] <- 'N';
	letras[14] <- 'O';
	letras[15] <- 'P';
	letras[16] <- 'Q';
	letras[17] <- 'R';
	letras[18] <- 'S';
	letras[19] <- 'T';
	letras[20] <- 'U';
	letras[21] <- 'V';
	letras[22] <- 'W';
	letras[23] <- 'X';
	letras[24] <- 'Y';
	letras[25] <- 'Z';
	
	//Generacion de matriz con letras aleatorias
	Para f<-0 hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			matriz[f,c] <- letras[Aleatorio(0,25)];
		FinPara
	FinPara
	//Escribir matriz
	Para f<-0 hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], "  ";
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Inicializacion de busqueda de palabras
	Escribir "Tamaño de palabra a buscar: ";
	Leer tamanoPaBuscada;
	Mientras (tamanoPaBuscada <= 0) //Validacion de Inputs
		Escribir "Escriba un tamaño de palabra correcto (mayor a 0)";
		Leer tamanoPaBuscada;;
	FinMientras
	
	Dimension letrasPBuscada[tamanoPaBuscada];
	Para i<-0 Hasta tamanoPaBuscada-1 Hacer
		Escribir "Ingrese la letra de la posicion ", i+1;
		leer l;
		letrasPBuscada[i] <- Mayusculas(l); //Validacion de Input;
	FinPara
	//Imprimimos palabras a buscar
	Para i<-0 Hasta tamanoPaBuscada-1 Hacer
		Escribir Sin Saltar letrasPBuscada[i];
	FinPara
	Escribir "";
	
	//Proceso 
	//Busqueda de palabra de manera Horizontal
	acum<-0;
	f<-0;
	pBuscadaHorizontal<-Falso;
	Mientras (f <= filas-1) y NO(pBuscadaHorizontal) Hacer
		c<-0;
		Mientras (c <= columnas-1) y NO(pBuscadaHorizontal) Hacer
			si (letrasPBuscada[0] = matriz[f,c]) Entonces
				Para i<-0 Hasta tamanoPaBuscada-1 Hacer
					si c+i < columnas Entonces
						si matriz[f,(c+i)] = letrasPBuscada[i] Entonces
							acum<-acum+1;
						FinSi
					FinSi
				FinPara
				si acum = tamanoPaBuscada Entonces
					pBuscadaHorizontal<-Verdadero;
					Escribir "La palabra fue encontrada en HORIZONTAL, en indice: matriz[",f,", ",c ,"]";
				sino
					acum<-0;
				FinSi
			FinSi
			c<-c+1;
		FinMientras
		f<-f+1;
	FinMientras
	si pBuscadaHorizontal = Falso Entonces
		Escribir "La palabra NO fue encontrada en HORIZONTAL";
	FinSi
	
	// Búsqueda de palabra de manera Vertical
	pBuscadaVertical <- Falso;
	c <- 0;
	Mientras (c < columnas) y NO(pBuscadaVertical) Hacer
		f <- 0;
		Mientras (f < filas) y NO(pBuscadaVertical) Hacer
			// Verifica si la palabra entra en las filas restantes
			si f + tamanoPaBuscada <= filas Entonces
				acum <- 0;
				si matriz[f, c] = letrasPBuscada[0] Entonces
					Para i <- 0 Hasta tamanoPaBuscada - 1 Hacer
						si matriz[f + i, c] = letrasPBuscada[i] Entonces
							acum <- acum + 1;
						FinSi
					FinPara
					si acum = tamanoPaBuscada Entonces
						pBuscadaVertical <- Verdadero;
						Escribir "La palabra fue encontrada en VERTICAL, en índice: matriz[", f, ", ", c, "]";
					FinSi
				FinSi
			FinSi
			f <- f + 1;
		FinMientras
		c <- c + 1;
	FinMientras
	si NO(pBuscadaVertical) Entonces
		Escribir "La palabra NO fue encontrada en VERTICAL";
	FinSi
FinAlgoritmo
