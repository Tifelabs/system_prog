/* Write a slight modification of the previous program, this time using 
* waitpid() instead of wait(). When will waitpid() be useful?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    printf("\t\t[ --> WAITPID() ADVANTAGES <-- ]\n\n");

    printf("PRO 1: Waiting for a specific child\n\n");
    int first_child = fork();
    int second_child;
    
    if(first_child == 0){
        printf("FIRST CHILD (PID:%d)\n",(int)getpid());
        sleep(3);
        printf("**** FIRST CHILD PROCESS FINISHED ****\n");
        exit(1);
    } 

    second_child = fork();
    if(second_child == 0){
        printf("SECOND CHILD (PID:%d)\n", (int) getpid());
        sleep(2);
        printf("**** SECOND CHILD PROCESS FINISHED ****\n");
        exit(2);
    }

    /* Parent waiting for second_child first despite first_child was created first */
    printf("PARENT :: WAITING FOR SECOND_CHILD (PID:%d)...\n", second_child);
    int status;
    waitpid(second_child, &status, 0);
    printf("PARENT --> Second Child Finished with status %d\n\n", WEXITSTATUS(status));
    
    /* Waiting for First Child */
    printf("PARENT :: WAITING FOR FIRST_CHILD (PID:%d)...\n", first_child);
    waitpid(first_child, &status, 0);
    printf("PARENT --> First Child Finished with status %d\n\n", WEXITSTATUS(status));

    return 0;
}
