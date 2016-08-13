#include <stdio.h>

#define MAXLINE 1000

/* strcpy: copy one char to another char */
void str_cpy(char *s, char *t)
{
    while((*s = *t) != '\0') 
    {
        s++, t++;
    }
}

/* strcat: concatenate 't' to the end of 's' */
void str_cat(char *s, char *t)
{
    while(*s != '\0') /* get tail of s[] char*/
    {
        ++s;
    }
    str_cpy(s,t);
}

int main(void)
{
    char alpha[MAXLINE] = "abc";
    char beta[MAXLINE] = "123";
    str_cat(alpha, beta);
    printf("str # 1: %s\n", alpha);
    printf("str # 2: %s\n", beta);
    printf("combined str:  %s\n", alpha);
    return 0;
}
