#include <stdio.h>

int main(){
    int processNum,resourceNum;
    printf("Enter the no.of processes and resources: ");
    scanf("%d%d",&processNum,&resourceNum);

    int alloc[processNum][resourceNum],max[processNum][resourceNum],need[processNum][resourceNum];
    int available[resourceNum],work[resourceNum];
    int finish[processNum],safeseq[processNum];
    int index=0;

    printf("Enter the allocation matrix: \n");
    for(int i=0;i<processNum;i++){
        for(int j=0;j<resourceNum;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the max matrix: \n");
    for(int i=0;i<processNum;i++){
        for(int j=0;j<resourceNum;j++){
            scanf("%d",&max[i][j]);
        }
    }

    for(int i=0;i<processNum;i++){
        for(int j=0;j<resourceNum;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nThe need matrix is : \n");
    for(int i=0;i<processNum;i++){
        for(int j=0;j<resourceNum;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    printf("Enter the available matrix: ");
    for(int i=0;i<resourceNum;i++){
        scanf("%d",&available[i]);
        work[i]=available[i];
    }

    for(int i=0;i<processNum;i++){
        finish[i]=0;
    }

    for(int k=0;k<processNum;k++){
        for(int i=0;i<processNum;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<resourceNum;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safeseq[index++]=i;
                    finish[i]=1;
                    for(int y=0;y<resourceNum;y++){
                        work[y]+=alloc[i][y];
                    }
                }
            }
        }
    }
    printf("Safety Sequence: : ");
    for(int i=0;i<processNum;i++){
        printf("P[%d]-->",safeseq[i]);
    }
}

// Output

// Enter the no.of processes and resources: 5 4
// Enter the allocation matrix:
// 0 0 1 2
// 1 0 0 0
// 1 3 5 4
// 0 6 3 2
// 0 0 1 4
// Enter the max matrix:
// 0 0 1 2 
// 1 7 5 0
// 2 3 5 6
// 0 6 5 2
// 0 6 5 6

// The need matrix is :
// 0 0 0 0
// 0 7 5 0
// 1 0 0 2
// 0 0 2 0
// 0 6 4 2
// Enter the available matrix: 1 5 2 0
// Safety Sequence: : P[0]-->P[2]-->P[3]-->P[4]-->P[1]-->


// Algorithm

// Step 1: Start
// Step 2: Declare variables processNum, resourceNum, index
// Step 3: Read the number of processes (processNum) and resources (resourceNum)
// Step 4: Declare arrays alloc[processNum][resourceNum], max[processNum][resourceNum], need[processNum][resourceNum], available[resourceNum], work[resourceNum], finish[processNum], safeseq[processNum]
// Step 5: Read the allocation matrix into the array alloc[][]
// Step 6: Read the max matrix into the array max[][]
// Step 7: Calculate the need matrix:
//     Step 7.1: For each process i from 0 to processNum - 1:
//         Step 7.1.1: For each resource j from 0 to resourceNum - 1:
//             Step 7.1.1.1: Calculate need[i][j] = max[i][j] - alloc[i][j]
// Step 8: Print the need matrix
// Step 9: Read the available matrix into the array available[]
// Step 10: Copy available[] to work[]
// Step 11: Initialize finish[] to all 0
// Step 12: Loop through each process to find a safe sequence:
//     Step 12.1: For each process i from 0 to processNum - 1:
//         Step 12.1.1: If finish[i] is 0:
//             Step 12.1.1.1: Set flag to 0
//             Step 12.1.1.2: For each resource j from 0 to resourceNum - 1:
//                 Step 12.1.1.2.1: If need[i][j] > work[j]:
//                     Step 12.1.1.2.1.1: Set flag to 1 and break the loop
//             Step 12.1.1.3: If flag is still 0:
//                 Step 12.1.1.3.1: Add process i to the safe sequence safeseq[]
//                 Step 12.1.1.3.2: Mark process i as finished
//                 Step 12.1.1.3.3: Update work[] by adding alloc[i][] to it
// Step 13: Print the safe sequence
// Step 14: End
