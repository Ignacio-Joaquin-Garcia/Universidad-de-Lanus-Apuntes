package datos;


import java.util.concurrent.Semaphore;



public class Almacen {

	//20 lugares para producir "Buffer"
    private final int MAX_LIMITE = 20;
    
    private int producto = 0;
    
    //Cuantos productores pueden producir en este momento
    private Semaphore productor = new Semaphore(MAX_LIMITE);
    //Cuantos pueden consumir
    private Semaphore consumidor = new Semaphore(0);
    //Cuantos pueden acceder a la región critica
    private Semaphore mutex = new Semaphore(1);

    public void producir(String nombreProductor) {
    	
        System.out.println(nombreProductor + " intentando almacenar un producto.");
        try {
            
        	
        		
                productor.acquire();//Si el semaforo no está en cero
                //decrementa y agarra el "recurso"
                
                mutex.acquire();//Si el semaforo no está en cero
                //decrementa y agarra el "recurso"
                

                producto++;
                
                System.out.println(nombreProductor + " almacena un producto. "
                        + "Almacén con " + producto +" productos.");
                
                mutex.release();//devuelve el semaforo, aumenta el contador

                Thread.sleep(500); //Tiempo producción
           
        } catch (InterruptedException ex) {
        	System.out.println("ERROR: "+Almacen.class.getName());
        } finally {
        	//el semaforo de consumidor aumenta en uno, porque hay un nuevo producto.
            consumidor.release();
        }

    }

    public void consumir(String nombreConsumidor) {
        System.out.println(nombreConsumidor + " intentando retirar un producto");
        try {
            
                consumidor.acquire();
                mutex.acquire();

                producto--;
                System.out.println(nombreConsumidor + " retira un producto. "
                        + "Almacén con " + producto +" productos.");
                mutex.release();

                Thread.sleep(50); //Tiempo consumo
        } catch (InterruptedException ex) {
            System.out.println("ERROR: "+Almacen.class.getName());
        } finally {
            productor.release();

        }
    }

}