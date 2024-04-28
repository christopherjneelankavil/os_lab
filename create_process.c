#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        printf("Child id: %d\n",getpid());
        printf("Parent id : %d\n",getppid());
    }
    else{
        wait(NULL);
        printf("Child id: %d\n",pid);
        printf("Parent id: %d\n",getpid());
    }
}

// Output

// Child id: 7854
// Parent id : 7853
// Child id: 7854
// Parent id: 7853

// Algorithm

// Step 1: Start
// Step 2: Create a variable 'pid' of type pid_t
// Step 3: Fork the process and store the return value in 'pid'
// Step 4: If pid is 0 (child process):
//     Step 4.1: Print "Child id: <child_pid>"
//     Step 4.2: Print "Parent id: <parent_pid>"
// Step 5: If pid is not 0 (parent process):
//     Step 5.1: Wait for the child process to finish
//     Step 5.2: Print "Child id: <child_pid>"
//     Step 5.3: Print "Parent id: <parent_pid>"
// Step 6: End

