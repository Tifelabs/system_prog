/* 
Write a program that prints its input one word per line
 */
#include <stdio.h>

int main() {
    int c, in_word = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (in_word) putchar('\n');
            in_word = 0;  // Mark that we're outside a word
        } else {
            putchar(c);
            in_word = 1;  // Mark that we're inside a word
        }
    }
    if (in_word) putchar('\n');  // Final newline if needed
    return 0;
}               