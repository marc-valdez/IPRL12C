#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX 256
#define COLOR "\x1B"

typedef enum DataType {
    CHAR,
    STRING,
    INTEGER,
    FLOAT,
    DOUBLE
} DataType;

typedef enum TextColor {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    DEFAULT = 0
} TextColor;

void cprintf(const TextColor INPUT, const char *buffer, ...);

int is_empty(const char *buffer);
int has_whitespace(const char *buffer);
int starts_or_ends_with_dot(const char *buffer);

void *get_number(const DataType type, const char *prompt, ...)
{
    double min = INT_MIN, max = INT_MAX;
    int arg_count = 0;

    va_list args, args_copy;
    va_start(args, prompt);

    va_copy(args_copy, args);
    for(int i = 0; i < 2; i++)
    {
        if(va_arg(args_copy, void *) == NULL)
            arg_count += 1;
        else
            break;
    }

    if(arg_count != 0)
    {
        min = va_arg(args, double);
        max = va_arg(args, double);
    }

    va_end(args);
    va_end(args_copy);

    char buffer[MAX];
    void *user_input;

	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        if(is_empty(buffer))
            continue;
        if(has_whitespace(buffer))
            continue;
        if(starts_or_ends_with_dot(buffer))
            continue;

        switch(type)
        {
            case INTEGER:
            {
                user_input = malloc(sizeof(int));

                if(sscanf(buffer, "%d", user_input) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a numeric value.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%f%s", user_input, remaining) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please refrain from using non-numeric characters.\n");
                    continue;
                }

                if(sscanf(buffer, "%d%[.]%s", user_input, remaining, remaining) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a whole number.\n");
                    continue;
                }

                if(*(int *)user_input < (int)min || *(int *)user_input > (int)max) 
                {
                    cprintf(RED, "\n! Input out of range. Please enter a number between %d and %d (inclusive).\n", (int)min, (int)max);
                    continue;
                }
                
                return (int *)user_input;
            }
            case FLOAT:
            {
                user_input = malloc(sizeof(float));

                if(sscanf(buffer, "%f", user_input) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a numeric value.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%f%s", user_input, remaining) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a whole number.\n");
                    continue;
                }

                if(*(float *)user_input < (float)min || *(float *)user_input > (float)max) 
                {
                    cprintf(RED, "\n! Input out of range. Please enter a number between %f and %f (inclusive).\n", (float)min, (float)max);
                    continue;
                }
                
                return (float *)user_input;
            }
            case DOUBLE:
            {
                user_input = malloc(sizeof(double));

                if(sscanf(buffer, "%lf", user_input) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a numeric value.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%lf%s", user_input, remaining) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a whole number.\n");
                    continue;
                }

                if(*(double *)user_input < (double)min || *(double *)user_input > (double)max) 
                {
                    cprintf(RED, "\n! Input out of range. Please enter a number between %lf and %lf (inclusive).\n", (double)min, (double)max);
                    continue;
                }
                
                return (double *)user_input;
            }
        }
	}
}

void *get_text(const DataType type, const char *input, ...)
{
    char *prompt = malloc(strlen(input)+1);

    va_list args;
    va_start(args, input);

    vsprintf(prompt, input, args);

    va_end(args);

    char buffer[MAX];
    void *user_input;

	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(is_empty(buffer))
            continue;
        if(has_whitespace(buffer))
            continue;
        if(starts_or_ends_with_dot(buffer))
            continue;

        switch(type)
        {
            case CHAR:
            {
                user_input = malloc(sizeof(char));

                if(sscanf(buffer, "%s", user_input) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a single character.\n");
                    continue;
                }

                if(strlen((char *)user_input) != 1) 
                {
                    cprintf(RED, "\n! Invalid input. Please enter a single character.\n");
                    continue;
                }

                return (char *)user_input;
            }
            case STRING:
            {
                user_input = malloc(sizeof(char) * MAX);

                if(sscanf(buffer, "%s", user_input) != 1)
                {
                    cprintf(RED, "\n! Invalid input. Please enter a string of characters.\n");
                    continue;
                }

                if(strlen((char *)user_input) > MAX) 
                {
                    cprintf(RED, "\n! Invalid input. Character limit is %d characters.\n", MAX);
                    continue;
                }

                return (char *)user_input;
            }
        }
	}
}

int is_empty(const char *buffer)
{
    if(buffer[0] == '\0')
    {
        cprintf(RED, "\n! Input cannot be empty. Please enter a value.\n");
        return 1;
    }
    return 0;
}

int has_whitespace(const char *buffer)
{
    if(strchr(buffer, ' ') != NULL)
    {
        cprintf(RED, "\n! Invalid input. Please try again without using whitespace characters.\n");
        return 1;
    }
    return 0;
}

int starts_or_ends_with_dot(const char *buffer)
{
    if(buffer[0] == '.' || buffer[strlen(buffer)-1] == '.')
    {
        cprintf(RED, "\n! Invalid input. Please enter a value that does not start or end with a period (.) character.\n");
        return 1;
    }
    return 0;
}

void cprintf(const TextColor INPUT, const char *buffer, ...)
{
    va_list args;
    va_start(args, buffer);

    printf("%s[%dm", COLOR, INPUT);
    vprintf(buffer, args);
    printf("%s[%dm", COLOR, DEFAULT);

    va_end(args);
}

void exit_prompt(const char *prompt)
{
    printf(prompt);
    exit(0);
}

char yes_or_no(const char *prompt)
{
    while(1)
    {
        char *buffer = (char *)get_text(CHAR, prompt);
        
        if(strspn(buffer, "YyNn") != strlen(buffer))
        {
            cprintf(RED, "\n! Invalid input. Please enter Y or N to continue.\n");
            continue;
        }
        return buffer[0];
    }
}