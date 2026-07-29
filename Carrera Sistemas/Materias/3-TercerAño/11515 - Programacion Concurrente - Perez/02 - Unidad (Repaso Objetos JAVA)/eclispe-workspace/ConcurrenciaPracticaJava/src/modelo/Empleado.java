//Herencia de Persona
package modelo;
public class Empleado extends Persona{
	private float sueldo;
	
	//Constructor
	public Empleado(String nombre, int edad, float sueldo){
		super(nombre, edad); //Primero se instancia a la persona
		this.sueldo = sueldo; //despues al Empleado
	}
	
	@Override
	public String toString() {
		return super.toString() + "Empleado [sueldo=" + sueldo + "]";
	}
	
	public float getSueldo(){
		return sueldo;
	}
	public void setSueldo(float sueldo){
		this.sueldo = sueldo;
	}
}