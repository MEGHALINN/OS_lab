#include <stdio.h>
#include <stdlib.h>

struct fcfs {
    int pid;
    int atime;
    int btime;
    int ctime;
    int wtime;
    int ttime;
} p[10];

void main() {
    int i, j, n, totwt = 0, tottat = 0;
    
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("Enter PId, Arrival Time, Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("For Process %d: ", i);
        scanf("%d %d %d", &p[i].pid, &p[i].atime, &p[i].btime);
    }

    struct fcfs temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].atime > p[j].atime) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

  
    p[0].wtime = 0;
    p[0].ctime = p[0].btime + p[0].atime;
    p[0].ttime = p[0].ctime - p[0].atime;
    
    for (i = 1; i < n; i++) {
        p[i].ctime = (p[i-1].ctime > p[i].atime ? p[i-1].ctime : p[i].atime) + p[i].btime;
        p[i].ttime = p[i].ctime - p[i].atime;
        p[i].wtime = p[i].ttime - p[i].btime;
        totwt += p[i].wtime;
        tottat += p[i].ttime;
    }


    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround");
    for (i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].atime, p[i].btime, p[i].wtime, p[i].ttime);
    }

    printf("\nTotal Waiting Time: %d", totwt);
    printf("\nTotal Turnaround Time: %d", tottat);
    printf("\nAverage Waiting Time: %.2f", (float)totwt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)tottat / n);
}
