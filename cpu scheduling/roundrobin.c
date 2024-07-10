#include <stdio.h>
#include <stdlib.h>

struct roundrobin {
    int pid;
    int atime;
    int btime;
    int wtime;
    int ttime;
} p[10];

void main() {
    int i, j, n, totwt = 0, tottat = 0;
    struct roundrobin temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int remain = n;
    for (i = 0; i < n; i++) {
        printf("Enter PID, Arrival time, Burst time for Process %d: ", i + 1);
        // Combined scanf calls
        scanf("%d %d %d", &p[i].pid, &p[i].atime, &p[i].btime);
    }
    int tq;
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Sort processes by arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].atime > p[j].atime) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0, flag = 0;
    int rt[10];
    for (i = 0; i < n; i++) {
        rt[i] = p[i].btime;
    }

    i = 0;
    while (remain != 0) {
        // Corrected handling of remaining time
        if (rt[i] > 0 && rt[i] <= tq) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            p[i].wtime = time - p[i].atime - p[i].btime;
            p[i].ttime = time - p[i].atime;
            // Corrected accumulation of waiting and turnaround times
            totwt += p[i].wtime;
            tottat += p[i].ttime;
            flag = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (p[i + 1].atime <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    printf("Pid\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        // Adjusted output format
        printf("\nP%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].atime, p[i].btime, p[i].wtime, p[i].ttime);
    }

    // Added floating-point average calculations
    printf("Average Waiting Time: %.2f\n", (float) totwt / n);
    printf("Average Turnaround Time: %.2f\n", (float) tottat / n);
}
