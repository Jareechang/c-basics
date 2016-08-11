#include <stdio.h>

#define MAXLINE 1000

int reverse(char s[], int last, int first);

int main()
{
    int c, i, mid;
    char s[MAXLINE];  
    i = 0;
    while((c = getchar()) != EOF) {
        s[i] = c;
        if(c == '\n') {
            mid = (i-1)/2;
            reverse(s, (i - 1), 0);
            printf("reversed string -> %s\n", s);
        }
        i++;
    }
    return 0;
}

int reverse(char s[], int last, int first)
{
    int temp, mid;
    mid = last - first;
    temp = s[first];
    s[first++] = s[last];
    s[last--] = temp;

    return (mid == 2 || mid == 1) ? 1 : reverse(s, last, first);
}
