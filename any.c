#include <stdio.h>

#define MAXLINE 1000

#define TRUE 1
#define FALSE 0

int any(char s1[], char s2[]);

int main()
{
    int i;

    char s1[MAXLINE] = "stuff wow";
    char s2[MAXLINE] = "w";
    printf("index found: %d \n", any(s1,s2));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;
    i = 0;
    int index_found = FALSE;

    do {
        for(j = 0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j]) {
                index_found = i; 
            }
        }
        i++;

    } while(index_found == FALSE);

    if(index_found == FALSE) {
        index_found = -1;
    }

    return index_found;
}
