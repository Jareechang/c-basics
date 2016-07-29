#include <stdio.h>
#include <string.h>

#define N 4 // Defining tabstop space
#define MAXLINE 1000

int is_blank(char c);
int replace_str(int i, int blank_count, char result[]);

int main()
{
    int c, i, blank_count;
    char result[MAXLINE];

    blank_count = 0;
    i = 0;
    while((c = getchar()) != EOF) {
        if(is_blank(c)) {
            blank_count++; // Start count
        } else {
            // check counter
            i = replace_str(i, blank_count ,result);
            blank_count = 0;
            result[i] = c;
            if(c == '\n') {
                /* Print final result, reset for the next line after line break */
                printf("%s \n", result);
                i = 0;  
                strcpy(result," ");
            }
            i++;
        }
    }
    return 0;
}

/*  replace_str: replaces the spaces with unique indentifier according
 *  to the number of tabstops
 *
 *  Returns the index 'i' to keep track of result index
 * */
int replace_str(int i, int blank_count, char result[])
{
    int j;
    if(blank_count == N) {
        result[i] = '-';
        i++;
    } else if(blank_count > 0){
        for(j = 0; j < blank_count; j++) {
            result[i] = '.';
            i++;
        }
    }
    return i;
}

int is_blank(char c)
{
    return (c == ' ');
}

