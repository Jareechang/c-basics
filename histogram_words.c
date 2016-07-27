#include <stdio.h>
#include <string.h>

#define MIN 0 /* minimum array size */
#define MAX 20 /* maximum array size */

int main()
{
    /* general variables */
    int c,i,j,x, hist[MAX]; 
    int hist_len, max_hist_len;
    int curr_idx;

    /* display specific */
    char display_str[80], x_ticks_str[80];
    int x_axis[MAX], prev_tick;

    /* set initial value for histogram height */
    for(i=0; i <= MAX; i++) {
        hist[i] = 0;
    }

    curr_idx = 0; // current index
    prev_tick = 0; // Set intial x-axis tick tracker
    max_hist_len = 0; // set default histogram length

    while((c = getchar()) != EOF) {
        if(c == ' ' || c == '\n' || c == '\t') {
            if(c == '\n') {
                if(hist[curr_idx] >= max_hist_len) {
                    max_hist_len = hist[curr_idx];
                }
                break;
            }
            curr_idx++;
        } else {
            ++hist[curr_idx];
        }
    }

    /* Spaces */
    printf(" \n");
    printf(" \n");

    for(hist_len = max_hist_len; hist_len >= 0; hist_len--) {
        strcpy(display_str, "");
        // Max height of histogram
        for(j = 0; j <= MAX; j++) {
            if(hist[j] > hist_len) {
                strcat(display_str, " = ");
                prev_tick = j;
            }
            else {
                strcat(display_str, "   ");
            }
        }
        /* output histogram at each level */
        printf("%s \n", display_str);
    }

    /* Divider */
    printf(" -----------------------------------------------------------------------\n");

    for(x = 1; x <= MAX; x++) {
        printf(" %d ", x);
    }

    printf("\n");
}

