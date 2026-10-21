import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

class Producer extends Thread {
    private BlockingQueue<Integer> queue;

    Producer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    public void run() {
        try {
            for (int i = 1; i <= 5; i++) {
                System.out.println("Producer produced: " + i);
                queue.put(i);
                Thread.sleep(500);
            }

            queue.put(-1);

        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Consumer extends Thread {
    private BlockingQueue<Integer> queue;

    Consumer(BlockingQueue<Integer> queue) {
        this.queue = queue;
    }

    public void run() {
        try {
            while (true) {
                int value = queue.take();

                if (value == -1) {
                    break;
                }

                System.out.println("Consumer consumed: " + value);
                Thread.sleep(800);
            }

        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class ProducerConsumerQueue {
    public static void main(String[] args) throws InterruptedException {

        // Message queue with capacity 2
        BlockingQueue<Integer> queue = new ArrayBlockingQueue<>(2);

        Producer producer = new Producer(queue);
        Consumer consumer = new Consumer(queue);

        producer.start();
        consumer.start();

        producer.join();
        consumer.join();

        System.out.println("Producer and Consumer finished.");
    }
}
