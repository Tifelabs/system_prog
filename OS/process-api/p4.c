#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork failed"); /* Fork Failed */
        exit(0);
    } else if(rc == 0){
    /* Child: redirect standard output to a file */
    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT| O_WRONLY| O_TRUNC, S_IRWXU);
    /* Now exec "wc" */
    char *myargs[3];
    myargs[0] = strdup("wc");       /* Program : wc */
    myargs[1] = strdup("p4.c");     /* arg: file to count */
    myargs[2] = NULL;                /* Mark the end of the array */
    execvp(myargs[0], myargs);
    } else{
        /* Parent goes down this path (main) */
        int rc_wait = wait(NULL);
    }
    return 0;
}