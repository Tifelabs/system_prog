/* 
Write a program to copy its input to its output, replacing each tab
by \t. each backspaces by \\ .This makes tabs and backspaces visible in an 
unambiaguous way. 
*/

#include <stdio.h>

int main() {

    int c;
    int output;

    c = getchar();          //To get user-input
    output = putchar;      //User Output

    while(c != EOF){
        c == output;

        if(c == '\t'){
            puts('\t');
        }

        else if (c == '\\')
        {
            puts('\\');
        }
        
    }
    return 0;
}