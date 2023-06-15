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
    if ((inputf = fopen("test.txt", "r")) == NULL)
    {
        // this error happens when the file cannot be opened
        // it then exits the program with a value of 1 indicating an error
        printf("ERROR: test.txt cannot be opened.\n");
        exit(1);
    }

    // read one character at a time from the file
    // then output each chacracter read onto the screen
    // repeat until the end-of-file is reached
    while ((c = fgetc(inputf)) != EOF)
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
    if ((inputf = fopen(filename, "r")) == NULL)
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

    if ((inputf = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", filename);
        exit(1);
    }

    while ((c = fgetc(inputf)) != EOF)
        fputc(c, stdout);

    fclose(inputf);
}

void example4()
{
    // declare two file pointers, one for input, one for output
    FILE *inputf;
    FILE *outputf;

    // create strings for the input and output file names
    // as well as the character variable to read from the input file
    char inputfilename[40];
    char outputfilename[40];
    char c;

    // ask the user for the name of the input file
    printf("Input name of text file: ");
    scanf("%s", inputfilename);

    // open input file
    if ((inputf = fopen(inputfilename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", inputfilename);
        exit(1);
    }

    // ask the user for the name of the output file
    printf("Input name of output text file: ");
    scanf("%s", outputfilename);

    // open output file
    outputf = fopen(outputfilename, "w");

    // read one character at a time from input file
    // then output each character onto the output file
    while ((c = fgetc(inputf)) != EOF)
        fputc(c, outputf);

    // safely close the files
    fclose(inputf);
    fclose(outputf);
}

void example5()
{
    // declare the file pointer as well as the string variable
    FILE *outputf;
    char outputfilename[40];

    // declare the following variables for reading later
    char ch;
    int i;
    float f;
    double d;

    // initialize each variable
    ch = 'A';
    i = 100;
    f = 88.3;
    d = 3.1416;

    // ask for filename, open text file for output
    printf("Input name of output text file: ");
    scanf("%s", outputfilename);
    outputf = fopen(outputfilename, "w");

    // output formatted data onto text file
    fprintf(outputf, "ch = %c\n", ch);
    fprintf(outputf, "i = %d\n", i);
    fprintf(outputf, "f = %f\n", f);
    fprintf(outputf, "d = %lf\n", d);
    fprintf(outputf, "Goodbye!\n");

    fclose(outputf);
}

void main()
{
    // this is just a simple selection menu for the example codes above
    while (1)
    {
        char *buffer = malloc(sizeof(char) * 256);
        int choice = 0;

        puts("----------------------------------------------\n");
        for (int i = 1; i <= 10; i++)
        {
            printf("\tExample [%d]", i);
            ++i;
            printf("\tExample [%d]\n", i);
        }

        printf("\nEnter a example number [1-10] >> ");
        fgets(buffer, strlen(buffer) + 1, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (sscanf(buffer, "%d", &choice) != 1)
        {
            printf("! Please input a number.\n");
            continue;
        }

        if (choice < 1 || choice > 10)
        {
            printf("! Input a number between 1 and 10.\n");
            continue;
        }

        switch (choice)
        {
            case 1: example1(); break;
            case 2: example2(); break;
            case 3: example3(); break;
            case 4: example4(); break;
            case 5: example5(); break;
            // case 6: example6(); break;
            // case 7: example7(); break;
            // case 8: example8(); break;
            // case 9: example9(); break;
            // case 10: example10(); break;
        }

        puts("\nPress enter to continue...");
        if (choice >= 2 && choice <= 5)
            getchar();
        getchar();
        system("cls");
    }
}