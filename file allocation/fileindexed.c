#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 20
#define MAX_BLOCKS 100

typedef struct {
    int indexBlock;
    int blocks[MAX_BLOCKS];
    int length;
} IndexedFile;

IndexedFile indexedFiles[MAX_FILES];
int disk[MAX_BLOCKS]; // 0 means free, 1 means allocated

void indexedAllocation(int fileId, int length) {
    int indexBlock = -1;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (disk[i] == 0) {
            indexBlock = i;
            break;
        }
    }

    if (indexBlock == -1) {
        printf("No free index block available for file %d\n", fileId);
        return;
    }

    disk[indexBlock] = 1;
    indexedFiles[fileId].indexBlock = indexBlock;
    indexedFiles[fileId].length = length;

    int allocatedBlocks = 0;
    for (int i = 0; i < MAX_BLOCKS && allocatedBlocks < length; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            indexedFiles[fileId].blocks[allocatedBlocks] = i;
            allocatedBlocks++;
        }
    }

    if (allocatedBlocks < length) {
        printf("Not enough free blocks for file %d of length %d\n", fileId, length);
        return;
    }

    printf("File %d allocated using indexed allocation: index block %d, data blocks: ", fileId, indexBlock);
    for (int i = 0; i < length; i++) {
        printf("%d ", indexedFiles[fileId].blocks[i]);
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = 0; // Initialize all blocks as free
    }

    int fileId, length;
    printf("Indexed Allocation Strategy:\n");
    while (1) {
        printf("Enter file ID (-1 to exit): ");
        scanf("%d", &fileId);
        if (fileId == -1) break;
        printf("Enter file length: ");
        scanf("%d", &length);

        indexedAllocation(fileId, length);
    }

    return 0;
}
