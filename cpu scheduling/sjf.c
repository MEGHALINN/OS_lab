#include <stdio.h>

struct sjf {
    int pid;
    int btime;
    int atime;
    int wtime;
    int ttime;
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
    }


    sortProcesses(p, n);

    printf("Pid\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    while (completed < n) {
        int min_btime_idx = -1;

      
        for (i = 0; i < n; i++) {
            if (p[i].atime <= current_time && p[i].btime > 0) {
                if (min_btime_idx == -1 || p[i].btime < p[min_btime_idx].btime) {
                    min_btime_idx = i;
                }
            }
        }

        if (min_btime_idx != -1) {
     
            p[min_btime_idx].wtime = current_time - p[min_btime_idx].atime;
            p[min_btime_idx].ttime = p[min_btime_idx].wtime + p[min_btime_idx].btime;

          
            totwt += p[min_btime_idx].wtime;
            tottat += p[min_btime_idx].ttime;

     
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[min_btime_idx].pid, p[min_btime_idx].btime, p[min_btime_idx].atime, p[min_btime_idx].wtime, p[min_btime_idx].ttime);

         
            current_time += p[min_btime_idx].btime;
            p[min_btime_idx].btime = -1; 
            completed++;
        } else {
            
            int next_arrival = __INT_MAX__;
            for (i = 0; i < n; i++) {
                if (p[i].atime < next_arrival && p[i].btime > 0) {
                    next_arrival = p[i].atime;
                }
            }
            current_time = next_arrival;
        }
    }

    printf("Average Waiting Time: %.2f\n", totwt / n);
    printf("Average Turnaround Time: %.2f\n", tottat / n);

    return 0;
}
