#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinaryTree {
    char *value;
    struct BinaryTree *right;
    struct BinaryTree *left;
};

struct BinaryTree *create_tree(char **s, int start, int end);
struct BinaryTree *tree_alloc(void);
char *str_dup(char **s, int mid);

int main()
{
    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = 7;

    int end = (size - 1);  
    int start = 0;
    struct BinaryTree *letters = create_tree(s, start, end);
    printf("value: %s\n", letters->right->value);
    return 0;
}

struct BinaryTree *create_tree(char **s, int start, int end)
{
    int mid = (end + start)/2;
    int i = 0;
    struct BinaryTree *Tree = tree_alloc(); /* allocate memory for tree */

    Tree->value = str_dup(s, mid);

    if(mid == start || mid == end) {
        return Tree;
    }
    Tree->left =  create_tree(s, start, (mid - 1));
    Tree->right =  create_tree(s, (mid + 1), end);
    return Tree;
}

struct BinaryTree *tree_alloc(void)
{
    return (struct BinaryTree *) malloc(sizeof(struct BinaryTree));
}

char *str_dup(char **s, int mid)
{
    char *p;
    p = (char *) malloc(strlen(s[mid]) + 1);
    strcpy(p, s[mid]);
    return p;
}
