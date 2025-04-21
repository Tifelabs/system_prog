/* 
Write a program entabs that replace strings of blanks by the minimun number of tabs and blanks to achieve
the same spacing .Use the same tab stops as for detab. When either a tab or single blank would suffice to
reach a tab stop, which should be given preference
*/

#include <stdio.h>

#define TAB_STOP 10  // Tab stop interval (number of columns)

int main() {
    int c;           // Current character
    int pos = 0;     // Current column position
    int spaces = 0;  // Count of consecutive spaces

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spaces++;  // Count the space
            pos++;
            // If we can use a tab to reach the next tab stop
            if (pos % TAB_STOP == 0 && spaces >= 2) {
                putchar('\t');
                spaces = 0;  // Reset space count
            }
        } else {
            // Output any accumulated spaces as spaces
            while (spaces > 0) {
                putchar(' ');
                spaces--;
            }
            // Handle the current non-space character
            putchar(c);
            pos++;
            if (c == '\n') {
                pos = 0;  // Reset position on newline
            }
        }
    }
    // Output any remaining spaces
    while (spaces > 0) {
        putchar(' ');
        spaces--;
    }
    return 0;
}