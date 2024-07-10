#include <stdio.h>
#include <stdlib.h>

void main() {
    int req[20], head, seek = 0, n, i, size, move, temp, j;

    // Input the number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    // Input the requests
    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    // Input the initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Input the total size of disk
    printf("Enter the total size of disk: ");
    scanf("%d", &size);

    // Sorting requests in ascending order (Bubble Sort)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    // Finding the index where head initially is
    int index = 0;
    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            index = i;
            break;
        }
    }

    // C-SCAN logic (Moving right only)
    // Moving towards larger requests first
    for (i = index; i < n; i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }
    // Moving to the end of the disk
    seek += abs(head - (size - 1));
    head = size - 1;

    // Jumping to the beginning of the disk
    seek += abs(head - 0);
    head = 0;

    // Continuing towards larger requests
    for (i = 0; i < index; i++) {
        seek += abs(head - req[i]);
        head = req[i];
    }

    printf("Total head movements: %d\n", seek);
}
