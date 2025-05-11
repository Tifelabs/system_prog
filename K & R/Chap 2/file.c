#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    char notes[20];

    // Get user input
    printf("Enter new note: ");
    scanf("%19s", notes);

    // Open file in write mode
    fptr = fopen("note.txt", "w");

    // Check if file opened successfully before writing
    if (fptr == NULL) {
        fprintf(stderr, "Error opening file in main()\n");
        exit(1);
    }

    // Write to file
    fprintf(fptr, "%s", notes);

    // Close the file
    fclose(fptr);

    return 0;
}