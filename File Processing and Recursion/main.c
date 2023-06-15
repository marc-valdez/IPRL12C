#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void example1()
{
    // create a file pointer called inputf
    // then declare an integer variable called c
    FILE *inputf;
    char c;

    // open the text file for input
    if((inputf = fopen("test.txt", "r")) == NULL)
    {
        // this error happens when the file cannot be opened
        // it then exits the program with a value of 1 indicating an error
        printf("ERROR: test.txt cannot be opened.\n");
        exit(1);
    }

    // read one character at a time from the file
    // then output each chacracter read onto the screen
    // repeat until the end-of-file is reached
    while((c = fgetc(inputf)) != EOF)
        printf("%c", c);

    // safely close the file
    fclose(inputf);
}

void example2()
{
    // create a file pointer called inputf
    // then declare an character variable called c
    // next create a string variable called filename
    FILE *inputf;
    char c;
    char filename[40];

    // ask the user for the filename to open
    printf("Input name of text file: ");
    scanf("%s", filename);

    // open text file for input using the filename given by the user
    if((inputf = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", filename);
        exit(1);
    }

    // simply print the contents of the file
    while ((c = fgetc(inputf)) != EOF)
        printf("%c", c);
    
    // safely close the file
    fclose(inputf);
}

void example3()
{
    FILE *inputf;
    char filename[40];
    char c;

    printf("Input name of text file: ");
    scanf("%s", filename);

    if((inputf = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", filename);
        exit(1);
    }

    while((c = fgetc(inputf)) != EOF)
        fputc(c, stdout);
    
    fclose(inputf);
}

void main()
{
    // this is just a simple selection menu for the example codes above
    while(1)
    {
        char *buffer = malloc(sizeof(char) * 256);
        int choice = 0;

        puts("----------------------------------------------\n");
        for(int i = 1; i <= 10; i++)
        {
            printf("\tExample [%d]", i);
            ++i;
            printf("\tExample [%d]\n", i);
        }

        printf("\nEnter a example number [1-10] >> ");
        fgets(buffer, strlen(buffer) + 1, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(sscanf(buffer, "%d", &choice) != 1)
        {
            printf("! Please input a number.\n");
            continue;
        }

        if(choice < 1 || choice > 10)
        {
            printf("! Input a number between 1 and 10.\n");
            continue;
        }

        switch (choice)
        {
            case 1: example1(); break;
            case 2: example2(); break;
            case 3: example3(); break;
            // case 4: example4(); break
            // case 5: example5(); break;
            // case 6: example6(); break;
            // case 7: example7(); break;
            // case 8: example8(); break;
            // case 9: example9(); break;
            // case 10: example10(); break;
        }

        puts("\nPress enter to continue...");
        if(choice >= 2 && choice <= 3)
            getchar();
        getchar();
        system("cls");
    }
}