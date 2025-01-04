#include <stdio.h>

//Copy Input to output First Version

int main(){

	int c;

	c = getchar();
	//Reads and check in one step
	while (c != EOF) {
	//Writes the character 
	  putchar(c);
	  c = getchar();
	}
 	return 0;

}


//Copy Input to output Second Version
#include <stdio.h>

main(){
	int c;

	while (( c =  getchar()) != EOF){

	  putchar(c);

}
