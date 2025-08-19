Algoritmo sin_titulo
//Definicion
	Definir matriz Como Entero;
	Definir filas, columnas, f, c Como Entero;
	Definir vectorAux, sumaProdDia Como Entero;
	Definir diaMenosFab, fabMenor Como Entero;
	
//Inicializacion
	filas<-7;      //Dias
	columnas<-3;   //Turnos
	Dimension matriz[filas,columnas];
	//1) Creamos matriz aleatoria con productos fabricados por Dias/Turnos
	Para f<-0 hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			matriz[f,c]<-Aleatorio(0,30);
		FinPara
	FinPara
	
	//4) vectorAux
	Dimension vectorAux[filas];
	
	//2) Impresion Matriz
	Escribir "Matriz Original: ";
	Para f<-0 hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c<>columnas-1 Entonces
				si matriz[f,c] >= 10 Entonces
					Escribir Sin Saltar matriz[f,c], "  ";
				SiNo
					Escribir Sin Saltar matriz[f,c], "   ";
				FinSi
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
//Proceso
	//3) Turnos con mas de 25 fabricados
	Escribir "";
	Escribir "Turnos con más de 25 fabricados:";
	Para f<-0 hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si matriz[f,c] > 25 Entonces
				Escribir "Día ", f+1, " Turno ", c+1, " - Se fabricaron más de 25 productos";
			FinSi
		FinPara
	FinPara
	
	//4) Carga de datos en vectorAux
	Para f<-0 hasta filas-1 Hacer
		sumaProdDia<-0;
		Para c<-0 Hasta columnas-1 Hacer
			sumaProdDia<-sumaProdDia + matriz[f,c];
		FinPara
		vectorAux[f]<-sumaProdDia;
	FinPara
	//5)Imprimimos Vector Auxiliar
	Escribir "";
	Escribir "Suma de fabricados por día";
	Para f<-0 Hasta filas-1 Hacer
		Escribir "Día ", f+1, ": ", vectorAux[f];
	FinPara
	
	//6) Recorremos en Vector Aux en busqueda del dia con menos fabricaciones totales
	diaMenosFab<-0;
	fabMenor<- vectorAux[0];
	Para f<-1 Hasta filas-1 Hacer
		si vectorAux[f] < fabMenor Entonces
			diaMenosFab<-f;
			fabMenor<- vectorAux[f];
		FinSi
	FinPara
	Escribir "";
	Escribir "El día con menos productos fabricados fue el día ", diaMenosFab+1, " con ", fabMenor, " productos";
FinAlgoritmo
