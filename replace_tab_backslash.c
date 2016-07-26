#include <stdio.h>

int main(void)
{
    char c, key;

    while( (c = getchar()) != EOF ) {
        key = getch();

        if(c == '\t') 
        {
            putchar('\\');
            putchar('t');
        }

        else if(c == '\b') 
        {
            putchar('\\');
            putchar('b');
        }

        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }

        if(c != '\t' || c != '\b' || c != '\\') 
        {
            putchar(c);
        }
    }
    return 0;
}
