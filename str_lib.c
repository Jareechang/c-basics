#include <stdio.h>

#define MAXLINE 1000

/* s_copy: copies 'n' items from s to t*/
void s_copy(char *s, char *t, int n)
{
    int times = 1;
    while((*t++ = *s++) != '\0' && times++ < n)
        ;
}

int main()
{
    char s1[MAXLINE] = "hello";
    char s2[MAXLINE] = "";
    int n = 3;
    s_copy(s1, s2, n);
    printf("original str: %s, copied str: %s, number of letters copied: %d\n", s1, s2, n);
    return 0;
}
