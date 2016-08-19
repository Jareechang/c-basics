#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

/* linked list structure */
struct tnode  {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *add_tree(struct tnode *, char *);
void tree_print(struct tnode*);
/*int get_word(char *, int);*/

struct tnode *talloc(void);
char *str_dup(char *);
void free_tree (struct tnode *p);

int main(void)
{
    struct tnode *root;
    char *first_ptr = "test";
    char *second_ptr = "this";

    root = NULL;
    root = add_tree(root, first_ptr);
    root = add_tree(root, second_ptr);
    tree_print(root);
    free_tree(root); /* free tree memory usuage */
    return 0;
}

/* add_tree: add a node with w, at or below p  */
struct tnode * add_tree(struct tnode *p, char *w)
{
    int cond;
    if(p == NULL) {
        p = talloc(); // Create new node via memory managed func
        p->word = str_dup(w);
        p->count = 1; 
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) { 
        p->count++;
    } else if(cond < 0) { /* less than lexicograpically */ 
        p->left = add_tree(p->left, w);
    } else {
        p->right = add_tree(p->right, w);
    }
    return p;
}

/* tree_print: in-order (recursive) print of tree p */
void tree_print(struct tnode *p)
{
    if(p != NULL) {
        tree_print(p->left);
        printf("%4d %s\n", p->count, p->word);
        tree_print(p->right);
    }
}

/* talloc: make a new node */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/* str_dup: make a duplicate  */

char *str_dup(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
    if(p != NULL) {
        strcpy(p, s);
    }
    return p;
}

void free_tree (struct tnode *p)
{
    if(p != NULL) {
        free_tree(p->left);
        free_tree(p->right);
        free(p->word);
        free(p);
    }
}
