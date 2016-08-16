#include <stdio.h>

char *week_days(int n)
{
    static char *names[] = {
        "illegal week day",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    return (n <= 7 || n >= 1) ? names : names[0];
}

int main()
{
    printf("%c\n", *week_days(2));
}
