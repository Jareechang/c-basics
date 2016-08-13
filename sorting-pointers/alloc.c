#include <stdio.h>

#include "custom_libs.h"

#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n); /* return pointer to characters */

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}
