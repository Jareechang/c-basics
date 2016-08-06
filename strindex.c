#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main()
{
    printf("strindex(\"abcabc\", \"ab\") ==> %d\n", strindex("cdfcdf", "cd"));
    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k;

    int s_len = strlen(s);
    int t_len = strlen(t);

    for(i = s_len - t_len; i >= 0; i--) {
        for(j = i, k = 0; t[k] != '\0' && s[i] == t[k]; j++, k++)
            ;
        if(j > 0 && t[j] == '\0')  
            return i;
    }
    return -1;
}

