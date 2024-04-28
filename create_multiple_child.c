#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

//main function

int main(){
    pid_t pid1,pid2;
    pid1=fork();
    if(pid1==0){
        printf("Child1 process id: %d\n",getpid());
        printf("Parent process id of child1: %d\n",getppid());
    }
    else{
        pid2=fork();
        if(pid2==0){
            printf("Child2 process id : %d\n",getpid());
            printf("Parent process id of child2: %d\n",getppid());
        }
        else{
            printf("Parent id: %d\n",getpid());
        }
    }
}

// Output

// Child1 process id: 24552
// Parent process id of child1: 24551
// Parent id: 24551
// Child2 process id : 24553
// Parent process id of child2: 1


// The parent process ID of Child2 is 1 (since it is an orphan process).
// An orphan process is a child process that continues to run after its parent process has terminated or completed its execution.
// To get correct result
// #include<stdio.h>
// #include<unistd.h>
// #include<sys/wait.h>

// //main function

// int main(){
//     pid_t pid1,pid2;
//     pid1=fork();
//     if(pid1==0){
//         printf("Child1 process id: %d\n",getpid());
//         printf("Parent process id of child1: %d\n",getppid());
//     }
//     else{
//         wait(NULL);
//         pid2=fork();
//         if(pid2==0){
//             printf("Child2 process id : %d\n",getpid());
//             printf("Parent process id of child2: %d\n",getppid());
//         }
//         else{
//             wait(NULL);
//             printf("Parent id: %d\n",getpid());
//         }
//     }
// }


// Algorithm

// Step 1: Start
// Step 2: Create variables 'pid1' and 'pid2' of type pid_t
// Step 3: Fork the process and store the return value in 'pid1'
// Step 4: If pid1 is 0 (child process 1):
//     Step 4.1: Print "Child1 process id: <pid1>"
//     Step 4.2: Print "Parent process id of child1: <parent_pid>"
// Step 5: If pid1 is not 0 (parent process):
//     Step 5.1: Wait for child process 1 to finish
//     Step 5.2: Fork the process again and store the return value in 'pid2'
//     Step 5.3: If pid2 is 0 (child process 2):
//         Step 5.3.1: Print "Child2 process id: <pid2>"
//         Step 5.3.2: Print "Parent process id of child2: <parent_pid>"
//     Step 5.4: If pid2 is not 0 (parent process):
//         Step 5.4.1: Wait for child process 2 to finish
//         Step 5.4.2: Print "Parent id: <parent_pid>"
// Step 6: End


