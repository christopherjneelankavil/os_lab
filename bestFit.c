#include <stdio.h>

int main(){
    int blocks[10],process[10];

    //reading blocks
    printf("Enter the no.of blocks: ");
    int blockNum;
    scanf("%d",&blockNum);
    printf("Enter the size of each blocks : \n");
    for(int i=0;i<blockNum;i++){
        scanf("%d",&blocks[i]);
    }

    //reading processes
    printf("\nEnter the no.of processes : ");
    int processNum;
    scanf("%d",&processNum);
    printf("Enter the size of each process: \n");
    for(int i=0;i<processNum;i++){
        scanf("%d",&process[i]);
    }
}