#include <stdio.h>
#include <stdlib.h>
#define maxpages 20
#define maxframes 3
int frames[maxframes];
int counter[maxframes];

void initialize(){
    for(int i=0;i<maxframes;i++){
        frames[i]=-1;
        counter[i]=0;
    }
}

void displayframes() {
    printf("\n");
    for (int i = 0; i < maxframes; i++) {
        if (frames[i] != -1) {
            printf("%d\t", frames[i]);
        } else {
            printf("-\t");
        }
    }
}

int findlru(){
    int max=counter[0];
    int lruframe=0;
    for(int i=0;i<maxframes;i++){
        if(counter[i]>max){
            max=counter[i];
            lruframe=i;
        }
    }
    return lruframe;
}
void lru(int pages[],int n){
    int pagefaults=0;
    for(int i=0;i<n;i++){
        int page=pages[i];
        int found=0;
        for(int j=0;j<maxframes;j++){
            if(frames[j]==page){
                found=1;
                printf("Page %d is already in memory",page);
                break;
            }
        }
        if(!found){
            pagefaults++;
            int lruframe=findlru();
            frames[lruframe]=page;
            counter[lruframe]=0;

        }
        for(int j=0;j<maxframes;j++){
            counter[j]++;
        }
        for(int j=0;j<maxframes;j++){
            if(frames[j]==page){
                counter[j]=0;
                break;
            }
        }
        displayframes();
    }
    printf("Page ffaults :%d",pagefaults);
}
void main(){
    int pages[maxpages];
    int i,n;
    printf("Enter the no of pages:");
    scanf("%d",&n);
    printf("Enter the page sequence:");
    for(i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    initialize();
    lru(pages,n);
}