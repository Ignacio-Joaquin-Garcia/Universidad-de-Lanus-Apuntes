Algoritmo sin_titulo
//Definicion
	Definir flotaEnemiga Como caracter;
	Definir miFlota Como caracter;
	Definir disparos Como Caracter;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	Definir i Como Entero;
	Definir j Como Entero;
	Definir acum Como Entero;
	Definir acum2 Como Entero;
	
	Definir empezoJuego Como Logico;
	Definir juego Como Caracter;
	
	Definir filaJ Como Caracter;
	Definir filaSel Como entero;
	Definir columnaSel Como entero;
	Definir orientacionSel Como Caracter;
	Definir posicionValida Como Logico;
	
	Definir fDisparo Como Entero;
	Definir cDisparo Como Entero;
	Definir lecturaFDisparo Como Caracter;

	Definir barcosEnJuego Como Logico;
	Definir verFlota Como Caracter;
	
	//definimos los barcos
	Definir barco5C Como Entero; 
	Definir barco4C Como Entero; 
	Definir barco3C Como Entero; 
	Definir barco2C Como Entero; 
	Definir barco1C Como Entero; 
	Definir distintaPosicionBarco Como Logico;
	
//Inicializacion
	filas<-11;
	columnas<-11;
	Dimension flotaEnemiga[filas,columnas];
	Dimension miFlota[filas,columnas];
	Dimension disparos[filas,columnas];
	
	Dimension barco5C[2];
	Dimension barco4C[2];
	Dimension barco3C[2];
	Dimension barco2C[2];
	Dimension barco1C[2];
	
	//Generamos valores de Muestra 
	// 1-10
		flotaEnemiga[0,1] <- "1";
		miFlota[0,1] <- "1";
		disparos[0,1]<- "1";
		flotaEnemiga[0,2] <- "2";
		miFlota[0,2] <- "2";
		disparos[0,2]<- "2";
		flotaEnemiga[0,3] <- "3";
		miFlota[0,3] <- "3";
		disparos[0,3]<- "3";
		flotaEnemiga[0,4] <- "4";
		miFlota[0,4] <- "4";
		disparos[0,4]<- "4";
		flotaEnemiga[0,5] <- "5";
		miFlota[0,5] <- "5";
		disparos[0,5]<- "5";
		flotaEnemiga[0,6] <- "6";
		miFlota[0,6] <- "6";
		disparos[0,6]<- "6";
		flotaEnemiga[0,7] <- "7";
		miFlota[0,7] <- "7";
		disparos[0,7]<- "7";
		flotaEnemiga[0,8] <- "8";
		miFlota[0,8] <- "8";
		disparos[0,8]<- "8";
		flotaEnemiga[0,9] <- "9";
		miFlota[0,9] <- "9";
		disparos[0,9]<- "9";
		flotaEnemiga[0,10] <- "10";
		miFlota[0,10] <- "10";
		disparos[0,10]<- "10";

	// A-J
		flotaEnemiga[1,0] <- "A";
		miFlota[1,0] <- "A";
		disparos[1,0]<- "A";
		flotaEnemiga[2,0] <- "B";
		miFlota[2,0] <- "B";
		disparos[2,0]<- "B";
		flotaEnemiga[3,0] <- "C";
		miFlota[3,0] <- "C";
		disparos[3,0]<- "C";
		flotaEnemiga[4,0] <- "D";
		miFlota[4,0] <-"D";
		disparos[4,0]<- "D";
		flotaEnemiga[5,0] <- "E";
		miFlota[5,0] <- "E";
		disparos[5,0]<- "E";
		flotaEnemiga[6,0] <- "F";
		miFlota[6,0] <- "F";
		disparos[6,0]<- "F";
		flotaEnemiga[7,0] <- "G";
		miFlota[7,0] <- "G";
		disparos[7,0]<- "G";
		flotaEnemiga[8,0] <- "H";
		miFlota[8,0] <- "H";
		disparos[8,0]<- "H";
		flotaEnemiga[9,0] <- "I";
		miFlota[9,0] <- "I";
		disparos[9,0]<- "I";
		flotaEnemiga[10,0] <- "J";
		miFlota[10,0] <- "J";
		disparos[10,0]<- "J";

	//Generamos valor nulo de tipo caracter en las matrices ("")
	flotaEnemiga[0,0] <- "";
	miFlota[0,0] <- "";
	disparos[0,0]<- "";
	Para f<-1 Hasta filas-1 Hacer
		Para c<-1 Hasta columnas-1 Hacer
			flotaEnemiga[f,c] <- "";
			miFlota[f,c] <- "";
			disparos[f,c]<- "";
		FinPara
	FinPara
	
	//Simbolos en este juego, * (disparo al Agua), B (barco sin hundir), X (Barco Hundido) 
	
	empezoJuego<-Falso;
	Mientras No(empezoJuego) Hacer
		Escribir "Quiere empezar a Jugar a la batalla Naval (Si/No): ";
		Leer juego;
		juego<- Mayusculas(juego);
		si juego = "SI" Entonces
			empezoJuego<-Verdadero;
			Escribir "Generando Flota Enemiga Aleatoria....";
			Escribir "";
			//Creamos Flota Enemiga 
			//Barco Grande 5C (portaAviones)
				barco5C[0]<-Aleatorio(1,10); //Fila
				barco5C[1]<-Aleatorio(1,10); //Columna
				Para i<-0 Hasta 4 Hacer
					si barco5C[0] <= 6 Entonces
						flotaEnemiga[barco5C[0]+i, barco5C[1]]<-"P";
					sino
						si barco5C[1] <= 6 Entonces
							flotaEnemiga[barco5C[0], barco5C[1]+i]<-"P";
						SiNo
							flotaEnemiga[i+1, 1]<-"P";
						FinSi
					FinSi
				FinPara
				
			//Barco semiGrande 4C (Acorazado)
				distintaPosicionBarco<-Falso;
				Mientras No(distintaPosicionBarco) Hacer //Comprobacion que no haya otro barco en esa posicion
					barco4C[0]<-Aleatorio(1,10); //Fila
					barco4C[1]<-Aleatorio(1,10); //Columna
					si flotaEnemiga[barco4C[0], barco4C[1]] <> "" Entonces
						distintaPosicionBarco<-Falso;
					SiNo
						distintaPosicionBarco<-Verdadero;
						Para i<-0 Hasta 3 Hacer
							si (barco4C[0] <= 7) y (flotaEnemiga[barco4C[0]+i, barco4C[1]] <> "") Entonces
								distintaPosicionBarco<-Falso;
							SiNo 
								si (barco4C[1] <= 7) y (flotaEnemiga[barco4C[0], barco4C[1]+i] <> "")  Entonces
									distintaPosicionBarco<-Falso;
								FinSi
							FinSi
						FinPara
					FinSi
				FinMientras
				Para i<-0 Hasta 3 Hacer
					si barco4C[0] <= 7 Entonces
						flotaEnemiga[barco4C[0]+i, barco4C[1]]<-"A";
					sino
						si barco4C[1] <= 7 Entonces
							flotaEnemiga[barco4C[0], barco4C[1]+i]<-"A";
						SiNo
							flotaEnemiga[i+1, 1]<-"A";
						FinSi
					FinSi
				FinPara
				
			//Barco Mediano 3C (Submarino)
				distintaPosicionBarco<-Falso;
				Mientras No(distintaPosicionBarco) Hacer //Comprobacion que no haya otro barco en esa posicion
					barco3C[0]<-Aleatorio(1,10); //Fila
					barco3C[1]<-Aleatorio(1,10); //Columna
					si flotaEnemiga[barco3C[0], barco3C[1]] <> "" Entonces
						distintaPosicionBarco<-Falso;
					SiNo
						distintaPosicionBarco<-Verdadero;
						Para i<-0 Hasta 2 Hacer
							si (barco3C[0] <= 8) y (flotaEnemiga[barco3C[0]+i, barco3C[1]] <> "") Entonces
								distintaPosicionBarco<-Falso;
							SiNo 
								si (barco3C[1] <= 8) y (flotaEnemiga[barco3C[0], barco3C[1]+i] <> "")  Entonces
									distintaPosicionBarco<-Falso;
								FinSi
							FinSi
						FinPara
					FinSi
				FinMientras
				Para i<-0 Hasta 2 Hacer
					si barco3C[0] <= 8 Entonces
						flotaEnemiga[barco3C[0]+i, barco3C[1]]<-"S";
					sino
						si barco3C[1] <= 8 Entonces
							flotaEnemiga[barco3C[0], barco3C[1]+i]<-"S";
						SiNo
							flotaEnemiga[i+1, 1]<-"S";
						FinSi
					FinSi
				FinPara
				
				//Barco Mediano 2C (Destructor)
				distintaPosicionBarco<-Falso;
				Mientras No(distintaPosicionBarco) Hacer //Comprobacion que no haya otro barco en esa posicion
					barco2C[0]<-Aleatorio(1,10); //Fila
					barco2C[1]<-Aleatorio(1,10); //Columna
					si flotaEnemiga[barco2C[0], barco2C[1]] <> "" Entonces
						distintaPosicionBarco<-Falso;
					SiNo
						distintaPosicionBarco<-Verdadero;
						Para i<-0 Hasta 1 Hacer
							si (barco2C[0] <= 9) y (flotaEnemiga[barco2C[0]+i, barco2C[1]] <> "") Entonces
								distintaPosicionBarco<-Falso;
							SiNo 
								si (barco2C[1] <= 9) y (flotaEnemiga[barco2C[0], barco2C[1]+i] <> "")  Entonces
									distintaPosicionBarco<-Falso;
								FinSi
							FinSi
						FinPara
					FinSi
				FinMientras
				Para i<-0 Hasta 1 Hacer
					si barco2C[0] <= 9 Entonces
						flotaEnemiga[barco2C[0]+i, barco2C[1]]<-"D";
					sino
						si barco2C[1] <= 9 Entonces
							flotaEnemiga[barco2C[0], barco2C[1]+i]<-"D";
						SiNo
							flotaEnemiga[i+1, 1]<-"D";
						FinSi
					FinSi
				FinPara
		FinSi
	FinMientras
	
	//Generacion de flota del jugador
	Para j<-4 Hasta 1 Con Paso -1 Hacer
		posicionValida<-Falso;
		Mientras No(posicionValida) Hacer
			si j = 4 Entonces
				Escribir "Donde quiere poner su Porta Aviones?";
			FinSi
			si j = 3 Entonces
				Escribir "Donde quiere poner su Acorazado?";
			FinSi
			si j = 2 Entonces
				Escribir "Donde quiere poner su Submarino?";
			FinSi
			si j = 1 Entonces
				Escribir "Donde quiere poner su Destructor?";
			FinSi

			Escribir "Ingrese Fila (A-J)";
			Leer filaJ;
			filaJ <- Mayusculas(filaJ);
			Para f<-1 Hasta filas-1 Hacer
				si miFlota[f,0] = filaJ Entonces
					filaSel<-f;
				FinSi
			FinPara
			Escribir "Ingrese columna (1-10)";
			Leer columnaSel;
			Escribir "Ingrese orientacion del barco (V-H)";
			leer orientacionSel;
			orientacionSel<- Mayusculas(orientacionSel);
			
			posicionValida<-Verdadero;
			si miFlota[filaSel, columnaSel] <> "" Entonces
				posicionValida<-Falso;
				Escribir "Por Favor Escriba una posicion Valida";
			SiNo
				si orientacionSel = "V" Entonces
					Para i<-0 Hasta j Hacer
						si (filaSel+i > 10) Entonces
							posicionValida<-Falso;
							Escribir "Por Favor Escriba una posicion Valida";
						SiNo
							si miFlota[filaSel+i, columnaSel] <> "" Entonces
								posicionValida<-Falso;
								Escribir "Por Favor Escriba una posicion Valida";
							FinSi
						FinSi
					FinPara
				SiNo
					Para i<-0 Hasta j Hacer
						si (columnaSel+i > 10) Entonces
							posicionValida<-Falso;
							Escribir "Por Favor Escriba una posicion Valida";
						SiNo
							si miFlota[filaSel, columnaSel+i] <> "" Entonces
								posicionValida<-Falso;
								Escribir "Por Favor Escriba una posicion Valida";
							FinSi
						FinSi
					FinPara
				FinSi
			FinSi
		FinMientras
		//Asignacion de Barcos
		si orientacionSel = "V" Entonces
			Para i<-0 Hasta j Hacer
				si j = 4 Entonces
					miFlota[filaSel+i, columnaSel] <- "P";
				FinSi
				si j = 3 Entonces
					miFlota[filaSel+i, columnaSel] <- "A";
				FinSi
				si j = 2 Entonces
					miFlota[filaSel+i, columnaSel] <- "S";
				FinSi
				si j = 1 Entonces
					miFlota[filaSel+i, columnaSel] <- "D";
				FinSi
			FinPara
		SiNo
			Para i<-0 Hasta j Hacer
				si j = 4 Entonces
					miFlota[filaSel, columnaSel+i] <- "P";
				FinSi
				si j = 3 Entonces
					miFlota[filaSel, columnaSel+i] <- "A";
				FinSi
				si j = 2 Entonces
					miFlota[filaSel, columnaSel+i] <- "S";
				FinSi
				si j = 1 Entonces
					miFlota[filaSel, columnaSel+i] <- "D";
				FinSi
			FinPara
		FinSi
	FinPara
	
