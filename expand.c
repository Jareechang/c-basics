#include <stdio.h>

#define FALSE 0
#define MAXLINE 1000

void expand(char s1[], char s2[]);
int is_digit(int digit);
int is_alphabet(int alphabet);

int main()
{
    char letter;
    char str[MAXLINE];
    expand("-a-z0-9--", str);
    printf("new string: %s \n", str);
    return 0;
}

void expand(char s1[], char s2[])
{
    // Parse char for start and end 
    int i, j, k, l, prev, next, letter_start, letter_end;
    int num_start, num_end;
    letter_start = letter_end = FALSE; 
    num_start = num_end = -1;
    i = 0;
    k = 0;

    while(s1[i] != '\0') {
        prev = i - 1;
        next = i + 1;
        if(s1[i] == '-') {
            if(is_digit(s1[next] - '0') && is_digit(s1[prev] - '0')) {
                for(j = 0; j <= (s1[next] - '0'); j++) {
                    s2[k] = '0' + j;
                    k++;
                }
            } else if (is_alphabet(s1[next]) && is_alphabet(s1[prev])) {
                for(l = s1[prev]; l < s1[next]; l++) {
                    s2[k] = l;
                    k++;
                }
            } else {
                s2[k] = s1[i];
                k++;
            }
        }
        i++;
    }
}

int is_digit(int digit)
{
    return (digit >= 0 && digit <= 9);
}

int is_alphabet(int alphabet)
{
    return  (alphabet >= 'a' && alphabet <= 'z');
}
