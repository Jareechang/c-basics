#include <stdio.h>

int lower(int c);

int main()
{

    char letter = 'A';
    letter = lower(letter);

    printf("uppercase: %c\n", letter);
    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c);
}
