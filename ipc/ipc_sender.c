#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include  <sys/shm.h>
#include <string.h>
#include <unistd.h>

void main(){
    void *sharedmem;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
    sharedmem=shmat(shmid,NULL,0);
    printf("Enter data to write to shared memory");
    scanf("%s",buff);
    strcpy(sharedmem,buff);
    printf("Data Written");
}