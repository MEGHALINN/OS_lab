#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Enter the number of processes: ");
    int num, i;
    pid_t p;
    scanf("%d", &num);

    for(i = 0; i < num; i++) {
        p = fork();

        if (p < 0) {
            printf("\nFork Failed");
            exit(EXIT_FAILURE);
        } else if (p == 0) {
            printf("\nChild Process: %d", getpid());
            printf("\nMy Parent is Process: %d\n", getppid());
            exit(EXIT_SUCCESS);
        }
    }

    for(i = 0; i < num; i++)
        wait(NULL);

    printf("\nParent Process ID: %d", getpid());
    printf("\nLast Forked Child Process ID: %d\n", p);

    return 0;
}
