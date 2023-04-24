#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX 256

bool is_empty(char *buffer, char *prompt);
bool has_whitespace(char *buffer, char *prompt);
bool starts_or_ends_with_dot(char *buffer, char *prompt);

enum data_type {
    CHAR,
    STRING,
    INTEGER,
    FLOAT,
    DOUBLE
};

void *get_number(enum data_type type, char *prompt, void *min, void *max)
{
	char buffer[MAX];
    void *user_input;

	while(true)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        switch(type)
        {
            case INTEGER:
            {
                user_input = malloc(sizeof(int));
                
                if(is_empty(buffer, "\n\t* Input cannot be empty.\n"))
                    continue;
                
                if(has_whitespace(buffer, "\n\t* Invalid input. Input cannot contain whitespace characters.\n"))
                    continue;

                if(starts_or_ends_with_dot(buffer, "\n\t* Invalid input. Please try again.\n"))
                    continue;

                if(sscanf(buffer, "%d", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Input must not contain non-numeric characters.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%f%s", user_input, remaining) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Input must not contain non-numeric characters.\n");
                    continue;
                }

                if(sscanf(buffer, "%d%[.]%s", user_input, remaining, remaining) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be a whole number.\n");
                    continue;
                }

                if(*(int *)user_input < *(int *)min || *(int *)user_input > *(int *)max) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Input out of range. Please enter a number between %d and %d.\n", *(int *)min, *(int *)max);
                    continue;
                }
                
                return (int *)user_input;
            }
            case FLOAT:
            {
                user_input = malloc(sizeof(float));
                
                if(is_empty(buffer, "\n\t* Input cannot be empty.\n"))
                    continue;
                
                if(has_whitespace(buffer, "\n\t* Invalid input. Input cannot contain whitespace characters.\n"))
                    continue;

                if(starts_or_ends_with_dot(buffer, "\n\t* Invalid input. Please try again.\n"))
                    continue;

                if(sscanf(buffer, "%f", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Input must not contain non-numeric characters.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%f%s", user_input, remaining) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Input must not contain non-numeric characters.\n");
                    continue;
                }

                if(*(float *)user_input < *(float *)min || *(float *)user_input > *(float *)max) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Input out of range. Please enter a number between %f and %f.\n", *(float *)min, *(float *)max);
                    continue;
                }
                
                return (float *)user_input;
            }
            case DOUBLE:
            {
                user_input = malloc(sizeof(double));
                
                if(is_empty(buffer, "\n\t* Input cannot be empty.\n"))
                    continue;
                
                if(has_whitespace(buffer, "\n\t* Invalid input. Input cannot contain whitespace characters.\n"))
                    continue;

                if(starts_or_ends_with_dot(buffer, "\n\t* Invalid input. Please try again.\n"))
                    continue;

                if(sscanf(buffer, "%lf", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Input must not contain non-numeric characters.\n");
                    continue;
                }

                char remaining[MAX];
                if(sscanf(buffer, "%lf%s", user_input, remaining) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Input must not contain non-numeric characters.\n");
                    continue;
                }

                if(*(double *)user_input < *(double *)min || *(double *)user_input > *(double *)max) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Input out of range. Please enter a number between %lf and %lf.\n", *(double *)min, *(double *)max);
                    continue;
                }
                
                return (double *)user_input;
            }
        }
	}
}

void *get_text(enum data_type type, char *prompt, char *limit)
{
	char buffer[MAX];
    void *user_input;

	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
		
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts \"%s\"\n", limit);
            continue;
        }
        
        switch(type)
        {
            case CHAR:
            {
                user_input = malloc(sizeof(char));

                if(sscanf(buffer, "%s", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be a single character.\n[%s]");
                    continue;
                }

                if(strlen((char *)user_input) > 1) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Character limit is: %d\n", 1);
                    continue;
                }
                
                return (char *)user_input;
            }
            case STRING:
            {
                user_input = malloc(sizeof(char) * MAX);

                if(sscanf(buffer, "%s", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be a string of characters.\n");
                    continue;
                }

                if(strlen((char *)user_input) > MAX) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Character limit is: %d\n", MAX);
                    continue;
                }
                
                return (char *)user_input;
            }
        }
	}
}

bool is_empty(char *buffer, char *prompt)
{
    if(buffer[0] == '\0')
    {
        strcpy(buffer, "");
        printf(prompt);
        return true;
    }
    return false;
}

bool has_whitespace(char *buffer, char *prompt)
{
    if(strchr(buffer, ' ') != NULL)
    {
        strcpy(buffer, "");
        printf(prompt);
        return true;
    }
    return false;
}

bool starts_or_ends_with_dot(char *buffer, char *prompt)
{
    if(buffer[0] == '.' || buffer[strlen(buffer)-1] == '.')
    {
        strcpy(buffer, "");
        printf(prompt);
        return true;
    }
    return false;
}