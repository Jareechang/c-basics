#include <stdio.h>

/* Write a program that prints input one word per line */

int main()
{
    int c;
    while((c = getchar()) != EOF )  {
        if(c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }
}
