public class RaceCondition {
    static int counter = 0;

    // Method without synchronization
    static class UnsafeCounter extends Thread {
        public void run() {
            for (int i = 0; i < 1000; i++) {
                counter++;
            }
        }
    }

    // Method with synchronization
    static class SafeCounter extends Thread {
        public void run() {
            for (int i = 0; i < 1000; i++) {
                increment();
            }
        }
    }

    // Synchronized method prevents race condition
    static synchronized void increment() {
        counter++;
    }

    public static void main(String[] args) throws InterruptedException {

        // -------- Race Condition --------
        counter = 0;

        Thread t1 = new UnsafeCounter();
        Thread t2 = new UnsafeCounter();

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Without synchronization:");
        System.out.println("Counter = " + counter);
        System.out.println("Expected = 2000");

        // -------- Avoiding Race Condition --------
        counter = 0;

        Thread t3 = new SafeCounter();
        Thread t4 = new SafeCounter();

        t3.start();
        t4.start();

        t3.join();
        t4.join();

        System.out.println("\nWith synchronization:");
        System.out.println("Counter = " + counter);
        System.out.println("Expected = 2000");
    }
}
