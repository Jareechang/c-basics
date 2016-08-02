#include <stdio.h>

#define MAXLINE 1000

#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]);
int exists(char character, char target[]);

int main()
{
    char s1[MAXLINE] = "wow stuff how";
    char s2[MAXLINE] = "stuff";
    squeeze(s1,s2);
    printf("squeeze result: %s\n",s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
   int i, j, k;
   int found;
   found = FALSE;
   k = 0;

   for(i = j = 0; s1[i] != '\0'; i++) {

       found = FALSE; /* reset the found variable */

       while(s2[j] != '\0' && !found) {
           if(s1[i] == s2[j]) {
               found = TRUE;
           }
           j++;
       }

       j = 0; // Reset

       if(!found) {
           s1[k++] = s1[i];
       } 
   }

   s1[k] = '\0';
}
