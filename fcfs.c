#include<stdio.h>

int main(){
    int totalProcess;
    printf("Enter the total no.of processes: ");
    scanf("%d",&totalProcess);
    int burstTime[totalProcess],waitTime[totalProcess],turnAroundTime[totalProcess];
    float avgWait=0,avgTurnAround=0;

    printf("Enter the burst time of each processes: \n");
    for(int i=0;i<totalProcess;i++){
        printf("P[%d]: ",i+1);
        scanf("%d", &burstTime[i]);
    }
    waitTime[0]=0;
    for(int i=1;i<totalProcess;i++){
        waitTime[i]=0;
        for(int j=0;j<i;j++){
            waitTime[i]+=burstTime[j];
        }
    }
    printf("Gantt Chart\n");
    for(int i=1;i<=totalProcess;i++){
        printf("P[%d]-->",i);
    }
    printf("\n");

    printf("Process\tBurst time\tCompletion time\tWaiting time\tTurnAround Time\n");
    for(int i=0;i<totalProcess;i++){
        turnAroundTime[i]=waitTime[i]+burstTime[i];
        avgWait+=waitTime[i];
        avgTurnAround+=turnAroundTime[i];
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1,burstTime[i],turnAroundTime[i],waitTime[i],turnAroundTime[i]);
    }

    avgWait/=totalProcess;
    avgTurnAround/=totalProcess;

    printf("\nAverage wait time: %f\n",avgWait);
    printf("Average turn around time: %f\n",avgTurnAround);

    return 0;
}

// Output

// Enter the total no.of processes: 4
// Enter the burst time of each processes:
// P[1]: 3
// P[2]: 4
// P[3]: 2
// P[4]: 1
// Gantt Chart
// P[1]-->P[2]-->P[3]-->P[4]-->
// Process Burst time      Completion time    Waiting time    TurnAround Time

// P[1]                    3                       3                       0                       3
// P[2]                    4                       7                       3                       7
// P[3]                    2                       9                       7                       9
// P[4]                    1                       10                      9                       10
// Average wait time: 4.750000
// Average turn around time: 7.250000

// Algorithm

// Step 1: Start
// Step 2: Declare variables totalProcess, burstTime[], waitTime[], turnAroundTime[]
// Step 3: Read the total number of processes (totalProcess)
// Step 4: Read the burst time of each process into the array burstTime[]
// Step 5: Initialize waitTime[0] to 0
// Step 6: For each process i from 1 to totalProcess - 1:
//     Step 6.1: Initialize waitTime[i] to 0
//     Step 6.2: For each process j from 0 to i - 1:
//         Step 6.2.1: Add burstTime[j] to waitTime[i]
// Step 7: Print "Gantt Chart"
// Step 8: For each process i from 0 to totalProcess - 1:
//     Step 8.1: Calculate turnAroundTime[i] as waitTime[i] + burstTime[i]
//     Step 8.2: Add waitTime[i] to avgWait
//     Step 8.3: Add turnAroundTime[i] to avgTurnAround
//     Step 8.4: Print process details: Process number, burst time, compile time, waiting time, and turn around time
// Step 9: Calculate average waiting time (avgWait) by dividing total wait time by totalProcess
// Step 10: Calculate average turn around time (avgTurnAround) by dividing total turn around time by totalProcess
// Step 11: Print average wait time and average turn around time
// Step 12: End

