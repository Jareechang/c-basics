#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int reverse_print(char orig[], int length);
int getinput(char s[],int maxline);
int not_blank(char c);

int main()
{
    int c, len;
    char line[MAXLINE];

    while((len = getinput(line, MAXLINE)) > 0) {
        reverse_print(line, len);
    }
    return 0;
}

/* getinput: gets input from terminal and stores string in 'line' while
 * returning size of array 
 * */
int getinput(char s[], int maxline)
{
    int i, c;
    for(i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    return i;
}

int reverse_print(char orig[], int length)
{
    int i;
    for(i = length; i >= 0; --i) {
        if(not_blank(orig[i])) {
            printf("%c", orig[i]);
        }
    }
    printf("\n");

    return 0;
}

int not_blank(char c)
{
    return ! (c == '\t' || c == ' ' || c == '\n');
}
