#include <stdio.h>
#include <stdlib.h>


void main(){
    int req[20],head,seek=0,n,i,size,move,temp,j;
    printf("Enter the no of requests :");
    scanf("%d",&n);
    printf("Enter the requests :");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);
    printf("Enter the initial head position :");
    scanf("%d",&head);
    printf("Enter the total size of disk :");
    scanf("%d",&size);
    printf("Enter the direction 0 :left,1:right :");
    scanf("%d",&move);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    int index=0;
    for(i=0;i<n;i++){
        if(req[i]>=head){
            index=i;
            break;
        }
    }

    if(move==0){
        for(i=index-1;i>=0;i--){
            seek+=abs(head-req[i]);
            head=req[i];
        }
        //last movement
        seek+=abs(head-0);
        head=0;

        for(i=index;i<n;i++){
            seek+=abs(head-req[i]);
            head=req[i];
        }
        printf("Total head movements:%d",seek);
    }

    if(move ==1){
        for(i=index;i<n;i++){
            seek+=abs(head-req[i]);
            head=req[i];
        }
        //last movement
        seek+=abs(head-(size-1));
        head=size-1;

        for(i=index-1;i>=0;i--){
            seek+=abs(head-req[i]);
            head=req[i];
        }
        printf("Total head movements :%d",seek);
    }
}