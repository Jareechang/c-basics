#include <stdio.h>

#define MAXLINE 1000 /* maximun lines */

int obtainline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int i, len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = obtainline(line, MAXLINE)) > 0) {
        copy(longest, line);

        if(len > 80) {
            printf("over 80: %s", longest);
        }
    }
    return 0;
}

int obtainline(char s[], int lim)
{
    int i, c;

    for(i = 0; i <lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if(c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) 
{
    int i;
    i = 0 ;
    while((to[i] = from[i]) != '\0') {
        i++;
    }
}
