package datos;

public class Consumidor extends Thread {
	 
    private Almacen buffer;
 
    public Consumidor(Almacen buffer) {
        this.buffer = buffer;
    }
 
    public void run() {
 
        while (true) {
            // Consume el valor si es posible
            char valor = buffer.consumir();
            System.out.println("Recogido el caracter " + valor + " del buffer");
            try {
                // Esperamos  4 segundos
                sleep(50);
            } catch (InterruptedException e) { }
        }
    }
}