#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
	{
	pid_t p=fork();
	if(p<0){
		printf("Fork Failed");
		}
	else if (p==0){
		printf("Hello Child Process");
		printf("Process ID : %d",getpid());
		}
	else{
		printf("Hello Parent Process");
		printf("Process ID :%d",getpid());
		printf("Child ID :%d",p);
	}
	}
