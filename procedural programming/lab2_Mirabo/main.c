#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IS_NUMBER  0
#define STACK_SIZE 2

int stack_index = 0;
double stack[STACK_SIZE];

void put(double);
double pop(void);

int get_input(char []);

void clear_input(void);

int main(void)
{
    int input_type;
    char input[256];
	double op2;

    while ((input_type = get_input(input)) != EOF)
	{
        switch (input_type) {
            case IS_NUMBER:
				put(atof(input));
				break;

            case '+':
				put(pop() + pop());
				break;

            case '*':
				put(pop() * pop());
				break;

            case '-':
				op2 = pop();
				put(pop() - op2);
				break;

            case '/':
				op2 = pop();
				if (op2 != 0.0)
					put(pop() / op2);
				else
				{
					printf("Error: cant divide by 0!\n");
					clear_input();
				}
				break;

            case '\n':
				printf("Result: %g\n", pop());
				break;

            default:
				printf("Error: unknown input (%s)\n", input);
				clear_input();
        }
    }

	return 0;
}

void put(double val)
{
    if(stack_index > STACK_SIZE)
	{
		printf("Error: stack full!\n");
		exit(1);
	}

    stack[stack_index++] = val;
}

double pop(void)
{
    if(stack_index > 0)
        return stack[--stack_index];

    printf("Error: trying to pop from empty stack!\n");
    exit(1);
}

int get_input(char s[])
{
    int c, i = 0;
 
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
 
    if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}

    if (c == '-')
	{
        if (isdigit(c = getchar()) || c == '.')
		{
            s[++i] = c;
		}
        else
        {
            if (c != EOF)
                ungetc(c, stdin);
            return '-';
        }
	}
 
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
 
    if (c == '.')
	{
        while (isdigit(s[++i] = c = getchar()))
            ;
	}
 
    s[i] = '\0';

    if (c != EOF)
        ungetc(c, stdin);

    return IS_NUMBER;
}

void clear_input(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
		;
}
