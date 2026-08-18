Algoritmo RepasoIngreso
	//Definción de variables
	definir cantidad, indice Como Entero;
	definir precio, total, descuento Como Real;
	definir acumTotal, acumDescuento Como Real;
	definir deseaContinuar Como Logico;
	Escribir "¿Cuantos productos va a llevar?";
	Leer cantiProd;
	
	//Proceso 
	acumTotal <- 0;
	acumDescuento <- 0;
	indice <- 0;
	deseaContinuar <- Verdadero;
	Mientras indice < cantiProd Y deseaContinuar = Verdadero Hacer
		Escribir "Ingrese el precio del producto ", indice+1;
		Leer precio;
		Escribir "Ingrese la cantidad a comprar del producto ", indice+1;
		Leer cantidad;
		
		total <- precio * cantidad;
		descuento <- 0;
		si (cantidad > 5)
			descuento <- total * 10 / 100;
		FinSi
		
		acumTotal <- acumTotal + total;
		acumDescuento <- acumDescuento + descuento;
		Escribir "el descuento del prod ", indice+1, " es: ", descuento;
		indice <- indice + 1;
		
		Escribir "Si desea continuar ingrese Verdadero";
		Leer deseaContinuar;
	FinMientras
	
	//Salida
	Escribir "el descuento final es: ", acumDescuento;
	Escribir "el total es: ", acumTotal - acumDescuento;
	
FinAlgoritmo
