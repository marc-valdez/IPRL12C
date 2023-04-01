#define MAX 100

char get_char(char *prompt, char *limit)
{
	char buffer[MAX];
	
	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
        if(strlen(buffer) > 2)
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Character limit is: %d\n\n", 1);
            continue;
        }
        
        if(strlen(buffer) < 2)
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a character.\n\n");
            continue;
        }
        
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts: %s\n", limit);
            continue;
        }
		
        return buffer[0];
	}
}

int get_int(char *prompt, char *limit, int min, int max)
{
	char buffer[MAX];
	int user_input;
	
	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts %s\n", limit);
            continue;
        }
        
        if(sscanf(buffer, "%d", &user_input) != 1)
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number.\n\n");
            continue;
        }
        
        if(user_input < min || user_input > max) 
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number between %d and %d.\n\n", min, max);
            continue;
        }
		
        return user_input-1;
	}
}