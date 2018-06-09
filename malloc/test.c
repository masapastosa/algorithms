#include <stdio.h>
#include "malloc.h"

int main() {
    char *foo = malloc(0x1000 * sizeof(char));
    for (int i=0; i<0x1000; i++) foo[i] = i;
    free(foo);
    foo = malloc(0x10 * sizeof(char));
    free(foo);
}
