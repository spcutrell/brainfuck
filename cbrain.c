#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX 30000

void input(int, char **, char *);
void intrptr(char *s1, unsigned int *s2);

int main(int argc, char **argv)
{
    char instr_arr[MAX*sizeof(char)];
    unsigned int result_arr[MAX] = {0};

    input(argc, argv, instr_arr);
    intrptr(instr_arr, result_arr);

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
    while ( (c=fgetc(input)) != EOF ) {
        if(
                c == '>' ||
                c == '<' ||
                c == '+' ||
                c == '-' ||
                c == '.' ||
                c == ',' ||
                c == '[' ||
                c == ']'
          ) {
            *s=c;
            s++;
        }
    }
}

void intrptr(char *instr_arr, unsigned int *result_arr)
{
    unsigned int *ptr = result_arr;
    int instr = 0;
    int bal = 0;
    unsigned int brackets[MAX];

    int i;
    char c;
    for (i=0; (c=instr_arr[i]); ++i) {
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
                if (!*ptr) {
                    bal = 1;
                    while (bal) {
                        ++i;
                        if (instr_arr[i] == '[') {
                            ++bal;
                        } else if (instr_arr[i] == ']') {
                            --bal;
                        }
                    }
                } else {
                    brackets[instr++]=i; 
                }
                break;
            case ']' :
                if (*ptr) {
                    i=brackets[--instr] - 1; 
                } else {
                    --instr;
                }
                break;
            default  :
                break;

        }
    }
}

