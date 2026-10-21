import java.util.Scanner;

public class FCFSScheduling
{
    static void findWaitingTime(int[] processes, int n, int[] burstTime, int[] waitingTime)
    {
        waitingTime[0] = 0; // Waiting time for the first process is 0

        // Calculate waiting time for subsequent processes
        for (int i = 1; i < n; i++) {
            waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
        }
    }

    // Function to calculate turnaround time for each process
    static void findTurnAroundTime(int[] processes, int n, int[] burstTime, int[] waitingTime, int[] turnAroundTime) {
        // Calculate turnaround time by adding burst time and waiting time
        for (int i = 0; i < n; i++) {
            turnAroundTime[i] = burstTime[i] + waitingTime[i];
        }
    }

    // Function to calculate and display average times
    static void findAverageTime(int[] processes, int n, int[] burstTime) {
        int[] waitingTime = new int[n];
        int[] turnAroundTime = new int[n];
        int totalWaitingTime = 0;
        int totalTurnAroundTime = 0;

        // Calculate waiting time of all processes
        findWaitingTime(processes, n, burstTime, waitingTime);

        // Calculate turn around time for all processes
        findTurnAroundTime(processes, n, burstTime, waitingTime, turnAroundTime);

        // Display results
        System.out.println("Processes\tBurst Time\tWaiting Time\tTurn Around Time");
        for (int i = 0; i < n; i++) {
            totalWaitingTime += waitingTime[i];
            totalTurnAroundTime += turnAroundTime[i];
            System.out.printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
        }

        System.out.printf("\n Average Waiting Time = %.2f\n", (float) totalWaitingTime / n);
        System.out.printf("Average Turn Around Time = %.2f\n", (float) totalTurnAroundTime / n);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = scanner.nextInt();

        int[] processes = new int[n];
        int[] burstTime = new int[n];

        for (int i = 0; i < n; i++) {
            processes[i] = i + 1; // Assign process IDs
            System.out.print("Enter Burst Time for Process P" + (i + 1) + ": ");
            burstTime[i] = scanner.nextInt();
        }

        findAverageTime(processes, n, burstTime);

        scanner.close();
    }
}
