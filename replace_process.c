//Using C, create a new process and replace the child process with the "ps" process. (use execl() system call).

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

//main function 
int main(){
    pid_t pid;
    pid=fork();
    if(pid==0){
        execl("/bin/ps","ps",NULL);
        printf("Child id: %d\n",getpid());
    }
    else{
        wait(NULL);
        printf("Parent id: %d\n",getpid());
    }
}

// Output 

//     PID TTY          TIME CMD
//    4373 pts/2    00:00:00 bash
//   15543 pts/2    00:00:00 replace_process
//   15544 pts/2    00:00:00 ps
// Parent id: 15543

// Algorithm

// Step 1: Start
// Step 2: Create a variable 'pid' of type pid_t
// Step 3: Fork the process and store the return value in 'pid'
// Step 4: If pid is 0 (child process):
//     Step 4.1: Replace the child process with the 'ps' command using execl
//     Step 4.2: If execl fails, print an error message
// Step 5: If pid is not 0 (parent process):
//     Step 5.1: Wait for the child process to finish
//     Step 5.2: Print "Parent id: <parent_pid>"
// Step 6: End
