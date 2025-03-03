/* 
Write a program to remove trailing blanks and tabs from each line of input
and to delete entirely blank lines.
*/

#include <stdio.h>
#include <strings.h>

#define MAXLINE 1000

int main() {
    char line[MAXLINE];

    printf("Enter lines (Ctrl+D or Ctrl+Z to stop):\n");

    while (fgets(line, MAXLINE, stdin) != NULL) {
        // Get length and remove newline in one go
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        // Trim trailing blanks/tabs by moving backward
        while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t')) {
            line[--len] = '\0';
        }

        // Print only non-empty lines
        if (len > 0) {
            printf("%s\n", line);
        }
    }

    return 0;
}