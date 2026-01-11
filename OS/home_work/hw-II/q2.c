/* Write a program that opens a file (with the open() system call and then calls
* fork() to create a new process. Can both the child and parent access the file 
* descriptor returned by the open()? What happens when they are writing to the file
* concurrently, i.e at the same time
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){

    int fd;
    char buffer[BUFFER_SIZE];

    printf("(PID --> %d)\n\n", (int) getpid());

    fd = open("./agent.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    if(fd == -1){
        fprintf(stderr, "Error Opening File");
        exit(0);
    }
    int rc = fork(); /* Create new process */
    if(rc < 0){
        fprintf(stderr,"Fork Failed");
        exit(1);
    } else if(rc == 0){
        printf("(Child PID -->%d) writing to file\n\n", (int) getpid());
        char *child_msg = "Message from CHILD process\n";
        write(fd, child_msg, strlen(child_msg));
        printf("Finished Writing to Child\n");
    } else {
        wait(NULL);
        printf("(Parent PID --> %d)\n\n", (int) getpid());
        char *parent_msg = "Message from PARENT process\n";
        write(fd, parent_msg, strlen(parent_msg));
        printf("Finished writing to Parent\n");
    }
    return 0;
}