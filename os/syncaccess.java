class Counter   // variable
{
    private int c = 0;   // Shared variable

    // Method with synchronization block
    public void inc()
    {
        synchronized (this)
        {
            c++;
        }
    }

    public int get()
    {
        return c;
    }
}

public class SynchronizedAccess1
{
    public static void main(String[] args)
    {
        Counter cnt = new Counter();

        // Thread 1 to increment counter
        Thread t1 = new Thread(() ->
        {
            for (int i = 0; i < 1000; i++)
            {
                cnt.inc();
            }
        });

        // Thread 2 to increment counter
        Thread t2 = new Thread(() ->
        {
            for (int i = 0; i < 1000; i++)
            {
                cnt.inc();
            }
        });

        // Start both threads
        t1.start();
        t2.start();

        // Wait for threads to finish
        try
        {
            t1.join();
            t2.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }

        // Print final counter value
        System.out.println("Counter: " + cnt.get());
    }
}
