#include<stdio.h>

void worstFit(int blocks[],int blockNum,int process[],int processNum);

int main(){
    int blocks[10],process[10];

    //reading blocks 
    int blockNum;
    printf("Enter the no.of blocks: ");
    scanf("%d",&blockNum);
    printf("Enter the block size:\n");
    for(int i=0;i<blockNum;i++){
        scanf("%d",&blocks[i]);
    }

    //reading processes
    int processNum;
    printf("Enter the no.of processes: ");
    scanf("%d",&processNum);
    printf("Enter the process size: \n");
    for(int i=0;i<processNum;i++){
        scanf("%d",&process[i]);
    }

    //passing values to worst fit
    worstFit(blocks,blockNum,process,processNum);
    return 0;
}

void worstFit(int blocks[],int blockNum,int process[],int processNum){
    int allocation[10];
    for(int i=0;i<processNum;i++){
        allocation[i]=-1;
    }

    //checking
    for(int i=0;i<processNum;i++){
        int worstFit=-1;
        for(int j=0;j<blockNum;j++){
            if(blocks[j]>=process[i]){
                if(worstFit==-1||blocks[j]>blocks[worstFit]){
                    worstFit=j;
                }
            }
        }
        if(worstFit!=-1){
            allocation[i]=worstFit;
            blocks[worstFit]=0;
        }
    }

    //results
    printf("Process No\tProcess Size\tBlock No.\n");
    for(int i=0;i<processNum;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]==-1){
            printf("Not Allocated\n");
        }
        else{
            printf("%d\n",allocation[i]+1);
        }
    }
}