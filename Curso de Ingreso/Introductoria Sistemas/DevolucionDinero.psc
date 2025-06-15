Algoritmo Ejercicio_28
	Definir valorCompra Como Entero;
	Definir pagoRealizado Como Entero;
	Definir B1000 Como Entero;
	Definir B500 Como Entero;
	Definir B200 Como Entero;
	Definir B100 Como Entero;
	Definir B50 Como Entero;
	Definir aDevolver Como Entero;
	Definir pos1 Como Entero;
	pos1 <- 1;
	B1000 <- 0;
	B500 <- 0;
	B200 <- 0;
	B100 <- 0;
	B50 <- 0;
	Escribir 'Ingresar valorCompra';
	Leer valorCompra;
	Escribir 'Ingresar Pago Realizado';
	Leer pagoRealizado;
	Mientras pagoRealizado<>0 Hacer
		Si pos1=1 Entonces
			Si pagoRealizado>=valorCompra Entonces
				aDevolver <- pagoRealizado-valorCompra;
				pagoRealizado <- pagoRealizado-valorCompra;
			SiNo
				pagoRealizado <- 0;
				Escribir 'No te alcanza';
			FinSi
		FinSi
		pos1<-pos1+1;
		Si aDevolver>=1000 Entonces
			aDevolver <- aDevolver-1000;
			pagoRealizado <- pagoRealizado-1000;
			B1000 <- B1000+1;
		SiNo
			Si aDevolver>=500 Entonces
				aDevolver <- aDevolver-500;
				pagoRealizado <- pagoRealizado-500;
				B500 <- B500+1;
			SiNo
				Si aDevolver>=200 Entonces
					aDevolver <- aDevolver-200;
					pagoRealizado <- pagoRealizado-200;
					B200 <- B200+1;
				SiNo
					Si aDevolver>=100 Entonces
						aDevolver <- aDevolver-100;
						pagoRealizado <- pagoRealizado-100;
						B100 <- B100+1;
					SiNo
						Si aDevolver>=50 Entonces
							aDevolver <- aDevolver-50;
							pagoRealizado <- pagoRealizado-50;
							B50 <- B50+1;
						FinSi
					FinSi
					
				FinSi
			FinSi
		FinSi
		Si pagoRealizado=0 Entonces
			Escribir 'Devoler ', B1000, ' Billetes de 1000';
			Escribir 'Devoler ', B500, ' Billetes de 500';
			Escribir 'Devoler ', B200, ' Billetes de 200';
			Escribir 'Devoler ', B100, ' Billetes de 100';
			Escribir 'Devoler ', B50, ' Billetes de 50';
			
			pos1<-1;
			Escribir "nuevo valor compra";
			Leer valorCompra;
			Escribir "nuevo pago realizado";
			Leer pagoRealizado;
		FinSi
		
		
		
	FinMientras
FinAlgoritmo
