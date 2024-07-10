#include <stdio.h>
#include <stdlib.h>

struct roundrobin {
    int pid;
    int atime;
    int btime;
    int wtime;
    int ttime;
    int priority;  // Added priority field
} p[10];

void main() {
    int i, j, n, totwt = 0, tottat = 0;
    struct roundrobin temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int remain = n;
    for (i = 0; i < n; i++) {
        printf("Enter PID, Arrival time, Burst time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d %d", &p[i].pid, &p[i].atime, &p[i].btime, &p[i].priority);
    }
    int tq;
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Sort processes by arrival time, then by priority (lower number indicates higher priority)
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].atime > p[j].atime || (p[i].atime == p[j].atime && p[i].priority > p[j].priority)) {
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
        int highest_priority_index = -1;

        // Find the process with the highest priority that has arrived
        for (j = 0; j < n; j++) {
            if (p[j].atime <= time && rt[j] > 0) {
                if (highest_priority_index == -1 || p[j].priority < p[highest_priority_index].priority) {
                    highest_priority_index = j;
                }
            }
        }

        if (highest_priority_index != -1) {
            i = highest_priority_index;
            if (rt[i] <= tq) {
                time += rt[i];
                rt[i] = 0;
                flag = 1;
            } else {
                rt[i] -= tq;
                time += tq;
            }

            if (rt[i] == 0 && flag == 1) {
                remain--;
                p[i].wtime = time - p[i].atime - p[i].btime;
                p[i].ttime = time - p[i].atime;
                totwt += p[i].wtime;
                tottat += p[i].ttime;
                flag = 0;
            }
        } else {
            time++;
        }
    }

    printf("Pid\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].atime, p[i].btime, p[i].priority, p[i].wtime, p[i].ttime);
    }

    printf("Average Waiting Time: %.2f\n", (float) totwt / n);
    printf("Average Turnaround Time: %.2f\n", (float) tottat / n);
}
