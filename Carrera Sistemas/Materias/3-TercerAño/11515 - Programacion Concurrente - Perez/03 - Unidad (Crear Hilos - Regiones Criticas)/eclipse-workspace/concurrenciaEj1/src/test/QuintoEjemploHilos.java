package test;

import java.util.Random;

public class QuintoEjemploHilos {

    public static void main(String[] args) throws InterruptedException {

        int N = 20_000_000; // 🔥 grande

        int[] original = new int[N]; //1   2    1         3    1.......
        
        int[] secuencial = new int[N];// 10   20   10   30   10 ......
        int[] paralelo = new int[N];  // 10   20   10   30   10 ......

        Random r = new Random();

        // 🔹 Generar datos
        for (int i = 0; i < N; i++) {
            original[i] = r.nextInt(9) + 1;
        }

        // =========================
        // 🧘 SECUENCIAL
        // =========================
        long t1 = System.nanoTime();

        for (int i = 0; i < N; i++) {
            secuencial[i] = trabajoPesado(original[i]);
        }

        long t2 = System.nanoTime();

        // =========================
        // ⚡ PARALELO (2 HILOS)
        // =========================
        long t3 = System.nanoTime();

        Thread h1 = new Thread(() -> procesar(original, paralelo, 0, N / 4));
        Thread h2 = new Thread(() -> procesar(original, paralelo, N / 4, N / 2));
        Thread h3 = new Thread(() -> procesar(original, paralelo, N / 2, 3 * N / 4));
        Thread h4 = new Thread(() -> procesar(original, paralelo, 3 * N / 4, N));
        
        
        h1.start();
        h2.start();
        h3.start();
        h4.start();
        
        h1.join();
        h2.join();
        h3.join();
        h4.join();
        long t4 = System.nanoTime();

        // =========================
        // RESULTADOS
        // =========================
        System.out.println("🧘 Secuencial: " + (t2 - t1) / 1_000_000 + " ms");
        System.out.println("⚡ Paralelo:   " + (t4 - t3) / 1_000_000 + " ms");

        // Validación simple
        System.out.println("Chequeo: " + (secuencial[N - 1] == paralelo[N - 1]));
    }

    // 🔥 Trabajo pesado (clave)
    public static int trabajoPesado(int x) {
        int res = x;
        
        for (int i = 0; i < 100; i++) {
            res = res * 10 + 1;
            res = res / 2 + 3;
        }
        //res = res*10;
        return res;
    }

    public static void procesar(int[] origen, int[] destino, int inicio, int fin) {
        for (int i = inicio; i < fin; i++) {
            destino[i] = trabajoPesado(origen[i]);
        }
    }
}