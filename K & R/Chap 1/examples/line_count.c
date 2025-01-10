#include <stdio.h>

int main(){

    char result[10];
    char name;

    name = getchar();

    printf("What is your name? ");

    while (getchar() != EOF){
        result[10] = putchar(name);

        printf("My name is result %s", result);
    }
    

    return 0;
    
}