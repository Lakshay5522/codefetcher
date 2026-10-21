import java.util.Scanner;

public class ProcessScheduling {
    public static void main(String[] args) {
        int n, burst_time[], waiting_time[], turnaround_time[];
        float avg_waiting_time = 0, avg_turnaround_time = 0;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total number of processes (maximum 20): ");
        n = sc.nextInt();
        burst_time = new int[n];
        waiting_time = new int[n];
        turnaround_time = new int[n];

        System.out.println("\nEnter Process Burst Time");
        for (int i = 0; i < n; i++) {
            System.out.print("P[" + (i + 1) + "]: ");
            burst_time[i] = sc.nextInt();
        }

        waiting_time[0] = 0; // Waiting time for first process is 0

        // Calculating waiting time
        for (int i = 1; i < n; i++) {
            waiting_time[i] = 0;
            for (int j = 0; j < i; j++) {
                waiting_time[i] += burst_time[j];
            }
        }

        // Calculating turnaround time by adding burst_time and waiting_time
        for (int i = 0; i < n; i++) {
            turnaround_time[i] = burst_time[i] + waiting_time[i];
            avg_turnaround_time += turnaround_time[i];
        }

        avg_turnaround_time /= n;
        System.out.println("\nAverage Turnaround Time: " + avg_turnaround_time + "ms");

        // Calculating average waiting time
        for (int i = 0; i < n; i++) {
            avg_waiting_time += waiting_time[i];
        }

        avg_waiting_time /= n;
        System.out.println("\nAverage Waiting Time: " + avg_waiting_time + "ms\n");

        System.out.println("Process\tBurst Time\tWaiting Time\tTurnaround Time");
        for (int i = 0; i < n; i++) {
            System.out.println("P[" + (i + 1) + "]\t" + burst_time[i] + "\t\t" + waiting_time[i] + "\t\t" + turnaround_time[i]);
        }

        sc.close();
    }
}
