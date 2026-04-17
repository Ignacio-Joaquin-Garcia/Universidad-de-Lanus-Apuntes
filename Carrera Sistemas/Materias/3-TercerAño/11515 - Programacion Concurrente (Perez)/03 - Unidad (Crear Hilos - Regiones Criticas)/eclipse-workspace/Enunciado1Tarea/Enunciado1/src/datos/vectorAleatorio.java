package datos;

import java.util.Random;

public class vectorAleatorio {
	//Propiedades
	private int tam;
	public int[] vector;
	Random r = new Random();
	//Constructor
	public vectorAleatorio(int tam){
		this.tam = tam;
		this.vector = new int[tam];
		for(int i = 0; i < this.tam; i++) {
			this.vector[i] = r.nextInt(0, 101);
		}
	}
	//Metodos
	public void mostrarVector() {
		System.out.print("Vector Aleatorio: ");
		for(int i = 0; i < tam; i++) {
			System.out.print(vector[i] + ", ");
		}
		System.out.print("\n\n");
	}
	
}
