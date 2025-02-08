//Write a program to  print all input lines  that are longer than 80
//characters

#include <stdio.h>

#define MAXLINE 81

int main() 
	{
	char line[MAXLINE];

	while(1) {
		printf("Enter a  line: ")
		fgets(line, MAXLINE,stdin);
		line [strcspn(line , "\n")] =  0; remove newline character

		if (strlen(line) > MAXLINE  - 1) {
			pritnf("%s\n", line);
		}

		//Check for  EOF
		if (feof(stdin)) break;
	}
	return 0; 

}
