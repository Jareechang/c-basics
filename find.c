#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *line, int max);
void print_char(char *line);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int len;
    int found = 0;

    if(argc != 2) {
        printf("command: find pattern\n");

    } else {
        while((len = get_line(line, MAXLINE)) > 0) {
            if(strstr(line, argv[1]) != NULL) {
                printf("%s\n", line);
                found++;
            }
        }
    }

    return found;
}

int get_line(char *line, int max)
{
    int i, c;
    i = 0;
    while((c = getchar()) != EOF) {
        line[i++] = c;
        if(c == '\n') {
            break;
        }
    }
    line[i] = '\0';
    return i;
}

void print_char(char *line)
{
    while(*line != '\0') {
        printf("letter: %c\n", *line++);
    }
}
