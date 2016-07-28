#include <stdio.h>

int power(int m, int n);

int main()
{
    printf("power function: %d", power(2,5));
    return 0;
}


/* Power: raised to the n-th power; n >= 0*/

int power(int base, int n) {
    int i, p;
    p = 1;

    for(i = 1; i <= n; i++) {
        p = p * base;
    }

    return p;
}
