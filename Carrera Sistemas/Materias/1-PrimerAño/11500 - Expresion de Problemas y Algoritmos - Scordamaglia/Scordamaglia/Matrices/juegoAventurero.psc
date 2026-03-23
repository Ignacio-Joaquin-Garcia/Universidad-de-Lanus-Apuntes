Algoritmo Juego_Aventurero
//Definicion
	Definir matriz Como Entero;
	Definir filas, columnas, f, c, mCuadrada Como Entero;
	Definir i, j Como Entero;
	Definir cambioDireccion, perdisteJuego Como Logico;
	Definir comidaEnBolsa, pasos, pasosTotales, nivel, mejoraPasos, maxComidaEnBolso Como Entero;
	Definir dificultad, mejora Como Caracter;
//Inicializacion
	Escribir "Indique la dimensión de la matriz cuadrada:";
	Leer mCuadrada;
	filas<-mCuadrada;
	columnas<- mCuadrada;
	Dimension matriz[filas,columnas];
	//Generamos matriz con valores aleatorios
	Escribir "Que dificultad quieres que el aventurero tenga al hacer su viaje? (F, M, D)";
	Leer dificultad;
	dificultad<-Mayusculas(dificultad);
	
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si dificultad = "D" Entonces
				matriz[f,c]<-Aleatorio(-2,1);
			FinSi
			si dificultad = "M" Entonces
				matriz[f,c]<-Aleatorio(-1,1);
			FinSi
			si dificultad = "F" Entonces
				matriz[f,c]<-Aleatorio(0,1);
			FinSi
			si matriz[f,c] < 0 Entonces
				matriz[f,c] <- 0;
			FinSi
		FinPara
	FinPara
	
	//Imprimimos Matriz
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c<>columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], " | ";
			sino
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
//Proceso
	//Dinamica General con matriz recorrida de manera Serpiente
	cambioDireccion<-Verdadero;
	perdisteJuego<-Falso;
	comidaEnBolsa<-0;
	pasos<-3;
	pasosTotales<-0;
	nivel<-0;
	maxComidaEnBolso<-2;
	mejoraPasos<-0;
	Para f<-0 Hasta filas-1 Hacer
		si cambioDireccion Entonces //Movimiento Serpiente
			cambioDireccion<-Falso;
			c<-0;
		SiNo
			cambioDireccion<-Verdadero;
			c<-columnas-1;
		FinSi
		
		//Dinamica Juego
		Mientras (c >= 0) y (c <= columnas-1) y No(perdisteJuego) Hacer 
			si matriz[f,c] = 0 Entonces
				Escribir "Recorriendo el espacio (", f, ",", c, "), No hay nada";
			FinSi
			si matriz[f,c] = 1 Entonces
				si comidaEnBolsa >= maxComidaEnBolso Entonces
					Escribir "Recorriendo el espacio (", f, ",", c, "), Encontró comida pero se le cayo!. Comidas acumuladas:", comidaEnBolsa;
					Escribir "El Aventurero solo puede llevar ", maxComidaEnBolso, "comidas en el bolso, mejorale su bolsita para que pueda llevar más!";
				SiNo
					comidaEnBolsa<-comidaEnBolsa+1;
					Escribir "Recorriendo el espacio (", f, ",", c, "), Encontró comida y la guarda en el bolso. Comidas acumuladas:", comidaEnBolsa;
				FinSi
			FinSi
			pasos<-pasos-1;
			si pasos = 0 Entonces
				si comidaEnBolsa > 0 Entonces
					comidaEnBolsa<-comidaEnBolsa-1;
					pasos<-3;
					Escribir "Ha hecho 3 pasos y consumió comida. Comidas acumuladas: ", comidaEnBolsa;
				SiNo
					perdisteJuego<-Verdadero;
				FinSi
			FinSi
			pasosTotales<-pasosTotales+1;
			si (pasosTotales mod 6) = 0 Entonces
				nivel<-nivel+1;
				Escribir "Felicidades! Tu aventurero subio de nivel, Ahora es Nivel: ", nivel;
				si nivel=1 Entonces
					Escribir "Por ello, puedes elegir una mejora para tu aventurero. Que prefieres (mejoraBolso/mejoraPasos)";
					Escribir "Aclaracion: mejoraBolsos, mejora la cantidad de comida que puede llevar. mejoraPasos, permite al aventurero avanzar de 1 paso mas, salteandose todo lo de enmedio";
				SiNo
					Escribir "Que mejora prefieres? (mejoraBolso/mejoraPasos)";
				FinSi
				Leer mejora;
				si mejora = "mejoraBolso" Entonces
					maxComidaEnBolso<-maxComidaEnBolso+1;
				SiNo
					si mejora = "mejoraPasos" Entonces
						mejoraPasos<-mejoraPasos+1;
					SiNo
						Escribir "Escribiste mal la mejora que querias darle al aventurero, Ahora el aventurero se quedo sin mejora!";
					FinSi
				FinSi
			FinSi
			
			si cambioDireccion Entonces //Movimiento Serpiente
				c<-c-1 - mejoraPasos;
			SiNo
				c<-c+1 + mejoraPasos;
			FinSi
		FinMientras
	FinPara
	
//Salida
	si perdisteJuego Entonces //Analisis Final del Juego
		Escribir "El explorador ha muerto de hambre";
		Escribir "El aventurero murio despues de dar ", pasosTotales, " pasos";
	SiNo
		Escribir "El explorador sobrevivió";
		Escribir "El aventurero logro escapar despues de dar ", pasosTotales, " pasos";
	FinSi
FinAlgoritmo