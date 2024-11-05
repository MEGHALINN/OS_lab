#include <stdio.h>
#include <limits.h> // For INT_MAX

struct sjf {
    int pid;
    int btime;
    int atime;
    int wtime;
    int ttime;
    int completed;
};

void sortProcesses(struct sjf p[], int n) {
    struct sjf temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].atime > p[j + 1].atime) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int i, j, n, completed = 0, current_time = 0;
    float totwt = 0, tottat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct sjf p[n];
    for (i = 0; i < n; i++) {
        printf("Enter Pid, Burst time, and Arrival time for Process %d: ", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].btime, &p[i].atime);
        p[i].completed = 0; // Mark process as not completed initially
    } 

    sortProcesses(p, n);

    printf("Pid\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    while (completed < n) {
        int min_btime_idx = -1;
        int min_btime = INT_MAX;

        // Find the process with the shortest burst time that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (p[i].atime <= current_time && p[i].completed == 0 && p[i].btime < min_btime) {
                min_btime_idx = i;
                min_btime = p[i].btime;
            }
        }

        if (min_btime_idx != -1) {
            // Process is found, calculate waiting and turnaround times
            p[min_btime_idx].wtime = current_time - p[min_btime_idx].atime;
            p[min_btime_idx].ttime = p[min_btime_idx].wtime + p[min_btime_idx].btime;

            // Update totals
            totwt += p[min_btime_idx].wtime;
            tottat += p[min_btime_idx].ttime;

            // Print process info
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[min_btime_idx].pid, p[min_btime_idx].btime, p[min_btime_idx].atime, p[min_btime_idx].wtime, p[min_btime_idx].ttime);

            // Update current time and mark process as completed
            current_time += p[min_btime_idx].btime;
            p[min_btime_idx].completed = 1;
            completed++;
        } else {
            // If no process is ready, advance time to the next arrival
            int next_arrival = INT_MAX;
            for (i = 0; i < n; i++) {
                if (p[i].atime > current_time && p[i].completed == 0) {
                    if (p[i].atime < next_arrival) {
                        next_arrival = p[i].atime;
                    }
                }
            }
            current_time = next_arrival;
        }
    }

    printf("Average Waiting Time: %.2f\n", totwt / n);
    printf("Average Turnaround Time: %.2f\n", tottat / n);

    return 0;
}
