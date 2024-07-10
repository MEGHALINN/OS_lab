#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 20
#define MAX_BLOCKS 100

typedef struct {
    int start;
    int length;
} ContiguousFile;

ContiguousFile contiguousFiles[MAX_FILES];
int disk[MAX_BLOCKS]; // 0 means free, 1 means allocated

void contiguousAllocation(int fileId, int length) {
    int start = -1;
    for (int i = 0; i < MAX_BLOCKS - length; i++) {
        int free = 1;
        for (int j = 0; j < length; j++) {
            if (disk[i + j] == 1) {
                free = 0;
                break;
            }
        }
        if (free) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        printf("No contiguous space available for file %d of length %d\n", fileId, length);
        return;
    }

    for (int i = start; i < start + length; i++) {
        disk[i] = 1;
    }

    contiguousFiles[fileId].start = start;
    contiguousFiles[fileId].length = length;

    printf("File %d allocated contiguously from block %d to %d\n", fileId, start, start + length - 1);
}

int main() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = 0; // Initialize all blocks as free
    }

    int fileId, length;
    printf("Contiguous Allocation Strategy:\n");
    while (1) {
        printf("Enter file ID (-1 to exit): ");
        scanf("%d", &fileId);
        if (fileId == -1) break;
        printf("Enter file length: ");
        scanf("%d", &length);

        contiguousAllocation(fileId, length);
    }

    return 0;
}
