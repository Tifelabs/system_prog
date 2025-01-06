// Verify that the expression getchar() != EOF is 0 or 1

#include <stdio.h>

int main (void){

    int c;

    //Read the first line of the character
    c = getchar();

    // Loop until EOF is met
    while(c != EOF){
    //Print  the character
        putchar(c);

    //Read the next character
    c = getchar();
    }

    return 0;

}

// EOF mean => Ctrl + D on Unix