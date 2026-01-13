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
        printf("Child process calling wait()\n");
        int child_wait = wait(NULL);
        printf("\nChild Process After Wait() returns:[%d]\n", child_wait);
        sleep(2);
        printf("Child Process Finished\n\n");
    } else{
        /* Parent Process */
        printf("\nParent Process (PID:%d)\n", (int) getpid());
        printf("\nParent process calling wait\n");
        int parent_wait = wait(NULL);
        printf("Parent Process After wait() returns:[%d]\n", parent_wait);
        sleep(3);
        printf("Parent Process Finished\n");
    }
    return 0;
}