Algoritmo sin_titulo
	Definir matriz Como Entero;
	Definir matrizTranspuesta Como Entero;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	
	filas<-3;
	columnas<-3;
	
	Dimension matriz[filas,columnas];
	Dimension matrizTranspuesta[filas,columnas];
	
	matriz[0,0]<-1;
	matriz[0,1]<-0;
	matriz[0,2]<-4;
	matriz[1,0]<-0;
	matriz[1,1]<-5;
	matriz[1,2]<-0;
	matriz[2,0]<-6;
	matriz[2,1]<-0;
	matriz[2,2]<--9;
	
	Escribir "Matriz: ";
	Para f<-0 Hasta filas-1 Hacer
		Para c<-0 Hasta columnas-1 Hacer
			si c <> columnas-1 Entonces
				Escribir Sin Saltar matriz[f,c], " | ";
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	Escribir "Matriz Transpuesta: ";
	Para c<-0 Hasta columnas-1 Hacer
		Para f<-0 Hasta filas-1 Hacer
			matrizTranspuesta[f,c]<-matriz[f,c];
			si f <> filas-1 Entonces
				Escribir Sin Saltar matrizTranspuesta[f,c], " | ";
			SiNo
				Escribir matrizTranspuesta[f,c];
			FinSi
		FinPara
	FinPara
FinAlgoritmo
