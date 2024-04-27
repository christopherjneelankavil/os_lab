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

// Output

// Enter the no.of blocks: 5
// Enter the block size:
// 100 500 200 300 600
// Enter the no.of processes: 4
// Enter the process size:
// 212 417 112 426
// Process No      Process Size    Block No.
// 1               212             5
// 2               417             2
// 3               112             4
// 4               426             Not Allocated


//Algorithm

// Step 1: Start
// Step 2: Read the number of memory blocks (blockNum)
// Step 3: Read the size of each memory block into an array 'blocks'
// Step 4: Read the number of processes (processNum)
// Step 5: Read the size of each process into an array 'process'
// Step 6: Call the function worstFit(blocks, blockNum, process, processNum)
// Step 7: Exit

// Function worstFit(blocks[], blockNum, process[], processNum):
//     Step 1: Create an allocation array 'allocation' of size processNum and initialize all elements to -1
//     Step 2: For each process i from 0 to processNum - 1:
//         Step 2.1: Set worstFit to -1
//         Step 2.2: For each memory block j from 0 to blockNum - 1:
//             Step 2.2.1: If the size of block[j] is greater than or equal to the size of process[i]:
//                 Step 2.2.1.1: If worstFit is -1 or the size of block[j] is greater than the size of block[worstFit]:
//                     Step 2.2.1.1.1: Update worstFit to j
//         Step 2.3: If worstFit is not -1:
//             Step 2.3.1: Allocate process[i] to block worstFit
//             Step 2.3.2: Update allocation[i] to worstFit
//             Step 2.3.3: Set block[worstFit] to 0 to mark it as allocated
//     Step 3: Print the results:
//         Step 3.1: For each process i from 0 to processNum - 1:
//             Step 3.1.1: Print process number, size, and allocated block number if allocated, otherwise print "Not allocated"
//     Step 4: Exit
