/* 
* Write another progra, using fork(). Th child process should print "hello";
* the parent process should print "goodbye". You should try to ensure that the child process
* always prints first; can you do this method without using wait() in the parent
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc , char *argv[]){
    
    int pipe_fd[2];
    char buffer[4];

    if(pipe(pipe_fd) == -1){
        fprintf(stderr, "Pipe Failed\n");
        exit(1);
    }

    printf("(PID: %d)\n", (int) getpid());
    int rc = fork(); /* Create new process */
    if(rc < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc == 0){
        close(pipe_fd[0]);
        printf("Hello (from child). (PID:%d)\n",(int) getpid());
        write(pipe_fd[1], "Hey", 3);
        close(pipe_fd[1]);
    } else{
        close(pipe_fd[1]);
        read(pipe_fd[0], buffer, 3);
        close(pipe_fd[0]);
        printf("Goodbye (from parent). (PID:%d)\n", (int) getpid());
    }
    return 0;
}