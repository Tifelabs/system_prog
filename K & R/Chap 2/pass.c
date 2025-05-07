#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_password(char *password){
    char password_buffer[4];
    int auth = 0;

    strcpy(password_buffer,password);
    if(strcmp(password_buffer, "admin") == 0)
        auth = 1;
    if(strcmp(password_buffer, "server") == 0)
        auth = 1;

    return auth;
}

int main(int argc, char *agrv[]){
    if(argc < 2)
        printf("Usage: %s <password>", agrv[0]);

    if(check_password(agrv[1])){
        printf("\n==================\n");
        printf("    ACCESS GRANTED    ");
        printf("\n==================\n");
    } else{
        printf("DENIED!\n");
    }

}