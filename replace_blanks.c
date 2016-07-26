#include <stdio.h>

/* Replace each string of one or more blanks by a single blank */
int main()
{
    int c, n1, lastc;

    // "s dsd sds   " 
    n1 = 0;
    while( (c = getchar()) != EOF ) {
        if(c == ' ') {
            // increment counter
            if(lastc != ' ') {
                putchar(c);
            }
        } else {
            putchar(c);
        }
        lastc = c;
    }
    return 0;
}
