#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int not_blank(char c);
char * parse_lines(char lines[]);
int matches_comment(char lines[], int final_index);

int main()
{
    FILE * fPointer;
    fPointer = fopen("remove_comments_lines.txt", "r");
    char singleLine[150];

    while(fgets(singleLine, 150, fPointer)) {
        printf("%s", parse_lines(singleLine));
    }
    fclose(fPointer);
    return 0;
}


char* parse_lines(char lines[]) 
{
    int final_index;
    int c;
    // Find last index
    for(int i = 0; (c = lines[i]); i++) {
        if(c == '\n') {
            final_index = i - 1; // Last index would be (-1), one before line break
        }
    }

    if(matches_comment(lines, final_index)) {
        strcpy(lines, ""); // If matches, then empty the current line;
    }
    return lines;
}

int matches_comment(char lines[], int final_index)
{
    /* Matching comment style one and two   */
    return (lines[0] == '/' && lines[1] == '/') ||
        (lines[0] == '/' && lines[1] == '*' && 
         lines[final_index - 1] == '*' && lines[final_index] == '/');
}

int not_blank(char c)
{
    return ! (c == '\t' || c == ' ' || c == '\n');
}
