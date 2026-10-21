import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ArrayBlockingQueue;

public class CompareCommunication {

    // Shared memory example
    static int sharedData = 0;

    static class SharedProducer extends Thread {
        public void run() {
            for (int i = 1; i <= 5; i++) {
                synchronized (CompareCommunication.class) {
                    sharedData = i;
                    System.out.println("Shared Memory - Producer: " + i);
                }
            }
        }
    }

    static class SharedConsumer extends Thread {
        public void run() {
            for (int i = 1; i <= 5; i++) {
                synchronized (CompareCommunication.class) {
                    System.out.println(
                        "Shared Memory - Consumer: " + sharedData
                    );
                }
            }
        }
    }

    // Message passing example
    static class MessageProducer extends Thread {
        private BlockingQueue<Integer> queue;

        MessageProducer(BlockingQueue<Integer> queue) {
            this.queue = queue;
        }

        public void run() {
            try {
                for (int i = 1; i <= 5; i++) {
                    queue.put(i);
                    System.out.println(
                        "Message Passing - Producer: " + i
                    );
                }
                queue.put(-1);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    static class MessageConsumer extends Thread {
        private BlockingQueue<Integer> queue;

        MessageConsumer(BlockingQueue<Integer> queue) {
            this.queue = queue;
        }

        public void run() {
            try {
                while (true) {
                    int data = queue.take();

                    if (data == -1)
                        break;

                    System.out.println(
                        "Message Passing - Consumer: " + data
                    );
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {

        System.out.println("=== SHARED MEMORY ===");

        Thread producer1 = new SharedProducer();
        Thread consumer1 = new SharedConsumer();

        producer1.start();
        producer1.join();

        consumer1.start();
        consumer1.join();

        System.out.println("\n=== MESSAGE PASSING ===");

        BlockingQueue<Integer> queue =
            new ArrayBlockingQueue<>(5);

        Thread producer2 = new MessageProducer(queue);
        Thread consumer2 = new MessageConsumer(queue);

        producer2.start();
        consumer2.start();

        producer2.join();
        consumer2.join();

        System.out.println("\nProgram completed.");
    }
}
