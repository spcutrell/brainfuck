#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX 30000

struct node {
        char val;
        struct node *next;
};

void input(int, char **, char *);
void intrptr(char *s1, int *s2);
struct node *stackinit();
void push(char c, struct node **head);
char pop(struct node **head);
void delstack(struct node **head);

int main(int argc, char **argv)
{
        char input_arr[MAX*sizeof(char)];
        int instr_arr[MAX] = {0};

        input(argc, argv, input_arr);
        intrptr(input_arr, instr_arr);

        return 0;

}

void input(int argc, char **argv, char *s)
{
        FILE *input;
        if (argc > 1) {
                if (!strcmp(argv[1],"-")) {
                        input = stdin;
                } else {
                        input = fopen(argv[1], "r");
                        if (!input) {
                                fprintf(stderr, "Unable to open '%s': %s\n",
                                                argv[1], strerror(errno));
                                exit(EXIT_FAILURE);
                        }
                }
        } else {
                input = stdin;
        }
        char c;
        while (((c=fgetc(input))!=EOF)) {
                if(c != '\n') {
                        *s=c;
                        s++;
                }
        }
}

void intrptr(char *input_arr, int *instr_arr)
{
        int *ptr = instr_arr;
        int instr = 0;
        int brackets[MAX];

        int i;
        char c;
        for (i=0; (c=input_arr[i])!=EOF; ++i) {
                switch(c) {
                        case '>' :
                                ++ptr;
                                break;
                        case '<' :
                                --ptr;
                                break;
                        case '+' :
                                ++*ptr;
                                break;
                        case '-' :
                                --*ptr;
                                break;
                        case '.' :
                                putchar(*ptr);
                                break;
                        case ',' :
                                *ptr = getchar(); 
                                break;
                        case '[' :
                                brackets[instr++]=i; 
                                break;
                        case ']' :
                                if (*ptr>0) {
                                        i=brackets[--instr]; 
                                        --i;
                                }
                                break;
                        default  :
                                break;

                }
        }
}

// Stack Functions 
void push(char c, struct node **head)
{
        return;
}

char pop(struct node **head)
{
        return 0;
}

struct node *stackinit()
{
        struct node *head;
        head = malloc(sizeof(struct node)); 
        head->val = '\0';
        head->next = NULL;
        return head;
}

void delstack(struct node **head)
{
        struct node *cur = *head;
        // Finish Me
        return;
}
