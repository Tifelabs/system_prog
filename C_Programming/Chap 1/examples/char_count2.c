//Counting characters using the for loop instead of the while loop

//LONG
 #include <stdio.h>

 int  main (){
    long nc;

    for(nc = 0; getchar() != EOF; nc++){
        printf("Characters: %1d",nc);
    }
     return 0;

 }

 //FLOAT
 #include <stdio.h>

int main() {
    float nc;

    // Use a for loop to count characters
    for (nc = 0; getchar() != EOF; nc++) {
        printf("Characters: %.0f\n", nc + 1); // Display count as a whole number
    }

    return 0;
}
