#include <stdio.h>
#include "custom_libs.h"
#include <string.h>

#define MAXLINES 5000 /* max # of lines to be sorted */

char *lineptr[MAXLINES];

int main()
{
    print_lines("hello");
    return 0;
}
