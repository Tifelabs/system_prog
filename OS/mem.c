#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main (int argc, char *argv[]){
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) address pointed to p: %p\n")
}