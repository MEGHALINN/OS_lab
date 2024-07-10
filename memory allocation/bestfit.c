#include <stdio.h>
#include <stdlib.h>
#define max 10

void main() {
    int block[max], process[max], b, n, i, j, bestIndex;
    printf("Enter the number of blocks: ");
    scanf("%d", &b);
    for (i = 0; i < b; i++) {
        printf("Enter the size of block %d: ", i + 1);
        scanf("%d", &block[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &process[i]);
    }
    for (i = 0; i < n; i++) {
        bestIndex = -1;
        for (j = 0; j < b; j++) {
            if (block[j] >= process[i]) {
                if (bestIndex == -1 || block[j] < block[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            printf("Process %d is allocated to block %d\n", i + 1, bestIndex + 1);
            block[bestIndex] -= process[i];
        } else {
            printf("Process %d cannot be allocated\n", i + 1);
        }
    }
}
