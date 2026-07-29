package test;

import datos.Almacen;
import datos.Consumidor;
import datos.Productor;

public class TestProductoConsumidor {

    public static void main(String[] args) {
    	
        final int CANT_PRODUCTORES = 3;
        final int CANT_CONSUMIDORES = 10;

        Almacen almacen = new Almacen();
        
        for (int i = 0; i < CANT_PRODUCTORES; i++) {
            new Productor("Productor " + i, almacen).start();
        }
        
        for (int i = 0; i < CANT_CONSUMIDORES; i++) {
            new Consumidor("Consumidor " + i, almacen).start();
        }
    }
    
}