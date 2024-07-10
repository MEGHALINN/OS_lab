#include <stdio.h>
#include <stdlib.h>
struct fcfs{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

void main(){
    int i,n;
    int totwt=0,tottat=0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Pid ,Burst time for process %d:",i+1);
        scanf("%d",&p[i].pid);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for(i=1;i<n;i++){
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totwt+=p[i].wtime;
        tottat+=p[i].ttime;
    }
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\n",p[i].pid,p[i].btime,p[i].wtime,p[i].ttime);
    }
    printf("Average Waiting time : %d\n",(totwt/n));
        printf("Average Turnaround Time : %d\n",(tottat/n));
}