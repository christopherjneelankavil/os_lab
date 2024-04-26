#include<stdio.h>
void firstFit(int blocks[],int memBlocks,int process[],int processNum);
int main(){
    int blocks[10],process[10];
    
    //read no.of blocks
    printf("Enter the no.of blocks: ");
    int memBlocks;
    scanf("%d",&memBlocks);

    //reading the size of each block
    printf("\nEnter the size of each block:\n");
    for(int i=0;i<memBlocks;i++){
        scanf("%d",&blocks[i]);
    }

    //reading no.of processes
    printf("Enter the no.of processes: ");
    int processNum;
    scanf("%d",&processNum);

    //reading size of each processes
    printf("\nEnter the size of each processes: \n");
    for(int i=0;i<processNum;i++){
        scanf("%d",&process[i]);
    }

    //passing values to first fit function
    firstFit(blocks,memBlocks,process,processNum);

    return 0;
}

//first fit function

void firstFit(int blocks[],int memBlocks,int process[],int processNum){

    //create allocation matrix and assign all values to -1
    int allocation[10];
    for(int i=0;i<processNum;i++){
        allocation[i]=-1;
    }

    //checking
    for(int i=0;i<processNum;i++){
        for(int j=0;j<memBlocks;j++){
            if(blocks[j]>=process[i]){
                allocation[i]=j;
                blocks[j]=0;
                break;
            }
        }
    }

    //results
    printf("Process No. \tProcess Size \tBlock No.\n");
    for(int i=0;i<processNum;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]==-1){
            printf("Not allocated\n");
        }
        else{
            printf("%d\n",allocation[i]+1);
        }
    }
}

//Output

// Enter the no.of blocks: 5

// Enter the size of each block:
// 100 500 200 300 600
// Enter the no.of processes: 4

// Enter the size of each processes:
// 212 417 112 426
// Process No.     Process Size    Block No.
// 1               212             2
// 2               417             5
// 3               112             3
// 4               426             Not allocated

//Algorithm

// Step 1: Start
// Step 2: Read the number of memory blocks (memBlocks)
// Step 3: Read the size of each memory block into an array 'blocks'
// Step 4: Read the number of processes (processNum)
// Step 5: Read the size of each process into an array 'process'
// Step 6: Call the function firstFit(blocks, memBlocks, process, processNum)
// Step 7: Exit

// Function firstFit(blocks[], memBlocks, process[], processNum):
//     Step 1: Create an allocation array 'allocation' of size processNum and initialize all elements to -1
//     Step 2: For each process i from 0 to processNum - 1:
//         Step 2.1: For each memory block j from 0 to memBlocks - 1:
//             Step 2.1.1: If the size of block[j] is greater than or equal to the size of process[i]:
//                 Step 2.1.1.1: Allocate process[i] to block j
//                 Step 2.1.1.2: Update allocation[i] to j
//                 Step 2.1.1.3: Set block[j] to 0 to mark it as allocated
//                 Step 2.1.1.4: Break the loop
//     Step 3: Print the results:
//         Step 3.1: For each process i from 0 to processNum - 1:
//             Step 3.1.1: Print process number, size, and allocated block number if allocated, otherwise print "Not allocated"
//     Step 4: Exit

