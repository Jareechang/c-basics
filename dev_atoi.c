#include <stdio.h>


int dev_atoi(char rand[]);

int main()
{
    int j;
    printf("convert n: %d\n", dev_atoi("123"));
    return 0;
}

int dev_atoi(char rand[])
{
    int i, n;

    n = 0;

    for(i=0; rand[i] >= '0' && rand[i] <= '9'; ++i) {
        n = 10 * n + (rand[i] - '0');
        printf("n inside: %d \n", n);
    }
    return n;
}
