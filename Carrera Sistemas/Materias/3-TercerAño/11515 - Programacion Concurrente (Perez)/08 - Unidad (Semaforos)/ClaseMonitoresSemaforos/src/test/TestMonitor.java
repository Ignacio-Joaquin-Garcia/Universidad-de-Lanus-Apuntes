package test;

import datos.Almacen;
import datos.Consumidor;
import datos.Productor;

public class TestMonitor {
	 
    public static void main(String[] args) {
    	
        Almacen b = new Almacen(2);
        
        Productor p = new Productor(b);
        Consumidor c = new Consumidor(b);
        
        p.start();
		c.start();
    }
}