//Write a program to  print all input lines  that are longer than 80
//characters

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 // Bigger buffer to catch lines > 80 chars
#define THRESHOLD 80 // Lines longer than this get printed

int main() {
    char line[MAXLINE];

    printf("Enter lines (Ctrl+D or Ctrl+Z to stop):\n");

    while (fgets(line, MAXLINE, stdin) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove newline

        if (strlen(line) > THRESHOLD) {
            printf("%s\n", line);
        }
    }

    return 0;
}