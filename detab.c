#include <stdio.h>
#define N 4 /* Set number of columns*/

int print_tabs(int times);
int adjustable_tab(int i, char c);

int main()
{
    int i,c;
    i = 1;

    while((c = getchar()) != EOF) {
        if(adjustable_tab(i,c)) {
            print_tabs(i);
        } else {
            putchar(c);
        }
        if(i == N) {
            i = 0;
        }
        i++;
    }
    return 0;
}

int adjustable_tab(int i, char c)
{
    return (i <= N && c == '\t');
}

int print_tabs(int times)
{
    int j;
    for(j = times; j <= N; j++) {
        printf(" ");
    }
    return 0;
}
