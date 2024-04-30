#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

sem_t empty,full;
pthread_mutex_t mutex;
int buffer[5];
int count=0;

void* producer(void* args){
    long int num=(long int)args;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count]=rand()%10;
    printf("Producer [%ld] produced: %d\n",num+1,buffer[count]);
    count++;
    pthread_mutex_unlock(&mutex);
    sleep(1);
    sem_post(&full);
    pthread_exit(NULL);
}
void* consumer (void* args){
    long int num=(long int)args;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    count--;
    printf("Consumer [%ld] consumed: %d\n",num+1,buffer[count]);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    pthread_exit(NULL);
}
int main(){
    int pNum,cNum;
    printf("Enter the no.of processes and consumers : ");
    scanf("%d %d",&pNum,&cNum);
    pthread_t p[pNum],c[cNum];
    sem_init(&empty,0,5);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);
    unsigned long int i;
    for(i=0;i<pNum;i++){
        pthread_create(&p[i],NULL,producer,(void*)i);
    }
    for(i=0;i<cNum;i++){
        pthread_create(&c[i],NULL,consumer,(void*)i);
    }
    for(i=0;i<pNum;i++){
        pthread_join(p[i],NULL);
    }
    for(i=0;i<cNum;i++){
        pthread_join(c[i],NULL);
    }
    return 0;
}

// Output

// Enter the no.of processes and consumers : 5 4
// Producer [1] produced: 3
// Producer [2] produced: 6
// Producer [4] produced: 7
// Producer [3] produced: 5
// Producer [5] produced: 3
// Consumer [1] consumed: 3
// Consumer [2] consumed: 5
// Consumer [4] consumed: 7
// Consumer [3] consumed: 6

// Algorithm

// Step 1: Start
// Step 2: Declare variables empty, full, mutex, buffer[5], count
// Step 3: Initialize semaphores empty and full to 5 and 0 respectively
// Step 4: Initialize mutex
// Step 5: Define producer function:
//     Step 5.1: Receive the thread number as an argument
//     Step 5.2: Wait on empty semaphore
//     Step 5.3: Lock mutex
//     Step 5.4: Generate a random number and add it to the buffer
//     Step 5.5: Print the produced item
//     Step 5.6: Increment count
//     Step 5.7: Unlock mutex
//     Step 5.8: Sleep for 1 second
//     Step 5.9: Post to full semaphore
//     Step 5.10: Exit the thread
// Step 6: Define consumer function:
//     Step 6.1: Receive the thread number as an argument
//     Step 6.2: Wait on full semaphore
//     Step 6.3: Lock mutex
//     Step 6.4: Decrement count
//     Step 6.5: Print the consumed item
//     Step 6.6: Unlock mutex
//     Step 6.7: Sleep for 1 second
//     Step 6.8: Post to empty semaphore
//     Step 6.9: Exit the thread
// Step 7: Define main function:
//     Step 7.1: Read the number of producers (pNum) and consumers (cNum)
//     Step 7.2: Declare arrays of pthreads for producers and consumers
//     Step 7.3: Initialize semaphores and mutex
//     Step 7.4: Create producer threads:
//         Step 7.4.1: Loop over the number of producer threads
//         Step 7.4.2: Create producer thread and pass the thread number as argument
//     Step 7.5: Create consumer threads:
//         Step 7.5.1: Loop over the number of consumer threads
//         Step 7.5.2: Create consumer thread and pass the thread number as argument
//     Step 7.6: Join producer threads
//     Step 7.7: Join consumer threads
//     Step 7.8: End
