#include <stdio.h>
#include <stdlib.h>
#define max 10

void main(){
    int block[max],process[max],n,b,i,j;
    printf("Enter the number of blocks");
    scanf("%d",&b);
    for(i=0;i<b;i++){
        printf("Enter the size of block %d",i+1);
        scanf("%d",&block[i]);
    }
    printf("Enter the number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the size of process %d",i+1);
        scanf("%d",&process[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<b;j++){
            if(process[i]<=block[j]){
                printf("Process %d is allocated to block %d",i+1,j+1);
                block[j]=block[j]-process[i];
                break;
            }
        }
    }
}