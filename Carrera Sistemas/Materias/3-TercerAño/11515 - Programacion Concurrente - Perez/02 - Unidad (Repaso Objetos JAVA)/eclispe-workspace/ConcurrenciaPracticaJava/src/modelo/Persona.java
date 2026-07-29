package modelo;
//Implementar una Interfaz te obliga a darle formato a los metodos
public class Persona implements IVivir, IMorir {
	//public persona.variable
	//private persona.getVaraible
	//protected
	//ATRIBUTOS
	private String nombre;
	private int edad;
	
	public static int numero; //VARIABLE COMPARTIDA

	//CONSTRUCTOR
	public Persona(String nombre, int edad) {
		super(); //Llama al constructor del padre (Java igual lo agrega automaticamente))
		this.nombre = nombre;
		this.edad = edad;
	}
	
	//toString
	@Override
	public String toString() {
		return "Persona [nombre=" + nombre + ", edad=" + edad + "]";
	}
	
	//GETTERS and SETTERS
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public int getEdad() {
		return edad;
	}

	public void setEdad(int edad) {
		this.edad = edad;
	}
	
	//Metodos INTERFAZ
	public void estoyViviendo(){
		System.out.println("Esta viviendo!!");
	};
	public void estoyMuriendo(){
		System.out.println("Esta muriendo!!");
	}
	
	//Metodos
	public void funcion1(){
		System.out.println("Soy el Padre");
	}

	
	
}
