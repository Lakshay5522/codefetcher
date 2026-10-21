import java.util.concurrent.Semaphore;

public class ReadersWritersProblem {

    private final Semaphore readLock = new Semaphore(1);   // Controls access for readers (allows multiple)
    private final Semaphore writeLock = new Semaphore(1);  // Controls exclusive access for writer
    private int readersCount = 0;                          // Tracks the number of active readers

    public void startReading() throws InterruptedException {
        readLock.acquire();   // Acquire permit for reading
        synchronized (this) {
            readersCount++;

            if (readersCount == 1) {   // If first reader, block writers
                writeLock.acquire();
            }
        }
        readLock.release();   // Release permit for reading
        System.out.println(Thread.currentThread().getName() + " started reading.");
    }

    public void stopReading() throws InterruptedException {
        readLock.acquire();   // Acquire permit to modify readersCount
        synchronized (this) {
            readersCount--;
            if (readersCount == 0) {   // If last reader, unblock writers
                writeLock.release();
            }
        }
        readLock.release();   // Release permit
        System.out.println(Thread.currentThread().getName() + " stopped reading.");
    }

    public void startWriting() throws InterruptedException {
        writeLock.acquire();   // Acquire exclusive permit for writing
        System.out.println(Thread.currentThread().getName() + " started writing.");
    }

    public void stopWriting() {
        writeLock.release();   // Release exclusive permit
        System.out.println(Thread.currentThread().getName() + " stopped writing.");
    }

    public static void main(String[] args) {
        ReadersWritersProblem rw = new ReadersWritersProblem();

        // Create multiple reader threads
        for (int i = 0; i < 5; i++) {
            new Thread(() -> {
                try {
                    rw.startReading();
                    Thread.sleep(1000);   // Simulate reading
                    rw.stopReading();
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }, "Reader-" + (i + 1)).start();
        }

        // Create a writer thread
        new Thread(() -> {
            try {
                rw.startWriting();
                Thread.sleep(2000);   // Simulate writing
                rw.stopWriting();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }, "Writer-1").start();
    }
}
