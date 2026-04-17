package test;

import java.util.concurrent.atomic.AtomicInteger;

public class CuartoEjemploHilos {

    static int contador = 0;
    static final Object lock = new Object();
    static AtomicInteger contadorAtomico = new AtomicInteger(0);

    public static void main(String[] args) throws InterruptedException {

        int hilos = Runtime.getRuntime().availableProcessors();
        int iteraciones = 1_000_000; // 🔥 subir carga
        int totalEsperado = hilos * iteraciones;

        System.out.println("Núcleos: " + hilos);
        System.out.println("Iteraciones: " + iteraciones);
        System.out.println();

        // ❌ SIN SYNC
        contador = 0;
        long t1 = System.nanoTime();
        ejecutar(hilos, iteraciones, 0);
        long t2 = System.nanoTime();

        System.out.println("❌ SIN SYNC");
        System.out.println("Real: " + contador);
        System.out.println("Tiempo: " + (t2 - t1) + " ns\n");

        // ⚠️ SYNC
        contador = 0;
        long t3 = System.nanoTime();
        ejecutar(hilos, iteraciones, 1);
        long t4 = System.nanoTime();

        System.out.println("⚠️ SYNC");
        System.out.println("Real: " + contador);
        System.out.println("Tiempo: " + (t4 - t3) + " ns\n");

        // 🚀 ATOMIC
        contadorAtomico.set(0);
        long t5 = System.nanoTime();
        ejecutar(hilos, iteraciones, 2);
        long t6 = System.nanoTime();

        System.out.println("🚀 ATOMIC");
        System.out.println("Real: " + contadorAtomico.get());
        System.out.println("Tiempo: " + (t6 - t5) + " ns\n");

        // 🧘 SECUENCIAL
        long t7 = System.nanoTime();
        int c = 0;
        for (int i = 0; i < totalEsperado; i++) {
            c++;
        }
        long t8 = System.nanoTime();

        System.out.println("🧘 SECUENCIAL");
        System.out.println("Real: " + c);
        System.out.println("Tiempo: " + (t8 - t7) + " ns\n");
    }

    static void ejecutar(int hilos, int iteraciones, int tipo) throws InterruptedException {

        Thread[] arr = new Thread[hilos];

        for (int i = 0; i < hilos; i++) {
            arr[i] = new Thread(() -> {
                for (int j = 0; j < iteraciones; j++) {

                    switch (tipo) {
                        case 0: contador++; break;

                        case 1:
                            synchronized (lock) {
                                contador++;
                            }
                            break;

                        case 2:
                            contadorAtomico.incrementAndGet();
                            break;
                    }

                    // 🔥 opcional: agranda el caos
                    // try { Thread.sleep(0); } catch (Exception e) {}
                }
            });
        }

        for (Thread t : arr) t.start();
        for (Thread t : arr) t.join();
    }
}