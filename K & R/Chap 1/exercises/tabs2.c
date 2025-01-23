/* 
Write a program to copy its input to its output, replacing each tab
by \t. each backspaces by \\ .This makes tabs and backspaces visible in an 
unambiaguous way. 
*/

#include <stdio.h>

int main() {
    int c;
    while((c == getchar()) != EOF) {
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }else if (c == '\b'){
            putchar('\\');
            putchar('\\');
        }else{
            putchar(c);
        }
    }
    return 0;
}



