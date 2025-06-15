Algoritmo sin_titulo
	Definir matriz Como Entero;
	Definir filas Como Entero;
	Definir columnas Como Entero;
	Definir f Como Entero;
	Definir c Como Entero;
	Definir i Como Entero;
	
	Definir longValoresBusqueda Como Entero;
	Definir vecValoresABuscar Como Entero;
	
	Definir valorEncontrado Como Logico;
	Definir vecResultadosBusqueda Como logico;
	
	
	filas <- 10;
	columnas <- 10;
	Dimension matriz[filas,columnas];
	longValoresBusqueda<-5;
	Dimension vecValoresABuscar[longValoresBusqueda];
	Dimension vecResultadosBusqueda[longValoresBusqueda];
	valorEncontrado<-Falso;
	
	//Asignamos valores a la matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 hasta columnas-1 Hacer
			matriz[f,c] <- Aleatorio(0,50);
		FinPara
	FinPara
	
	//Imprimimos Matriz
	Para f<-0 Hasta filas-1 Hacer
		para c<-0 hasta columnas-1 Hacer
			si (c <> columnas-1)   Entonces
				si matriz[f,c] >= 10 Entonces
					Escribir Sin Saltar matriz[f,c], " | ";
				SiNo
					Escribir Sin Saltar matriz[f,c], "  | ";
				FinSi
			SiNo
				Escribir matriz[f,c];
			FinSi
		FinPara
	FinPara
	
	//Leemos valores a buscar
	Para i<-0 hasta 4 Hacer
		Escribir "Escriba valor ", i, " para buscar en la matriz";
		Leer vecValoresABuscar[i];
	FinPara
	//Mostrar Valores a buscar
	escribir "Vector Valores a Buscar: ";
	Para i<-0 hasta longValoresBusqueda-1 Hacer
		Escribir Sin Saltar vecValoresABuscar[i], " | ";
	FinPara
	Escribir "";
	
	//Recorremos la Matriz en busqueda del valor buscado por cada valor buscado
	Para i<-0 Hasta longValoresBusqueda-1 Hacer
		Para f<-0 Hasta filas-1 Hacer
			para c<-0 hasta columnas-1 Hacer
				si vecValoresABuscar[i] = matriz[f,c] Entonces
					valorEncontrado<- Verdadero;
				FinSi
			FinPara
		FinPara
		vecResultadosBusqueda[i]<-valorEncontrado;
		valorEncontrado<- Falso;
	FinPara
	
	//Mostrar Resultados Busqueda
	escribir "Vector Resultados Busqueda: ";
	Para i<-0 hasta longValoresBusqueda-1 Hacer
		Escribir Sin Saltar vecResultadosBusqueda[i], " | ";
	FinPara
	Escribir "";
	
	
FinAlgoritmo
