#include <stdio.h>

/* append_space: append spaces in between while not i hasn't
 * reach the end (argc) */
void append_space(int i, argc)
{
    return (i < argc - 1) ? " " : "";
}

int main(int argc, char *argv[])
{
    int i = 1;
    while(i < argc) {
        printf("%s%s", argv[i], append_space(i, argc));
        i++;
    }
    printf("\n");
    return 0;
}

