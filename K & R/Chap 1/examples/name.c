//Line Counting
//Program that counts input lines
#include <stdio.h>

/* Count Lines in Input */

main (){

    int c, n1;
    
    n1 = 0;
    while ((c = getchar() != EOF)){
        if (c == '\n')
        {
            ++n1;
    
    printf("%d\n", n1);
        }
   
}