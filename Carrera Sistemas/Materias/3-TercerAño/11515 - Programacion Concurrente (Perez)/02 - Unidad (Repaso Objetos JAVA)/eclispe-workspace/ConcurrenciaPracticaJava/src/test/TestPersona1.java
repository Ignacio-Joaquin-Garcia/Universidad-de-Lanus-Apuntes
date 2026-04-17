package test;

import modelo.Persona;
import modelo.Empleado;

public class TestPersona1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Persona persona1 = new Persona("Nico", 31);
		Persona persona2 = new Persona("Brenda", 22);
		System.out.println(persona1); //Imprime la Posicionde memoria de donde esta guardado
		
		persona1.numero = 3; //El numero no depende de la instancia sino de la clase
		System.out.println(persona1.numero); // 3
		System.out.println(persona2.numero); // 3
		
		Empleado e1 = new Empleado("Lopez", 23, 15.36f);
		System.out.println(e1);
		e1.funcion1(); //Hereda el Metodo
		
		
	}

}
