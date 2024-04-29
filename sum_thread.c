// Write a program to create a thread T1. The main process passes two numbers to T1. T1 calculates the 
// sum of these numbers and returns the sum to the parent process for printing.

#include<stdio.h>
#include<pthread.h>

void *calculate(void *args);
int main(){
    printf("Enter the first number: ");
    int n1;
    scanf("%d",&n1);
    printf("Enter the second number: ");
    int n2;
    scanf("%d",&n2);
    int args[2]={n1,n2};
    void* sum;
    pthread_t t1;
    pthread_create(&t1,NULL,calculate,(void*) args);
    pthread_join(t1,&sum);

    printf("The sum of %d and %d is : %d",n1,n2,(int)sum);
    return 0;
}

void *calculate(void *args){
    int num1=((int*)args)[0];
    int num2=((int*)args)[1];
    int sum = num1+num2;
    pthread_exit((void *)sum); 
}