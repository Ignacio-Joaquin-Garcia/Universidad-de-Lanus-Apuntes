package datos;

import java.util.Random;

public class Productor extends Thread {
    private Almacen buffer;
    private final String letras = "abcdefghijklmnopqrstuvxyz";

    public Productor( Almacen buffer) {
        this.buffer = buffer;
    }

    public void run() {
        while (true) {
            // Obtenemos una letra al azar
        	Random aleatorio = new Random(System.currentTimeMillis());
        	int n =  aleatorio.nextInt(letras.length());
            char c = letras.charAt(n);
            
            // Producimos un valor
            buffer.producir(c);
            
            System.out.println("Depositado el caracter " + c + " del buffer");
            
            try {
                // Esperamos entre 0 y 4 segundos 
                sleep((int) (Math.random() * 4000));
            } catch (InterruptedException e) { }
        }
    }
}