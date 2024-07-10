#include <stdio.h>
#include <stdlib.h>
int request[20],head,dis,seek=0;
void fcfs(int n){
    int i,cur;
    for(i=0;i<n;i++){
        cur=request[i];
        dis=abs(cur-head);
        seek+=dis;
        head=cur;
    }
    printf("Total head movements :%d",seek);
}
void main()
{
    int i,n;
    printf("Enter the number  of requests:");
    scanf("%d",&n);
    printf("Enter the requests");
    for(i=0;i<n;i++){
        scanf("%d",&request[i]);
    }
    printf("Enter the head position");
    scanf("%d",&head);
    fcfs(n);
}