#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void main()
	{
	pid_t p;
	p=fork();
	if(p<0)
		{
		printf("Fork Failed");
		}
	else if(p==0)
		{
		printf("Child Process");
		execl("/bin/ls","ls","-l",NULL);
		}
	else
		{
		printf("Parent Process");
		printf("ID of child is %d",p);
		wait(NULL);
		}
	}
