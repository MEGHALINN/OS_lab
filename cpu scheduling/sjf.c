#include <stdio.h>
#include <stdlib.h>

struct sjf {
  int pid;
  int btime;
  int atime;  // Added arrival time
  int wtime;
  int ttime;
};

void sort_by_arrival_and_burst(struct sjf *p, int n) {
  struct sjf temp;
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (p[j].atime > p[j + 1].atime ||
          (p[j].atime == p[j + 1].atime && p[j].btime > p[j + 1].btime)) {
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
}

int main() {
  int i, j, n, completed = 0, current_time = 0;
  struct sjf temp;
  float totwt = 0, tottat = 0;

  printf("Enter the no of processes :");
  scanf("%d", &n);

  struct sjf p[10];
  for (i = 0; i < n; i++) {
    printf("Enter Pid, Burst time and Arrival time for Process %d:", i + 1);
    scanf("%d %d %d", &p[i].pid, &p[i].btime, &p[i].atime);
  }

  sort_by_arrival_and_burst(p, n);  // Sort by arrival time (primary) and burst time (secondary)

  printf("Pid\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; completed < n; i++) {
    if (p[i].atime <= current_time) {
      p[i].wtime = current_time - p[i].atime;
      p[i].ttime = p[i].wtime + p[i].btime;
      totwt += p[i].wtime;
      tottat += p[i].ttime;
      current_time += p[i].btime;
      printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].btime, p[i].atime, p[i].wtime, p[i].ttime);
      completed++;
    }
  }

  printf("Average Waiting Time: %.2f\n", totwt / n);
  printf("Average Turnaround Time: %.2f\n", tottat / n);

  return 0;
}