//Proceso 
	//Impresion Flota Jugador
	barcosEnJuego<-Falso;
	Mientras No(barcosEnJuego) Hacer
		Escribir "Quiere ver su flota? (si/no)";
		Leer verFlota;
		verFlota<-Mayusculas(verFlota);
		si verFlota = "SI" Entonces
			Escribir "";
			Escribir "La Ubicacion de tu flota queda de la siguiente manera: ";
			Para f<-0 Hasta filas-1 Hacer
				Para c<-0 Hasta columnas-1 Hacer
					si c <> columnas-1 Entonces
						si miFlota[f,c] = "" Entonces
							Escribir Sin Saltar miFlota[f,c], "   | ";
						SiNo
							Escribir Sin Saltar miFlota[f,c], "  | ";
						FinSi
					SiNo
						si miFlota[f,c] = "" Entonces
							Escribir miFlota[f,c], "    | ";
						SiNo
							si (miFlota[f,c] = "X") o (miFlota[f,c] = "B") Entonces
								Escribir miFlota[f,c], "   | ";
							SiNo
								Escribir miFlota[f,c], "  | ";
							FinSi
						FinSi
						Para i<-0 Hasta columnas-1 Hacer
							Escribir Sin Saltar "-----";
						FinPara
						Escribir "";
					FinSi
				FinPara
			FinPara
		FinSi
		
		
		//Dinamica de Juego
		Escribir "Es tu turno donde quieres disparar?";
		Escribir "Elige fila a la que disparar (A-J)";
		Leer lecturaFDisparo;
		lecturaFDisparo<- Mayusculas(lecturaFDisparo);
		Para f<-1 Hasta filas-1 Hacer
			si miFlota[f,0] = lecturaFDisparo Entonces
				fDisparo<-f;
			FinSi
		FinPara
		Escribir "Elige columna a la que disparar (1-10)";
		Leer cDisparo;
		
		Escribir "";
		si (flotaEnemiga[fDisparo, cDisparo] = "P") Entonces
			disparos[fDisparo, cDisparo] <- "X";
			flotaEnemiga[fDisparo, cDisparo] <- "X";
			Escribir "Le diste al Porta Aviones Enemigo";
		SiNo
			si (flotaEnemiga[fDisparo, cDisparo] = "A") Entonces
				disparos[fDisparo, cDisparo] <- "X";
				flotaEnemiga[fDisparo, cDisparo] <- "X";
				Escribir "Le diste al Acorazado Enemigo";
			SiNo
				si (flotaEnemiga[fDisparo, cDisparo] = "S") Entonces
					disparos[fDisparo, cDisparo] <- "X";
					flotaEnemiga[fDisparo, cDisparo] <- "X";
					Escribir "Le diste al Submarino Enemigo";
				SiNo
					si (flotaEnemiga[fDisparo, cDisparo] = "D") Entonces
						disparos[fDisparo, cDisparo] <- "X";
						flotaEnemiga[fDisparo, cDisparo] <- "X";
						Escribir "Le diste al Destructor Enemigo";
					SiNo
						disparos[fDisparo, cDisparo] <- "~";
						Escribir "Agua (~)";
					FinSi
				FinSi
			FinSi
		FinSi
		//Impresion matriz Disparos
		Escribir "Quiere ver sus disparos? (si/no)";
		Leer verFlota;
		verFlota<-Mayusculas(verFlota);
		si verFlota = "SI" Entonces
			Escribir "";
			Escribir "Tus Disparos: ";
			Para f<-0 Hasta filas-1 Hacer
				Para c<-0 Hasta columnas-1 Hacer
					si c <> columnas-1 Entonces
						si disparos[f,c] = "" Entonces
							Escribir Sin Saltar disparos[f,c], "   | ";
						SiNo
							Escribir Sin Saltar disparos[f,c], "  | ";
						FinSi
					SiNo
						si disparos[f,c] = "" Entonces
							Escribir disparos[f,c], "    | ";
						SiNo
							si (disparos[f,c] = "X") Entonces
								Escribir disparos[f,c], "   | ";
							SiNo
								Escribir disparos[f,c], "  | ";
							FinSi
						FinSi
						Para i<-0 Hasta columnas-1 Hacer
							Escribir Sin Saltar "-----";
						FinPara
						Escribir "";
					FinSi
				FinPara
			FinPara
		FinSi
		
		//Ataque Enemigo
		fDisparo<-Aleatorio(1,10);
		cDisparo<-Aleatorio(1,10);
		posicionValida <- Falso;
		Mientras No(posicionValida) Hacer //Comprobracion de Tiro Aleatorio
			si (miFlota[fDisparo,cDisparo] = "~") o miFlota[fDisparo,cDisparo] = "X" Entonces
				fDisparo<-Aleatorio(1,10);
				cDisparo<-Aleatorio(1,10);
			SiNo
				posicionValida <- Verdadero;
			FinSi
		FinMientras
		si (miFlota[fDisparo, cDisparo] = "P") Entonces
			miFlota[fDisparo, cDisparo] <- "X";
			Escribir "Tu Porta Aviones fue atacado";
		SiNo
			si (miFlota[fDisparo, cDisparo] = "A") Entonces
				miFlota[fDisparo, cDisparo] <- "X";
				Escribir "Tu Acorazado fue atacado";
			SiNo
				si (miFlota[fDisparo, cDisparo] = "S") Entonces
					miFlota[fDisparo, cDisparo] <- "X";
					Escribir "Tu Submarino fue atacado";
				SiNo
					si (miFlota[fDisparo, cDisparo] = "D") Entonces
						miFlota[fDisparo, cDisparo] <- "X";
						Escribir "Tu Destructor fue atacado";
					SiNo
						miFlota[fDisparo, cDisparo] <- "~";
						Escribir "El enemigo le dio al Agua(~)";
					FinSi
				FinSi
			FinSi
		FinSi
		
		//Analisis si acabo Juego
		acum<-0;
		acum2<-0;
		Para f<-1 Hasta filas-1 Hacer
			Para c<-1 Hasta columnas-1 Hacer
				si disparos[f,c] = "X" Entonces
					acum<-acum+1;
				FinSi
				si miFlota[f,c] = "X" Entonces
					acum2<-acum2+1;
				FinSi
			FinPara
		FinPara
		si acum = 14 Entonces
			Escribir "Felicidades Ganaste el Juego!!, Hundiste tdos los barcos Enemigos";
			barcosEnJuego<-Verdadero;
		FinSi
		si acum2 = 14 Entonces
			Escribir "Perdiste!! :(, Todos tus barcos fueron Hundidos!";
			barcosEnJuego<-Verdadero;
		FinSi
	FinMientras
	
	
	
	//Impresion Flota Enemiga
	Escribir "";
	Escribir "La Flota Enemiga Quedo de esta manera: ";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				si flotaEnemiga[f,c] = "" Entonces
					Escribir Sin Saltar flotaEnemiga[f,c], "   | ";
				SiNo
					Escribir Sin Saltar flotaEnemiga[f,c], "  | ";
				FinSi
			SiNo
				si flotaEnemiga[f,c] = "" Entonces
					Escribir flotaEnemiga[f,c], "    | ";
				SiNo
					si (flotaEnemiga[f,c] = "X") o (flotaEnemiga[f,c] = "B") Entonces
						Escribir  flotaEnemiga[f,c], "   | ";
					SiNo
						Escribir  flotaEnemiga[f,c], "  | ";
					FinSi
				FinSi
				Para i<-0 Hasta columnas-1 Hacer
					Escribir Sin Saltar "-----";
				FinPara
				Escribir "";
			FinSi
		FinPara
	FinPara
	

FinAlgoritmo
