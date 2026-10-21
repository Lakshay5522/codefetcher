import java.time.Instant;
import java.time.Duration;

public class InstantTimer {
    public static void methodToBeTimed() {
        // Simulated code
        try {
            Thread.sleep(1500); // Simulate a medium delay
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public static void main(String[] args) {
        Instant start = Instant.now();
        methodToBeTimed();
        Instant end = Instant.now();
        Duration timeElapsed = Duration.between(start, end);
        System.out.println("Execution time: " + timeElapsed.toMillis() + " milliseconds");
    }
}
