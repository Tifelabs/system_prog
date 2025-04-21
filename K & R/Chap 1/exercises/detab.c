/* Write a program debtab that replaces tabs in the input with the proper
Number of tabs and blanks to space to the next tab stop.Assume a fix set of tab
stops, say every n columns. should be a varible or a symbolic parameter */

#include <stdio.h>

#define TAB_STOP 10  // Tab stop interval (number of columns)

int main() {
    int c;          // Current character
    int pos = 0;    // Current column position
    int spaces;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            // Calculate spaces needed to reach the next tab stop
            spaces = TAB_STOP - (pos % TAB_STOP);
            // Output the required number of spaces
            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                pos++;
            }
        } else if (c == '\n') {
            // Output newline and reset position
            putchar(c);
            pos = 0;
        } else {
            // Output other characters and increment position
            putchar(c);
            pos++;
        }
    }
    return 0;
}
