// Write a program to copy its input to its output, replacing 
//Each string of one or more blanks by single blanks


#include <stdio.h>

int main() {
    int c;            // Declare variable to store input character
    int last_char = 0; // Flag to track the previous character (non-space initially)

    while ((c = getchar()) != EOF) {  // Read input until EOF
        if (c == ' ') {
            if (last_char != ' ') { // Print space only if the previous char wasn't a space
                putchar(c);
            }
        } else {
            putchar(c);  // Print non-space characters
        }
        last_char = c;  // Update the last character
    }

    return 0;
}
