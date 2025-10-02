/* 
Write  the function htoi(s), which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer vlaues. The allowable digits
are 0 therought 9, a through f, and A through F.
*/

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]){
    int i = 0;
    int n = 0;

    if(s[i] == '0' && (s[1] == 'x' || s[1] == 'X')){
        i = 2;
    }

    while(s[i] != '\0'){
        if(isdigit(s[i])){
            n = n * 16 + (s[i] - 0);
        } else if (s[i] >= 'a' && s[i] <= 'f'){
            n = n * 16 + (s[i] - 'a' + 10)  /* Converting to lower case */
        } else if (s[i] >= 'A' && s[i] <= 'F'){
            n = n * 16 + (s[i] - 'A' + 10)  /* Converting to uppercase */
        } else{
            break;
        }
        i++
    }
    return n;
}