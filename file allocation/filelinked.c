#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 20
#define MAX_BLOCKS 100

typedef struct LinkedBlock {
    int blockNumber;
    struct LinkedBlock* next;
} LinkedBlock;

typedef struct {
    int fileId;
    LinkedBlock* start;
} LinkedFile;

LinkedFile linkedFiles[MAX_FILES];
int disk[MAX_BLOCKS]; // 0 means free, 1 means allocated

void linkedAllocation(int fileId, int length) {
    LinkedBlock* head = NULL;
    LinkedBlock* current = NULL;

    for (int i = 0; i < length; i++) {
        int block = -1;
        for (int j = 0; j < MAX_BLOCKS; j++) {
            if (disk[j] == 0) {
                block = j;
                break;
            }
        }

        if (block == -1) {
            printf("Not enough free blocks for file %d of length %d\n", fileId, length);
            return;
        }

        disk[block] = 1;
        LinkedBlock* newBlock = (LinkedBlock*)malloc(sizeof(LinkedBlock));
        newBlock->blockNumber = block;
        newBlock->next = NULL;

        if (head == NULL) {
            head = newBlock;
            current = newBlock;
        } else {
            current->next = newBlock;
            current = newBlock;
        }
    }

    linkedFiles[fileId].fileId = fileId;
    linkedFiles[fileId].start = head;

    printf("File %d allocated using linked allocation: ", fileId);
    current = head;
    while (current != NULL) {
        printf("%d ", current->blockNumber);
        current = current->next;
    }
    printf("\n");
}

int main() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i] = 0; // Initialize all blocks as free
    }

    int fileId, length;
    printf("Linked Allocation Strategy:\n");
    while (1) {
        printf("Enter file ID (-1 to exit): ");
        scanf("%d", &fileId);
        if (fileId == -1) break;
        printf("Enter file length: ");
        scanf("%d", &length);

        linkedAllocation(fileId, length);
    }

    return 0;
}
