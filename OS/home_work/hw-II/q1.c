/* Write a program that calls fork(). Before calling fork(), have the
* main process access a variable (e.g x) and set its value to something
* (e.g 100).What value is the variable in the child process?
* What happens to the variable when both the child and parent change the value of x.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int x = 100;
    printf("Before fork x:%d (PID: %d)\n\n", x,(int) getpid());

    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork failed");
        exit(1);
    } else if(rc == 0){
        /* Child new process */
        printf("Initial x:%d Child (PID:%d)\n\n",x,(int) getpid());
        x = 400;
        printf("New x:%d Child (PID:%d)\n\n",x,(int) getpid());
    } else{
        wait(NULL);
        printf("Initial x:%d Parent (PID:%d)\n\n",x,(int) getpid());
        x = 300;
        printf("New x:%d Parent (PID:%d)\n\n",x,(int) getpid());
    }
    return 0;
}