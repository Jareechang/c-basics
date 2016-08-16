#include <stdio.h>

/* append_space: append spaces in between while not i hasn't
 * reach the end (argc) */
char *append_space(int argc)
{
    return !(argc == 1) ? " " : "";
}

int main(int argc, char *argv[])
{
    while(argc-- > 0) {
        printf("%s%s", *++argv, append_space(argc));
    }
    printf("\n");
    return 0;
}

