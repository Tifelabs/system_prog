/* 
Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time.
*/
#include <stdio.h>

#define MAXLINE 101 // Our word bucket can hold 100 letters plus a secret end mark

// This flips your words backwards
void reverse(char word[]) {
    int start = 0; // Start at the front
    int end = 0;   // We’ll find the back

    // Move "end" to the last letter (before the "enter" or end mark)
    while (word[end] != '\n' && word[end] != '\0') {
        end = end + 1;
    }
    end = end - 1; // Step back one to the last real letter

    // Swap letters from start to end until they meet
    while (start < end) {
        char temp = word[start]; // Hold the front letter
        word[start] = word[end]; // Put back letter in front
        word[end] = temp;        // Put front letter in back
        start = start + 1;       // Move front forward
        end = end - 1;           // Move back backward
    }
}

int main() {
    char word[MAXLINE]; // Our bucket for your words

    printf("Say some words, and I’ll flip them! (Press Ctrl+D or Ctrl+Z when done)\n");

    // Keep grabbing your words until you stop
    while (fgets(word, MAXLINE, stdin) != NULL) {
        reverse(word); // Flip the word
        printf("%s", word); // Say it back to you
    }

    return 0;
}