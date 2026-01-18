/* Write a program that creates a child process, and then in the child
closes the standard output (STDOUT_FILENO). What happens if the child calls 
printf() to print some output afer close the file descriptor
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
    printf("\t\t ---> MAIN PROCESS (PID:%d)\n\n", (int) getpid());

    /* Creating the child process */
    int child = fork();
    
    if(child < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (child == 0){
        printf("CHILD PROCESS BEFORE CLOSING STDOUT (PID%d)\n",(int) getpid());

        /* Closing STDOUT */
        close(STDOUT_FILENO);
        printf("CHILD PROCESS AFTER CLOSING STDOUT (PID:%d)\n", (int) getpid());
        fflush(stdout);

        /* Testing with the write() syscall to check running state */
        char *msg = "CHILD-->>>>> Child process still running\n";
        write(STDERR_FILENO, msg, strlen(msg));
        exit(0);
    } else{
       /* Parent Process */
       wait(NULL);
       printf("PARENT: Child Finished\n");
    }
    return 0;
}