/* 
Write a program to determine the ranges of char, short, int, and long
varibles, both signed and unsigned by printing appropriate values from standard
headers and by direct computation.
Harder if you compute them: determine the abges of the various floating-point types
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Print ranges of integer types using standard headers */
void print_integer_ranges_headers() {
    printf("Ranges from <limits.h>:\n");
    printf("Signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("Signed short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short:0 to %u\n", USHRT_MAX);
    printf("Signed int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int:  0 to %u\n", UINT_MAX);
    printf("Signed long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 to %lu\n", ULONG_MAX);
}



/* Print ranges of floating-point types using standard headers */
void print_float_ranges_headers() {
    printf("\nFloating-point ranges from <float.h>:\n");
    printf("Float:         %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Double:        %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Long double:   %Le to %Le\n", LDBL_MIN, LDBL_MAX);
}


int main(int argc, char **agrv) {
    print_integer_ranges_headers();
    print_float_ranges_headers();
    return 0;
}