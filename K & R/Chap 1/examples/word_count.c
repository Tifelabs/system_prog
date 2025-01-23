// WORD COUNTING

#include <stdio.h>

#define IN 1     //inside a word
#define OUT 0    //Outside a word

/* Count words, lines and characters in input */
int main() {
    int c;
    int n1;
    int nw;
    int nc;
    int state;

    //Note this can also be written as int c,n1,nw,nc,state;

    state = OUT;
    n1 = nw = nc = 0;
    while((c == getchar() != EOF)) {
        nc++;
        if(c == '\n')
            n1++; 
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        } 
        else if (state == OUT) {
            state = IN;
            nw++;
        }
        
    }
    printf("%d %d %d\n",n1,nw,nc);
}