#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

enum data_type {
    CHAR,
    STRING,
    INTEGER,
    FLOAT,
    DOUBLE
};

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

                if(sscanf(buffer, "%c", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be a single character.\n\n");
                    continue;
                }

                if(strlen((char *)user_input) > 2) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Character limit is: %d\n\n", 1);
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
                    printf("\n\t* Invalid input. It must be a string of characters.\n\n");
                    continue;
                }

                if(strlen((char *)user_input) > MAX) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Character limit is: %d\n\n", MAX);
                    continue;
                }
                
                return (char *)user_input;
            }
        }
	}
}


void *get_number(enum data_type type, char *prompt, char *limit, void *min, void *max)
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
            case INTEGER:
            {
                user_input = malloc(sizeof(int));

                if(sscanf(buffer, "%d", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be an integer.\n");
                    continue;
                }
                
                if(*(int *)user_input < *(int *)min || *(int *)user_input > *(int *)max) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Please enter a number between %d and %d.\n", *(int *)min, *(int *)max);
                    continue;
                }
                
                return (int *)user_input;
            }
            case FLOAT:
            {
                user_input = malloc(sizeof(float));

                if(sscanf(buffer, "%f", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be a number.\n\n");
                    continue;
                }
                
                if(*(float *)user_input < *(float *)min || *(float *)user_input > *(float *)max) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Please enter a number between %.2f and %.2f.\n", *(float *)min, *(float *)max);
                    continue;
                }
                
                return (float *)user_input;
            }
            case DOUBLE:
            {
                user_input = malloc(sizeof(double));

                if(sscanf(buffer, "%lf", user_input) != 1)
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. It must be a number.\n\n");
                    continue;
                }
                
                if(*(double *)user_input < *(double *)min || *(double *)user_input > *(double *)max) 
                {
                    strcpy(buffer, "");
                    printf("\n\t* Invalid input. Please enter a number between %.2f and %.2f.\n", *(double *)min, *(double *)max);
                    continue;
                }
                
                return (double *)user_input;
            }
        }
	}
}