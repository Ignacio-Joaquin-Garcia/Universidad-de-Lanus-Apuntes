package test;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class SegundoEjemploHilos {

    // Contador compartido
    static int contador = 0;

    // Objeto de lock
    static final Object lock = new Object();

    // Formateador de hora
    static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss.SSS");

    public static void main(String[] args) throws InterruptedException {

        int nucleos = Runtime.getRuntime().availableProcessors();
        System.out.println("Núcleos lógicos: " + nucleos);

        MiHilo[] hilos = new MiHilo[nucleos];

        // 🔹 1. CREACIÓN
        for (int i = 0; i < nucleos; i++) {
            hilos[i] = new MiHilo(i);
        }

        // 🔹 2. LANZAMIENTO
        for (int i = 0; i < nucleos; i++) {
            hilos[i].start();
        }

        // 🔹 3. ESPERA
        for (int i = 0; i < nucleos; i++) {
            hilos[i].join();
        }

        // 🔹 4. RESULTADOS
        int esperado = nucleos * 10000;

        System.out.println("\n--- RESULTADOS ---");
        System.out.println("Valor esperado: " + esperado);
        System.out.println("Valor real:     " + contador);
    }

    // 🔸 Clase del hilo
    static class MiHilo extends Thread {

        private int id;

        public MiHilo(int id) {
            this.id = id;
        }

        @Override
        public void run() {
            System.out.println(timestamp() + " 🟢 Hilo " + id + " INICIADO");
            ejecutarConteo();
            System.out.println(timestamp() + " 🔴 Hilo " + id + " FINALIZADO");
        }
    }

    // 🔸 Lógica con sincronización
    public static void ejecutarConteo() {
        for (int i = 0; i < 10000; i++) {
            synchronized (lock) {
                contador++; // ✅ ahora protegido
            }
        }
    }

    // 🔸 Timestamp
    public static String timestamp() {
        return LocalTime.now().format(formatter);
    }
}