/* Write a program that creates two children, and connects the 
standard output of one to the standard input of the other, using 
pipe() system call 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[]){
    int fd[2];
    char *first_msg = "Message from FIRST CHILD\n";
    char *second_msg = "Message from SECOND CHILD\n";
    char buffer[BUFFER_SIZE];

    printf("\t\tPARENT --> MAIN PROCESS (PID:%d)\n", (int) getpid());
    /* Creating Pipe */
    if(pipe(fd) == -1){
        fprintf(stderr, "Pipe Failed\n");
        exit(1);
    }
    /* Creating First Child proc  */
    int first_child = fork();
    if(first_child < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }else if(first_child == 0){
    printf("FIRST CHILD CREATED! - WRITING TO PIPE...(PID:%d)\n", (int) getpid());
    close(fd[0]);
            /* Redirecting STDOUT to pipe */
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
            /* Writing to First pipe */
    printf("%s",first_msg);
    exit(0);
   } 
        /* Creating Second Child Proc */
    int second_child = fork();
    if(second_child < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if(second_child == 0){
    printf("SECOND CHILD CREATED! -READING FROM PIPE...(PID:%d)\n", (int) getpid());
    close(fd[1]);
        /* Redirecting STDIN to pipe */
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
        /* Reading from pipe */
    while(fgets(buffer, sizeof(buffer), stdin) != NULL){
        printf("SECOND CHILD received: %s", buffer);
    }
    exit(0);
}
    close(fd[0]);
    close(fd[1]);
        /* Wait for both children */
    wait(NULL);
    wait(NULL);
    printf("PARENT--> Both Children PROC FINISHED\n");
    return 0;
}