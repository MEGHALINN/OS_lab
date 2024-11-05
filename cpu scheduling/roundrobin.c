#include <stdio.h>
#include <stdlib.h>
 void main(){
    int i,j,n,time,remain,flag=0,ts;
    int at[10],bt[10],rt[10];
    int tottat=0,totwt=0;
    printf("Enter the number o processes :");
    scanf("%d",&n);
    remain=n;
    for(i=0;i<n;i++){
        printf("Enter arrival time burst time ");
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    printf("Enter time quantum:");
    scanf("%d",&ts);

    for(i=0,time=0;remain!=0;){
        if(rt[i]<=ts && rt[i]>0){
            time+=rt[i];
            rt[i]=0;
            flag=1;
        }
        if(rt[i]>0){
            rt[i]-=ts;
            time+=ts;
        }
        if(rt[i]==0&& flag==1){
            remain--;

            tottat +=time-at[i];
            totwt +=time-at[i]-bt[i];
            flag=0;
        }
        if(i==n-1)
            {i=0;}
        else if(at[i+1]<time){
            i++;
        }
        else
        {i=0;}
        
    }
    printf("%d%d",tottat/n,totwt/n);
 }