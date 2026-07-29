package datos;

public class Almacen {
	 
    private char buffer[];
    private int siguiente;
     
    // Flags para saber el estado del buffer
    private boolean estaLlena;
    private boolean estaVacia;
 
    public Almacen(int tamanio) {
        buffer = new char[tamanio];
        siguiente = 0;
        estaLlena = false;
        estaVacia = true;
    }
 
    // Método para retirar letras del buffer
    public synchronized char consumir() {
    	
        // No se puede consumir si el buffer está vacío
        while (estaVacia == true) {
        	
            try {
                wait(); // Se sale cuando estaVacia pasa a false -- necesito un llamado a notify
                //hilo dormido!!!
                
            } catch (InterruptedException e) { }
        }
        
        
        // Decrementa la cuenta, ya que va a consumir una letra
        siguiente--;
        
        // Comprueba si se retiró la última letra
        if (siguiente == 0) {
            estaVacia = true;
        }
        
        // El buffer no puede estar lleno, porque acabamos
        // de consumir
        
        estaLlena = false;
        notifyAll(); //despierto a todos los hilos
 
        // Devuelve la letra al thread consumidor
        return (buffer[siguiente]);
    }
 
    // Método para añadir letras al buffer
    public synchronized void producir(char c) {
        // Espera hasta que haya sitio para otra letra
        while (estaLlena == true) {
            try {
            	System.out.print("Soy el productor, quiero producir: " +c+"; pero está lleno el buffer.\n");
                wait(); // Se sale cuando estaLlena cambia a false
            } catch (InterruptedException e) {
             
            }
        }
        
        
        // Añade una letra en el primer lugar disponible
        buffer[siguiente] = c;
        
        // Cambia al siguiente lugar disponible
        siguiente++;
        estaVacia = false;
        
        // Comprueba si el buffer está lleno
        
        if (siguiente == this.buffer.length) {
            estaLlena = true;
        }
        
        estaVacia = false;
        notifyAll();
    }
}