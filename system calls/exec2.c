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
                char* args[]={"/bin/env",NULL};
		char* envp[]={"MY VARIABLE=Hello World","PATH=/bin:/bin",NULL};
                execve("/bin/env",args,envp);
                exit(EXIT_SUCCESS);
                }
        if(p>0)
                {
                printf("Parent Process");
                wait(NULL);
                }
        }
