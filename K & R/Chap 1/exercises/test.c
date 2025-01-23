#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') { // Handles backspace character
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
    return 0;
}