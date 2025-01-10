//Character counting
//A program that counts character

#include <stdio.h>

/*Counting characters in input first version*/

int main(){

    long nc;
    
    nc =  0;

    while (getchar() != EOF){
        ++nc;
        printf("%1d\n",nc);
    }
}


/* NOTE => Long integers are at atleast 32 bits  */

//Self Test
#include <stdio.h>

int main (){

    long nc;

    nc = 0;

    while (getchar() != EOF){
        nc++;
        printf("Characters: %1d",nc);
    }
}

