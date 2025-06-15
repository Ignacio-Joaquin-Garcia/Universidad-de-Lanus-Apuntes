Algoritmo sistemaDeNumeracion
	definir num Como Entero;
	definir numOriginal Como Entero;
	definir decimalesOriginales Como Entero;
	Definir decimales como real;
	definir decimalesBinarios como cadena;
	Definir aux como cadena;
	Definir base Como Entero;
	Definir numeroBinario como cadena;
	
	Definir longitud1 Como Entero;
    Definir intentos Como Entero;
    Definir cadenaInvertida como cadena;
	
	Escribir "cual es el numero a pasar SIN sus decimales?";
	leer numOriginal;
	Escribir "cuales son los decimales del numero?";
	leer decimalesOriginales;
	Escribir "desde el sistema de numeracion de base 10, a cual desea pasar su numero?";
	leer base;
	
	num<-numOriginal;
	numeroBinario<-"";
	Mientras (num / base) >= 0
		numeroBinario<- ConvertirATexto(num mod base) + numeroBinario;
		
		num<-num - num mod base;
		num<-num / base;
		si num=0
			num<-num-1;
		FinSi
	FinMientras
	Escribir numeroBinario;
	
	decimales<-decimalesOriginales / (10 ^ Longitud(ConvertirATexto(decimalesOriginales)));
	decimalesBinarios<-"";
	intentos<-0;
	Mientras no(intentos=10)
		decimales<-decimales*base;
		aux<-ConvertirATexto(decimales);
		decimalesBinarios<-decimalesBinarios+Subcadena(aux, 0, 1);
		decimales<-decimales - ConvertirANumero(Subcadena(aux, 0, 1));
		intentos<-intentos+1;
	FinMientras
	
	Escribir "los numeros encerados por . son los decimales";
	Escribir numeroBinario + "." + decimalesBinarios;		
	
FinAlgoritmo
