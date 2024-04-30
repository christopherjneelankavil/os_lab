#include<stdio.h>

int main(){
    int totalProcesses;
    printf("Enter the no. of total processes: ");
    scanf("%d", &totalProcesses);

    int burstTime[totalProcesses], waitTime[totalProcesses], turnAroundTime[totalProcesses], remBurstTime[totalProcesses];
    float avgWait = 0, avgTurnAround = 0;
    int timeslice;

    printf("Enter the burst time for each process: \n");
    for(int i = 0; i < totalProcesses; i++){
        printf("P[%d]: ", i + 1);
        scanf("%d", &burstTime[i]);
        remBurstTime[i] = burstTime[i];
    }

    printf("Enter the time slice: ");
    scanf("%d", &timeslice);

    printf("Gantt Chart\n");
    int sq = 0;
    while(1){
        int done = 1;
        for(int i = 0; i < totalProcesses; i++){
            if(remBurstTime[i] > 0){
                done = 0;
                if(remBurstTime[i] > timeslice){
                    printf("P[%d](%d)-->", i + 1, sq); // Print process and current time
                    sq += timeslice;
                    remBurstTime[i] -= timeslice;
                }
                else{
                    printf("P[%d](%d)-->", i + 1, sq); // Print process and current time
                    sq += remBurstTime[i];
                    remBurstTime[i] = 0;
                    turnAroundTime[i] = sq; // Calculate turnaround time
                }
            }
        }
        if(done)
            break;
    }

    printf("\nProcess\t\tBurst Time\t\tWait time\t\tCompletion time\t\tTurnAround time\n");

    for(int i = 0; i < totalProcesses; i++){
        waitTime[i] = turnAroundTime[i] - burstTime[i];
        avgTurnAround += turnAroundTime[i];
        avgWait += waitTime[i];

        printf("P[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, burstTime[i], waitTime[i], turnAroundTime[i], turnAroundTime[i]);
    }
    avgTurnAround /= totalProcesses;
    avgWait /= totalProcesses;

    printf("\nAverage turn around time : %.2f", avgTurnAround);
    printf("\nAverage wait time : %.2f", avgWait);

    return 0;
}
