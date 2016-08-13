#include <stdio.h>
#include "custom_libs.h"
#include <string.h>

#define MAXLINES 5000 /* max # of lines to be sorted */

char *lineptr[MAXLINES];

/* sort the lines */
int main()
{
    int nlines; // numbers of input lines

    printf("initiating program...\n");

    if((nlines = readlines(lineptr, MAXLINES)) > 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }else {
        printf("error: input too large to sort\n");
        return 1;
    }
}
