/* Now write a program that uses wait() to wait for the child process
* to finish in the parent, What does wait return? What happens if you use wait()
* in the child
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    printf("\nMain process (PID:%d)\n", (int) getpid());

    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork Failed");
        exit(1);
    } else if(rc == 0){
        /* New Child Process */
        printf("\nChild Process (PID:%d)\n", (int) getpid());
    } else{
        wait(NULL);
        /* Parent Process */
        printf("\nParent Process (PID:%d)\n", (int) getpid());
    }
}