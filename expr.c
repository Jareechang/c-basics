#include <stdio.h>
#include <ctype.h>

#define FALSE 0
#define MAX 100

char container[MAX];
char *stack = container; /* */
int sp = 0;

int get_op(char *item);
int pop(void);
void push(int item);
int is_operator(char item);

/* expr 2 3 4 + * evaluate to 2 x (3 + 4) */
int main(int argc, char *argv[])
{
    char temp;
    int op2;
    while(--argc > 0) {
        temp = **++argv;
        if(isdigit(temp)) {
            push(atoi(*argv));
        } else if(is_operator(temp)) {
            switch(**argv) {
                case 'x':
                    push(pop() * pop());
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
            }
        } else if (temp == '\n') {
            printf("end of line\n");
        }
    }
    printf("final: %d\n", pop());
}

int is_operator(char item) {
    return item == 'x' || item == '+' || item == '-';
}

void push(int item)
{
    if(sp < MAX) {
        *stack++ = item;
        sp++;
    } else {
        printf("stack is full \n");
    }
}

int pop(void)
{
    if(sp > 0) {
        return *--stack;
    } else {
        printf("stack is empty\n");
        return 0;
    }
}

int get_line(char *line, int max)
{
    int i, c;
    i = 0;
    while((c = getchar()) != EOF) {
        line[i++] = c;
        if(c == '\n') {
            break;
        }
    }
    line[i] = '\0';
    return i;
}
