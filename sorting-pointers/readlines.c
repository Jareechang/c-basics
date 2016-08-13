#include <stdio.h>
#include <string.h>
#include "custom_libs.h"

#define MAXLEN 1000 /* max input length*/

char *alloc(int);
/* readlines: read input lines */

int readlines(char *lineptr[], int maxlines)
{

    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = get_line(line, MAXLEN)) > 0) {
        if(nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
