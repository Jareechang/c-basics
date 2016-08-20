#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_line(char *s, int lim);

int main(void)
{
    int day, month, year;
    char monthname[20];
    char *line[MAXLINE];
    while(get_line(line, sizeof(line)) > 0) {
        if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
            printf("valid: %s\n", line);
        } else if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid: %s\n", line);
        } else {
            printf("in-valid: %s\n", line); 
        }
    }
    return 0;
}

int get_line(char *s, int lim)
{
    int c, i;
    i = 0;
    while(i++ < lim && (c = getchar()) != EOF) {
        *s++ = c;
    }
    ++i;
    *s = '\0';
    return i;
}
