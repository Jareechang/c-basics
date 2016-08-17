#include <stdio.h>

void tail(int n, char *line_ptr);
char *output_list(int i);
void print_lines(int lim, int max);

int main(int argc, char *argv[])
{
    int lim = 10; /* cutoff limit for printing lines */
    int max = 14;
   
    argv++;  /*move pointer up to the argv inputs */

    if(argc > 1) {
        while(argc-- > 1) {
            if(**argv == '-' && *(++(*argv)) == 'n') {
                --(*argv);
                lim = atoi(*++argv);
                print_lines(lim, max);
            }         
        }
    } else {
        print_lines(lim, max);
    }
    return 0;
}

void print_lines(int lim, int max)
{
    while(lim-- > 0) {
        printf("%s\n", output_list(--max));
    }
}

/* output_list: random items indexed by numerical number 0 - 13 */
char *output_list(int i) {
    /* internal static list  */
    static char *fruits[] = {
        "Out of range (index 1-13)"
        "1: stuff",
        "2: Orange",
        "3: Apple",
        "4: Banana",
        "5: Mango",
        "6: Pineapple",
        "7: Guava",
        "8: Watermellon",
        "9: Coconut",
        "10: Grapefruit",
        "11: Grapes",
        "12: Cherries",
        "13: Raspberries",
        "14: Passionfruit"
    };
    return (i > 0 || i < 14) ? fruits[i] : fruits[0];
}
