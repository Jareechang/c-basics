#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next; // Next entry in the chain (incase of hash-key collision)
    char *name; // defined named
    char *defn; // replacement text
};

static struct nlist *hashtab[HASHSIZE];
struct nlist *link_allocate(void);

/* hash: simple hash to map items to an random index in array
 * 31 (prime-number) is used to avoid hash-key collisions */
unsigned hash(char *s)
{
    unsigned hashval;
    for(hashval = 0; *s++ != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
char *str_dup(char *);

int main(void)
{
    char *ptr = "hello";
    char *ptr_second = "hello";
    char *defn_first = "whole new way";
    char *defn_second = "a way to greet someone";

    install(ptr, defn_first);
    install(ptr_second, defn_second);

    struct nlist *np;
    np = lookup(ptr);

    for(np = hashtab[hash(ptr)]; np != NULL; np = np->next) {
        printf("definition: %s\n", np->defn);
    }
    return 0;
}

struct nlist *link_alloc(void)
{
    return (struct nlist *) malloc(sizeof(struct nlist));
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next) {
        if(strcmp(s, np->name) == 0) {
            return np; /* found */
        }
    }
    return NULL; /* defaults to not found */
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    struct nlist *new_link;
    unsigned hashval;

    if((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if(np == NULL || (np->name = str_dup(name)) == NULL) {
            return NULL;
        } 
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else  {
        new_link = link_alloc();
        new_link->name = str_dup(defn);
        new_link->defn = np->defn;
        new_link->next = NULL;
        np->next = new_link;
        np->defn = str_dup(defn);
        /*free((void *) np->defn);*/
    }

    if((np->defn = str_dup(defn)) == NULL) {
        return NULL;
    }

    return np;
}

char *str_dup(char *s)    // make a duplicate of s
{
    char *p;
    p = (char *) malloc(strlen(s)+1);   // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}
