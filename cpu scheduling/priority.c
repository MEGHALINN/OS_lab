#include <stdio.h>

struct Process{
    int pid;
    int atime;
    int btime;
    int priority;
};

void sortprocesses(struct Process p[],int n){
    struct Process temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].atime>p[j].atime || (p[i].atime==p[j].atime && p[i].priority>p[j].priority)){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

void calcandprint(struct Process p[],int n){
    int wt[n],tat[n];
    int pstart=0;
    wt[0]=0;
    float avwt=0,avtat=0;
    for(int i=1;i<n;i++){
        pstart+=p[i-1].btime;
        wt[i]=pstart-p[i].atime;
        avwt+=wt[i];
    }

    for(int i=0;i<n;i++){
        tat[i]=wt[i]+p[i].btime;
        avtat+=tat[i];
    }
    avwt=avwt/n;
    avtat=avtat/n;
    printf("PID\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].atime,p[i].btime,wt[i],tat[i]);
    }
    printf("Average Waiting Time: %f\n",avwt);
    printf("Average Turnaround Time: %f\n",avtat);
}

void main(){
    int n;
    printf("ENter the total number of processes:");
    scanf("%d",&n);
    struct Process p[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time, burst time and priority of process %d:",i+1);
        p[i].pid=i+1;
        scanf("%d %d %d",&p[i].atime,&p[i].btime,&p[i].priority);
    }
    sortprocesses(p,n);
    calcandprint(p,n);
}