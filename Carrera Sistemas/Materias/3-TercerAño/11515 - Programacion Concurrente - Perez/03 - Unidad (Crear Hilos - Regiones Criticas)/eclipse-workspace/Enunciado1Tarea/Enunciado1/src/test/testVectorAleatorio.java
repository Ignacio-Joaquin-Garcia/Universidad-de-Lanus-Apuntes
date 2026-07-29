package test;
import datos.vectorAleatorio;

public class testVectorAleatorio implements Runnable{
	//Propiedades
	vectorAleatorio vector;
	int inicio;
	int termina;
	//Constructor
	public testVectorAleatorio(vectorAleatorio vector, int inicio, int termina) {
		this.vector = vector;
		this.inicio = inicio;
		this.termina = termina;
	}
	
	public static void ProcesoPesado(vectorAleatorio vector, int inicio, int termina) {
		for(int i = inicio; i < termina; i++) {
			vector.vector[i] = vector.vector[i] * 10;
		}
	}
	
	
	
	public void run() {
		System.out.println("INICIO HILO: " + Thread.currentThread().getName());
		ProcesoPesado(vector, inicio, termina);
	}
	
	public static void main(String[] args){
		int tam = 20;
		vectorAleatorio v = new vectorAleatorio(tam);
		v.mostrarVector();
		
		
		testVectorAleatorio t1 = new testVectorAleatorio(v, 0, tam / 2);
		testVectorAleatorio t2 = new testVectorAleatorio(v, tam / 2, tam);
		
		
		Thread h1 = new Thread(t1, "1");
		Thread h2 = new Thread(t2, "2");
		
		h1.start();
		h2.start();
		
		try {
			h1.join();
			h2.join();
		}catch(Exception e) {System.out.println(e);}
		
		v.mostrarVector();
	}
}
