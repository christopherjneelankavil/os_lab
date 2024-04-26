#include <stdio.h>

void bestFit(int blocks[],int blockNum,int process[],int processNum);

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

    //passing values to bestFit
    bestFit(blocks,blockNum,process,processNum);
    return 0;
}

void bestFit(int blocks[],int blockNum,int process[],int processNum){

    int allocation[10];
    for(int i=0;i<processNum;i++){
        allocation[i]=-1;
    }

    //checking
    for(int i=0;i<processNum;i++){
        int bestFit=-1;
        for(int j=0;j<blockNum;j++){
            if(blocks[j]>=process[i]){
                if(bestFit==-1||blocks[j]<blocks[bestFit]){
                    bestFit=j;
                }
            }
        }
        if(bestFit!=-1){
           allocation[i]=bestFit;
           blocks[bestFit]-= process[i];
        }
    }  

    //results
    printf("Process No.\tProcess Size\tBlock No.\n");
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


//Output

// Enter the no.of blocks: 5
// Enter the size of each blocks :
// 100 500 200 300 600 

// Enter the no.of processes : 4
// Enter the size of each process:
// 212 417 112 426
// Process No.     Process Size    Block No.
// 1               212             4
// 2               417             2
// 3               112             3
// 4               426             5


//Algorithm

// Step 1: Start
// Step 2: Read the number of memory blocks (blockNum)
// Step 3: Read the size of each memory block into an array 'blocks'
// Step 4: Read the number of processes (processNum)
// Step 5: Read the size of each process into an array 'process'
// Step 6: Call the function bestFit(blocks, blockNum, process, processNum)
// Step 7: Exit

// Function bestFit(blocks[], blockNum, process[], processNum):
//     Step 1: Create an allocation array 'allocation' of size processNum and initialize all elements to -1
//     Step 2: For each process i from 0 to processNum - 1:
//         Step 2.1: Set bestFit to -1
//         Step 2.2: For each memory block j from 0 to blockNum - 1:
//             Step 2.2.1: If the size of block[j] is greater than or equal to the size of process[i]:
//                 Step 2.2.1.1: If bestFit is -1 or the size of block[j] is less than the size of block[bestFit]:
//                     Step 2.2.1.1.1: Update bestFit to j
//         Step 2.3: If bestFit is not -1:
//             Step 2.3.1: Allocate process[i] to block bestFit
//             Step 2.3.2: Update allocation[i] to bestFit
//             Step 2.3.3: Decrease the size of block bestFit by the size of process[i]
//     Step 3: Print the results:
//         Step 3.1: For each process i from 0 to processNum - 1:
//             Step 3.1.1: Print process number, size, and allocated block number if allocated, otherwise print "Not allocated"
//     Step 4: Exit
