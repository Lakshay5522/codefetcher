class TicketBooking implements Runnable
{
    public void run()
    {
        try   // If exception occurs the execution of the try block immediately stops
        {
            Thread.sleep(200);   // Causes the currently executing thread to pause
        }
        catch (InterruptedException e)   // Handles specific types of exceptions
        {
            e.printStackTrace();
        }
        System.out.println("State of bookingThread while mainThread is waiting: "
                            + TicketSystem.mainThread.getState());

        try
        {
            Thread.sleep(100);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}

public class TicketSystem implements Runnable
{
    public static Thread mainThread;
    public static TicketSystem ticketSystem;

    public void run()
    {
        TicketBooking booking = new TicketBooking();      // object creation
        Thread bookingThread = new Thread(booking);       // object creation

        System.out.println("State after creating bookingThread: " + bookingThread.getState());
        bookingThread.start();
        System.out.println("State after starting bookingThread: " + bookingThread.getState());

        try
        {
            Thread.sleep(50);
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("State after sleeping bookingThread: " + bookingThread.getState());

        try
        {
            bookingThread.join();   // Moves mainThread to waiting state
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("State after bookingThread finishes: " + bookingThread.getState());
    }

    public static void main(String[] args)
    {
        ticketSystem = new TicketSystem();
        mainThread = new Thread(ticketSystem);
        System.out.println("State after creating mainThread: " + mainThread.getState());
        mainThread.start();
        System.out.println("State after starting mainThread: " + mainThread.getState());
    }
}
