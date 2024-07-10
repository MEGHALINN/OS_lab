#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
	{
	pid_t p;
	p=fork();
	if(p<0)
		{
		printf("Fork Failed");
		exit(EXIT_FAILURE);
		}
	if(p==0)
		{
		printf("Child Process");
		char* args[]={"ls","-l",NULL};
		execvp(args[0],args);
		exit(EXIT_SUCCESS);
		}
	if(p>0)
		{
		printf("Parent Process");
		wait(NULL);
		}
	}
