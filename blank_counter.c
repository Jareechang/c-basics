#include <stdio.h>

int main()
{
    int c, n1;

    n1 = 0;
    while( (c = getchar()) != EOF) {
        // predicate for blanks, tabs and newlines
        if(c == ' ' || c == '\t' || c == '\n') {
            n1++;
            printf("%d",n1);
        }
    }
}
