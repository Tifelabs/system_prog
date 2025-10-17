/* 
Write an alternate version of squeeze (s1, s2),
that deletes each character in s1 that matches any character in string s2
*/

#include <stdio.h>


void squeeze(char s1[], char s2[]){
    int i; j, k;

    for(i = k = 0; s1[i] != '\0', i++){
        int store = 1;
        for(j = 0; s2[j] != '\0', j++){
            if (s1[i] == s2[j]){
                store = 0;
                break;
            }
        if(store){
            s[k] = s[i];
            k++;
        }
      }
    }
    s1[k] = '\0';
}

int main (void){
    char s1[50], s2[50];
    int i = 0;
    char c;
    while((c == getchar()) != '\n' && c != EOF && i < 49){
        s1[i++] = c;
    }
    s1[i] = '\0';

    i = 0;
    printf("Enter string s2: ");
    while ((c = getchar()) != '\n' && c != EOF && i < 99) {
        s2[i++] = c;
    }
    s2[i] = '\0'; 

    squeeze(s1, s2);

    printf("Resulting string: %s\n", s1);

    return 0;
}