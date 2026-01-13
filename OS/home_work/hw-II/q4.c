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
        char *prog_path[] = {"/bin/ls", NULL};

        switch (variant){
        case 1:
            printf("USING execl()\n");
            execl("/bin/ls", "ls", "-l", NULL);
            break;
        
        case 2:
            printf("USING evecvp()");
            char *myargs_vp[] = {"ls", "-l", NULL};
            execvp(myargs_vp[0], myargs_vp);
            break;
        
        case 3:
            printf("USING execle()\n");
            execle("/bin/ls", "ls", "-l", NULL, prog_path);
            break;
        
        case 4:
            printf("USING execlp()\n");
            execlp("ls", "ls", "-l", NULL);
            break;

        case 5:
            printf("USING execv()\n");
            char *myargs_cv[] = {"ls", "-l", NULL};
            execv("/bin/ls", myargs_cv);
            break;

        default:
            fprintf(stderr, "INVALID VARIANT, Use 1-5\n");
            exit(1);
        }
    }
        else{
        /* PARENT process */
        wait(NULL);
        printf("\nParent (PID:%d) - Child completed\n", (int) getpid());
        }
        return 0;
    }