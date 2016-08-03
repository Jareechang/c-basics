#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);

int main()
{
    char new_str[MAXLINE];
    char string[MAXLINE] = "\n \t \n hello world. \n hello world.\t";
    char test[MAXLINE] = "";
    escape(string, new_str);
    printf("escaped: %s\n", new_str);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j, c;
    j = 0;
    for(i = 0; (c = s[i]) != '\0'; i++) {
        switch(c) {
            case '\t':
                t[j] = '\\';
                j++;
                t[j++] = 't';
                break;
            case '\n':
                t[j] = '\\';
                j++;
                t[j++] = 'n';
                break;
            default:
                t[j] = s[i];
                j++;
                break;
        }
    }
}
