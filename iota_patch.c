#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void reverse(char s[]);
void iota(int n, char s[]);

int main(void)
{
    char buffer[20];
    printf("int min: %d\n", -INT_MIN);
    iota(INT_MIN, buffer);
    printf("Buffer: %s\n", buffer);
    return 0;
}

void iota(int n, char s[])
{
    int i, sign;
    if((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = abs(n % 10) + '0'; 
    } while (n /= 10);

    if(sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int length = strlen(s);
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
