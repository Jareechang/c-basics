#include <stdio.h>

#define MAXLINE 1000

/* s_copy: copies 'n' items from s to t*/
void s_copy(char *s, char *t, int n)
{
    int times = 1;
    while((*t++ = *s++) != '\0' && times++ < n)
        ;
}

/* s_cat: concatenate n char from t to s */
void s_cat(char *s, char *t, int n)
{
    while(*++s != '\0') /* find end of first str */
        ;
    s_copy(t, s, n);
}

int main()
{
    char s1[MAXLINE] = "hello";
    char s2[MAXLINE] = "123";
    int n = 3;
    /* testing for s_copy  */

    /*s_copy(s1, s2, n);*/
    /*printf("original str: %s, copied str: %s, number of letters copied: %d\n", s1, s2, n);*/

    /* testing for s_cat */
    s_cat(s1, s2, n);
    printf("combined str: %s strings to combine: %d\n", s1, n);
    return 0;
}
