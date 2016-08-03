#include <stdio.h>

int bitcount_fast(unsigned x);

int main()
{
    printf("Count: %d\n", bitcount_fast(15));
    return 0;
}

int bitcount_fast(unsigned x)
{
    int count;
    for(count = 0; x != 0; (x &= (x-1))) {
        count++;
    }
    return count;
}
