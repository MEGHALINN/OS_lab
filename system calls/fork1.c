#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
	{
	printf("Enter the no of processes :");
	int num,i;
	pid_t p;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		p=fork();
		if(p==0){
			printf("\nChild Process : %d",getpid());
			printf("\nMy Parent is Process %d ",getppid());
			exit(EXIT_SUCCESS);
			}
		else if(p<0){
			printf("\nFork Failed");
			exit(EXIT_FAILURE);
			}
		}
	for(i=0;i<num;i++)
		wait(NULL);

//		printf("\nParent Process ID :%d",getpid());
//		printf("\nMy Child is Process %d",p);
	}
