#include <stdio.h>
#include <string.h>

// Defining default boolean sets
#define TRUE 1
#define FALSE 0

int main()
{
    int c, i, j, x, hist_height, max_len;
    int char_count[26];
    char display_str[300];

    /* Default values */
    max_len = 0;

    for(j = 0; j < 26; j++) {
        char_count[j] = 0;
    }

    /* Obtaining input, and counting character occurences */
    while((c = getchar()) != EOF) {
        if(c >= 'a' && c <= 'z') {
            char_count[c-'a']++;
        } else if(c == '\n') {
            break;
        }
    }

    /* Determine max histogram length*/
    for(i = 0; i < 26; i++) {
        if(char_count[i] > max_len) {
            max_len = char_count[i];
        }
    }

    /* Plotting histogram */

    printf("\n");
    printf("\n");

    for(hist_height = max_len; hist_height >= 0; hist_height--) {
        strcpy(display_str, "");
        for(x = 0; x < 26; x++) {
            if(char_count[x] > hist_height) {
                strcat(display_str, " = ");
            } else {
                strcat(display_str, "   ");
            }
        }
        printf("%s \n", display_str);
    }

    printf("------------------------------------------------------------------------------\n");
    printf("\n");
    printf(" a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z\n");
    printf("\n");
    printf("                              (letters)                                   \n ");
    printf("\n");
    return 0;
}

