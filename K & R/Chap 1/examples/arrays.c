//ARRAYS.

#include <stdio.h>

/*Count Digits, Whitespace and Others  */

int main() {
   int c;          // Stores each character we read
   int i;          // Loop counter
   int nwhite;     // Counts whitespace
   int nother;     // Counts other characters
   int ndigits[10]; // Array to count each digit (0-9)

    nwhite = nother = 0;        //Start both counters at zero
    for (i = 0; i < 10; i++)    //Initialize all digits count to zero(0)
        ndigits[i] = 0;

    while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')       // Is it a digit?
        ++ndigits[c-'0'];           
    else if (c == ' ' || c == '\n' || c == '\t')  // Is it whitespace?
        ++nwhite;
    else                            // Everything else
        ++nother;
}
    
    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigits[i]);
    printf(", white space = %d, other = %d\n",nwhite,nother);
    
}