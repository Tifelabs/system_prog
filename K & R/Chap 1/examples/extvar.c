#include <stdio.h>

#define MAXLINE 1000        // Maximum input line size

int max;                    // Maximum length seen so far
char line[MAXLINE];         // Current input line
char longest[MAXLINE];      // Longest line saved here

int get_line(void);         // Renamed to avoid conflict with stdio.h
void copy(void);

// Print the longest input line
int main() {
    int len;
    max = 0;

    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) {  // There was a non-empty line
        printf("Longest line (%d characters):\n%s", max, longest);
    } else {
        printf("No valid lines entered.\n");
    }
    return 0;
}

// get_line: Read a line into line[], return its length
int get_line(void) {
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    // Return 0 for empty lines (just newline)
    if (i == 1 && line[0] == '\n') {
        return 0;
    }
    return i;
}

// copy: Copy line[] to longest[]
void copy(void) {
    int i = 0;
    while ((longest[i] = line[i]) != '\0') {
        i++;
    }
}