import java.io.*;
import java.util.*;

public class ThreadJoining extends Thread {
    public void run() {
        for (int i = 1; i <= 4; i++) {
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println(e);
            }
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        ThreadJoining th1 = new ThreadJoining();
        ThreadJoining th2 = new ThreadJoining();
        ThreadJoining th3 = new ThreadJoining();

        th1.start();
        try {
            th1.join();
        } catch (Exception e) {
            System.out.println(e);
        }

        th2.start();
        try {
            th2.join();
        } catch (Exception e) {
            System.out.println(e);
        }

        th3.start();
        try {
            th3.join();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
