//Write a program to count blanks, tabs, and newlines

#include <stdio.h>


int main() {
    int c;

    int t = 0, b = 0, n = 0;

     while ((c = getchar() != EOF)){
        if(c == '\n'){
            n++;
        }
        else if (c == '\t'){
            t++;
        }
        else if(c == ' '){
            b++;
       }
     }

    printf("Tabs: %d, Blanks: %d, Newlines: %d\n", t, b, n);

    return 0;
 }


