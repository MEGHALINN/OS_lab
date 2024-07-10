#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0, empty = 5, x = 0;

void wait(int *s) {
    while (*s <= 0)
        ;
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    wait(&mutex);
    signal(&full);
    wait(&empty);
    x++;
    printf("Produced item %d\n", x);
    signal(&mutex);
}

void consumer() {
    wait(&mutex);
    wait(&full);
    signal(&empty);
    printf("Consumed item %d\n", x);
    x--;
    signal(&mutex);
}

void main() {
    int ch;
    printf("1. Producer\n2. Consumer\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    while (ch != 3) {
        switch (ch) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("The buffer is full\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("The buffer is empty\n");
                break;
        }
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    }
}
