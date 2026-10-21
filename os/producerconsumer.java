import java.util.concurrent.Semaphore;

public class ProducerConsumer {

    // Shared memory (buffer)
    static int[] buffer = new int[5];

    static int in = 0;
    static int out = 0;

    // Semaphores
    static Semaphore empty = new Semaphore(5);
    static Semaphore full = new Semaphore(0);
    static Semaphore mutex = new Semaphore(1);

    // Producer
    static class Producer extends Thread {
        public void run() {
            for (int i = 1; i <= 10; i++) {
                try {
                    empty.acquire();   // Wait for empty space
                    mutex.acquire();   // Enter critical section

                    buffer[in] = i;
                    System.out.println("Producer produced: " + i);
                    in = (in + 1) % buffer.length;

                    mutex.release();   // Leave critical section
                    full.release();    // Increase full count

                    Thread.sleep(500);

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    // Consumer
    static class Consumer extends Thread {
        public void run() {
            for (int i = 1; i <= 10; i++) {
                try {
                    full.acquire();    // Wait for an item
                    mutex.acquire();   // Enter critical section

                    int item = buffer[out];
                    System.out.println("Consumer consumed: " + item);

                    out = (out + 1) % buffer.length;

                    mutex.release();   // Leave critical section
                    empty.release();   // Increase empty count

                    Thread.sleep(800);

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Producer producer = new Producer();
        Consumer consumer = new Consumer();

        producer.start();
        consumer.start();

        producer.join();
        consumer.join();

        System.out.println("Producer-Consumer execution completed.");
    }
}
