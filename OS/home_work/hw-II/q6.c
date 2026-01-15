/* Write a slight modification of the previous program, this time using 
* waitpid() instead of wait(). When will waitpid() be useful?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int status;
    printf("Main Process (PID:%d)\n", (int) getpid());

    int rc = fork();
    
    if(rc < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }else if(rc == 0){
        printf("Child Process (PID:%d)\n",(int)getpid());
        sleep(2);
        printf("**** CHILD PROCESS FINISHED ****\n");
    } else{
        printf("Parent Process (PID:%d)\n", (int) getpid());
        printf("Parent process Calling waitpid()\n\n");
        int parent_waitpid = waitpid(-1, &status, WCONTINUED);
        printf("Parent proc after Waitpid() (PID:%d) returns [%d]\n",(int) getpid(), parent_waitpid);        
        sleep(3);
        printf("**** CHILD PROCESS FINISHED ****\n");
    }
       return 0;
}
