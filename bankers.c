#include <stdio.h>
#include <stdlib.h>
void main()
    {
    int i,j,k,y,n,m,ind=0,alloc[20][20],max[20][20],avail[20];
    printf("Enterthe no of processes:");
    scanf("%d",&n);
    printf("Enter the no of resources");
    scanf("%d",&m);
    printf("Enter the allocation matrix");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);
        }
    printf("Enter the max matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    }
    printf("Enter the available matrix:");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);
    int work[m],finish[n],need[n][m],safesequence[n];
    printf("Need matrix is\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)
        work[i]=avail[i];
    for(i=0;i<n;i++)
        finish[i]=0;
    for(k=0;k<n;k++)
        {
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
            if(flag==0){
                safesequence[ind++]=i;
                for(y=0;y<m;y++)
                    work[y]+=alloc[i][y];
                finish[i]=1;
                    }
                }
            }
        }
        printf("The safe sequence is:");
            for(i=0;i<n;i++)
                printf("P%d,",safesequence[i]);
    }
