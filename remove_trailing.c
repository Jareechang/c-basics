#include <stdio.h>

#define MAXLINE 1000

int is_blank(char c);

int main()
{
    int c;
    char transformed_str[MAXLINE];

    while((c = getchar()) != EOF) {
        if(is_blank(c)) {
            putchar(c);
        }     
    }
    return 0;
}

int is_blank(char c)
{
    return ! (c == '\t' || c == ' ' || c == '\n');
}
