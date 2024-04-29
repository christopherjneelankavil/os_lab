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

    printf("Process\tBurst time\tCompile time\tWaiting time\tTurnAround Time\n");
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