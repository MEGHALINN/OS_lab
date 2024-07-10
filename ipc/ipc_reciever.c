#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main(){
    void *sharedmem;
    int shmid;
    shmid=shmget((key_t)1222,1024,0666);
    sharedmem=shmat(shmid,NULL,0);
    char *ptr;
    while(*ptr!='\0'){
        printf("%c\n",*ptr);
        ptr++;
        }
}