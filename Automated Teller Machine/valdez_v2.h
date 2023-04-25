#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>

#define MAX 256
#define ERROR_COLOR "\033[31m"
#define RESET_COLOR "\033[0m"

void print_error(const char *prompt, ...);
bool is_empty(char *buffer);
bool has_whitespace(char *buffer);
bool starts_or_ends_with_dot(char *buffer);

enum data_type {
    CHAR,
    STRING,
    INTEGER,
    FLOAT,
    DOUBLE
};

void *get_number(enum data_type type, char *prompt, const double min, const double max)
{
	char buffer[MAX];
    void *user_input;

	while(true)
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
                    print_error("\n! Invalid input. Please enter a numeric value.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%f%s", user_input, remaining) != 1)
                {
                    print_error("\n! Invalid input. Please refrain from using non-numeric characters.\n");
                    continue;
                }

                if(sscanf(buffer, "%d%[.]%s", user_input, remaining, remaining) != 1)
                {
                    print_error("\n! Invalid input. Please enter a whole number.\n");
                    continue;
                }

                if(*(int *)user_input < (int)min || *(int *)user_input > (int)max) 
                {
                    print_error("\n! Input out of range. Please enter a number between %d and %d (inclusive).\n", (int)min, (int)max);
                    continue;
                }
                
                return (int *)user_input;
            }
            case FLOAT:
            {
                user_input = malloc(sizeof(float));

                if(sscanf(buffer, "%f", user_input) != 1)
                {
                    print_error("\n! Invalid input. Please enter a numeric value.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%f%s", user_input, remaining) != 1)
                {
                    print_error("\n! Invalid input. Please enter a whole number.\n");
                    continue;
                }

                if(*(float *)user_input < (float)min || *(float *)user_input > (float)max) 
                {
                    print_error("\n! Input out of range. Please enter a number between %f and %f (inclusive).\n", (float)min, (float)max);
                    continue;
                }
                
                return (float *)user_input;
            }
            case DOUBLE:
            {
                user_input = malloc(sizeof(double));

                if(sscanf(buffer, "%lf", user_input) != 1)
                {
                    print_error("\n! Invalid input. Please enter a numeric value.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%lf%s", user_input, remaining) != 1)
                {
                    print_error("\n! Invalid input. Please enter a whole number.\n");
                    continue;
                }

                if(*(double *)user_input < (double)min || *(double *)user_input > (double)max) 
                {
                    print_error("\n! Input out of range. Please enter a number between %lf and %lf (inclusive).\n", (double)min, (double)max);
                    continue;
                }
                
                return (double *)user_input;
            }
        }
	}
}

void *get_text(enum data_type type, char *prompt, ...)
{
    int character_limit = MAX;
    const char *format = NULL;

    va_list args;
    va_start(args, prompt);

    character_limit = va_arg(args, const int);
    format = va_arg(args, const char *);

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
                    print_error("\n! Invalid input. Please enter a single character.\n");
                    continue;
                }

                if(strlen((char *)user_input) != 1) 
                {
                    print_error("\n! Invalid input. Please enter a single character.\n");
                    continue;
                }

                if(format != NULL)
                {
                    if(strspn(buffer, format) != strlen(buffer))
                    {
                        print_error("\n! Invalid input. Please enter a value that matches the format \"%s\"\n", format);
                        continue;
                    }
                }

                va_end(args);
                return (char *)user_input;
            }

            case STRING:
            {
                user_input = malloc(sizeof(char) * MAX);

                if(sscanf(buffer, "%s", user_input) != 1)
                {
                    print_error("\n! Invalid input. Please enter a string of characters.\n");
                    continue;
                }

                if(strlen((char *)user_input) > character_limit) 
                {
                    print_error("\n! Invalid input. Character limit is %d characters.\n", character_limit);
                    continue;
                }
                
                if(format != NULL)
                {
                    if(strspn(buffer, format) != strlen(buffer))
                    {
                        print_error("\n! Invalid input. Please enter a value that matches the format \"%s\"\n", format);
                        continue;
                    }
                }

                va_end(args);
                return (char *)user_input;
            }
        }
	}
}

void print_error(const char *buffer, ...)
{
    va_list args;
    va_start(args, buffer);
    printf(ERROR_COLOR);
    vprintf(buffer, args);
    printf(RESET_COLOR);
    va_end(args);
}

bool is_empty(char *buffer)
{
    if(buffer[0] == '\0')
    {
        strcpy(buffer, "");
        print_error("\n! Input cannot be empty. Please enter a value.\n");
        return true;
    }
    return false;
}

bool has_whitespace(char *buffer)
{
    if(strchr(buffer, ' ') != NULL)
    {
        strcpy(buffer, "");
        print_error("\n! Invalid input. Please try again without using whitespace characters.\n");
        return true;
    }
    return false;
}

bool starts_or_ends_with_dot(char *buffer)
{
    if(buffer[0] == '.' || buffer[strlen(buffer)-1] == '.')
    {
        strcpy(buffer, "");
        print_error("\n! Invalid input. Please enter a value that does not start or end with a period (.) character.\n");
        return true;
    }
    return false;
}