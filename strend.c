#include <stdio.h>

#define MAXLINE 1000

int str_end(char *s, char *t)
{
    while(*++s != '\0')
        ;
    
    return (*s == *t) ? 1 : -1;
}

int main()
{
    char s1[MAXLINE] = "hello";
    char check[MAXLINE] = "o";
    printf("is \' %s \' in the end of \' %s \' ? %s\n", 
            check, 
            s1, 
            str_end(s1, check) ? "Yes" : "No" );
    return 0;
}
