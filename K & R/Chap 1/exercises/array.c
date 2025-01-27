/* 
Write a program to print the Histogram of the length of words
in its input.
 */


#include <stdio.h>

#define MAX_LENGTH 1000  // Adjust this value as needed

int main() {
    int counts[MAX_LENGTH + 1] = {0};  // Indexes 1 to MAX_LENGTH, MAX_LENGTH for overflow
    int c, current_length = 0, inside_word = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inside_word) {
                if (current_length > MAX_LENGTH) {
                    counts[MAX_LENGTH]++;
                } else if (current_length > 0) {
                    counts[current_length]++;
                }
                current_length = 0;
                inside_word = 0;
            }
        } else {
            current_length++;
            inside_word = 1;
        }
    }

    // Check for the last word
    if (inside_word) {
        if (current_length > MAX_LENGTH) {
            counts[MAX_LENGTH]++;
        } else if (current_length > 0) {
            counts[current_length]++;
        }
    }

    // Determine the maximum length with non-zero count
    int max_length = 0;
    for (int i = 1; i <= MAX_LENGTH; i++) {
        if (counts[i] > 0 && i > max_length) {
            max_length = i;
        }
    }

    // Print the histogram
    for (int i = 1; i <= max_length; i++) {
        if (counts[i] > 0) {
            printf("%3d: ", i);
            for (int j = 0; j < counts[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    // Check and print overflow entries
    if (counts[MAX_LENGTH] > 0) {
        printf("%3d+: ", MAX_LENGTH);
        for (int j = 0; j < counts[MAX_LENGTH]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}