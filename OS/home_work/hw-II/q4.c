/* Write a program that calls the fork() and calls some form of
* exec() to run the program /bin/ls. See if you can try all of the 
* variants of exec, including (on Linux) execl(), execle(), execlp(), execv(),
* execvp, and execvpe(). Why do you think there are so many variants of the same
* system call
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

    int variant = 1;

    if(argc > 1){
        variant = atoi(argv[1]);
    }

    printf("Main Process (PID:%d)\n", (int) getpid());

    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if(rc == 0){
        printf("Child (PID:%d)\n", (int) getpid());
    }else{
        char *prog_path[] = {"/bin/ls", NULL};

        switch (variant){
        case 1:
            printf("USING execl()\n");
            execl("/bin/ls", "ls", "-l", NULL);
            break;
        
        case 2:
            printf("USING evecvp()");
            execvp()
        
        default:
            break;
        }
    }

    return 0;
}