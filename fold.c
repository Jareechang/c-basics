#include <stdio.h> 
#include <string.h>

#define N 14 /* Defining the interval to fold the characters */
#define MAXLINE 2000
#define INVALID 0

int shift_str(char str[], int lim);

int main()
{
    int c, i, counter;
    int space_bt; // space back-track index
    char folded_str[MAXLINE];
    
    counter = 1; 
    i = 0; 
    space_bt = INVALID;

    while((c = getchar()) != EOF) {
        if(counter == N) {
            if(space_bt == INVALID) {
                // Shift string and return index
                i = shift_str(folded_str, i);
            } else {
                folded_str[space_bt] = ',';
            }
            counter = 1;
        } else {
            if(c == ' ') {
                space_bt = i;
            }
        }

        folded_str[i] = c; 
        i++;
        counter++;
        
        if(c == '\n') {
            printf("%s \n", folded_str);
            strcpy(folded_str, "");
            i = 0;
            counter = 1;
        }

    }
    return 0;
}

int shift_str(char str[], int lim)
{
    int j;

    for(j = 0; j < lim; j++) {
        if(j == N) {
            str[j] = ',';
            j++;
        } else {
            str[j] = str[j];
        }
    }
    return j;
}
