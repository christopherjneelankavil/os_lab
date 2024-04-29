#include<stdio.h>

int main(){

    int totalProcess;
    printf("Enter the total no.of processes: ");
    scanf("%d",&totalProcess);

    int burstTime[totalProcess],waitTime[totalProcess],turnAroundTime[totalProcess],process[totalProcess];
    float avgWait=0,avgTurnAround=0;

    printf("Enter the burst time of each processes: \n");
    for(int i=0;i<totalProcess;i++){
        printf("P[%d]: ",i+1);
        scanf("%d",&burstTime[i]);
        process[i]=i+1;
    }

    for(int i=0;i<totalProcess;i++){
        int pos=i;
        for(int j=i+1;j<totalProcess;j++){
            if(burstTime[j]<burstTime[pos]){
                pos=j;
            }
        }
        int temp=burstTime[i];
        burstTime[i]=burstTime[pos];
        burstTime[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }

    waitTime[0]=0;
    for(int i=1;i<totalProcess;i++){
        waitTime[i]=0;
        for(int j=0;j<i;j++){
            waitTime[i]+=burstTime[j];
        }
    }

    printf("Gantt Chart:\n");
    for(int i=0;i<totalProcess;i++){
        printf("P[%d]-->",process[i]);
        turnAroundTime[i]=waitTime[i]+burstTime[i];
        avgWait=avgWait+waitTime[i];
        avgTurnAround=avgTurnAround+turnAroundTime[i];
    }
    printf("\n");

    printf("\nProcess\t\tBurst Time\t\tCompletion Time\t\tWaiting time\t\tTurnAroundTime\n");
    for(int i=0;i<totalProcess;i++){
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",process[i],burstTime[i],turnAroundTime[i],waitTime[i],turnAroundTime[i]);
    }

    avgTurnAround /= (float)(totalProcess);
    avgWait /= (float)(totalProcess);


    printf("\nAverage wait time: %f",avgWait);
    printf("\nAverage turn around time: %f",avgTurnAround);

    return 0;
}


// Output

// Enter the total no.of processes: 4
// Enter the burst time of each processes:
// P[1]: 1
// P[2]: 9
// P[3]: 4
// P[4]: 6
// Gantt Chart:
// P[1]-->P[3]-->P[4]-->P[2]-->

// Process         Burst Time              Completion Time         Waiting time            TurnAroundTime

// P[1]                    1                       1                       0                       1
// P[3]                    4                       5                       1                       5
// P[4]                    6                       11                      5                       11
// P[2]                    9                       20                      11                      20
// Average wait time: 4.250000
// Average turn around time: 9.250000

// Algorithm

// Step 1: Start
// Step 2: Declare variables totalProcess, burstTime[], waitTime[], turnAroundTime[], process[], avgWait, avgTurnAround
// Step 3: Read the total number of processes (totalProcess)
// Step 4: Read the burst time of each process into the array burstTime[] and initialize process[] with process numbers
// Step 5: Sort burstTime[] and process[] in ascending order using selection sort
// Step 6: Calculate waitTime[] for each process:
//     Step 6.1: Initialize waitTime[0] to 0
//     Step 6.2: For each process i from 1 to totalProcess - 1:
//         Step 6.2.1: Initialize waitTime[i] to 0
//         Step 6.2.2: For each process j from 0 to i - 1:
//             Step 6.2.2.1: Add burstTime[j] to waitTime[i]
// Step 7: Print "Gantt Chart"
// Step 8: Calculate turnAroundTime[] and accumulate total wait and turn around times:
//     Step 8.1: For each process i from 0 to totalProcess - 1:
//         Step 8.1.1: Calculate turnAroundTime[i] as waitTime[i] + burstTime[i]
//         Step 8.1.2: Add waitTime[i] to avgWait
//         Step 8.1.3: Add turnAroundTime[i] to avgTurnAround
// Step 9: Print process details:
//     Step 9.1: Print process number, burst time, completion time, waiting time, and turn around time for each process
// Step 10: Calculate average waiting time (avgWait) by dividing total wait time by totalProcess
// Step 11: Calculate average turn around time (avgTurnAround) by dividing total turn around time by totalProcess
// Step 12: Print average wait time and average turn around time
// Step 13: End
