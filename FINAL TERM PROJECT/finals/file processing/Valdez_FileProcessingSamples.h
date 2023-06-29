#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fp_sample1()
{
    // create a file pointer called inputf
    // then declare an integer variable called c
    FILE *inputf;
    char c;

    // open the text file for input
    if((inputf = fopen("input.txt", "r")) == NULL)
    {
        // this error happens when the file cannot be opened
        // it then exits the program with a value of 1 indicating an error
        printf("ERROR: input.txt cannot be opened.\n");
        return;
    }

    // read one character at a time from the file
    // then output each chacracter read onto the screen
    // repeat until the end-of-file is reached
    while((c = fgetc(inputf)) != EOF)
        printf("%c", c);

    // safely close the file
    fclose(inputf);
}

void fp_sample2()
{
    // create a file pointer called inputf
    // then declare an character variable called c
    // next create a string variable called filename
    FILE *inputf;
    char c;

    // ask the user for the filename to open
    char filename[MAX];
    get_string(filename, MAX, "> Input name of input text file: ");

    // open text file for input using the filename given by the user
    if((inputf = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", filename);
        return;
    }

    // simply print the contents of the file
    while((c = fgetc(inputf)) != EOF)
        printf("%c", c);

    // safely close the file
    fclose(inputf);
}

void fp_sample3()
{
    FILE *inputf;
    char filename[MAX];
    get_string(filename, MAX, "> Input name of input text file: ");
    char c;

    if((inputf = fopen(filename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", filename);
        return;
    }

    while((c = fgetc(inputf)) != EOF)
        fputc(c, stdout);

    fclose(inputf);
}

void fp_sample4()
{
    // declare two file pointers, one for input, one for output
    FILE *inputf;
    FILE *outputf;

    // create strings for the input and output file names
    // as well as the character variable to read from the input file
    char inputfilename[MAX];
    char outputfilename[MAX];
    char c;

    get_string(inputfilename, MAX, "> Input name of input text file: ");
    get_string(outputfilename, MAX, "> Input name of output text file: ");

    // open input file
    if((inputf = fopen(inputfilename, "r")) == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", inputfilename);
        return;
    }

    // open output file
    outputf = fopen(outputfilename, "w");

    // read one character at a time from input file
    // then output each character onto the output file
    while((c = fgetc(inputf)) != EOF)
        fputc(c, outputf);

    // safely close the files
    fclose(inputf);
    fclose(outputf);
}

void fp_sample5()
{
    // declare the file pointer as well as the string variable
    FILE *outputf;
    char outputfilename[MAX];
    get_string(outputfilename, MAX, "> Input name of output text file: ");

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

    // open text file for output
    outputf = fopen(outputfilename, "w");

    // output formatted data onto text file
    fprintf(outputf, "ch = %c\n", ch);
    fprintf(outputf, "i = %d\n", i);
    fprintf(outputf, "f = %f\n", f);
    fprintf(outputf, "d = %lf\n", d);
    fprintf(outputf, "Goodbye!\n");

    fclose(outputf);
}

void fp_sample6()
{
    FILE *inputf;
    char ch;
    int i;
    float f;
    double d;
    char mystr[40];

    // ask for filename, open text file for input
    char inputfilename[MAX];
    get_string(inputfilename, MAX, "> Input name of output text file: ");

    inputf = fopen(inputfilename, "r");

    // input formatted data from text file
    fscanf_s(inputf, "%c", &ch);
    fscanf_s(inputf, "%d", &i);
    fscanf_s(inputf, "%f", &f);
    fscanf_s(inputf, "%lf", &d);
    fscanf_s(inputf, "%s", mystr);

    // output data - use fprintf()
    // note that the output can also be done using prinf()
    fprintf(stdout, "ch = %c\n", ch);
    fprintf(stdout, "i = %d\n", i);
    fprintf(stdout, "f = %f\n", f);
    fprintf(stdout, "d = %lf\n", d);
    fprintf(stdout, "mystr = %s\n", mystr);

    fclose(inputf);
}

void fileprocessing_samples()
{
    // this is just a simple selection menu for the fp_sample codes above
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("File Processing Example Programs | [0] Go back | [-1] Exit\n");
        printf("  [1] The following sample program opens a text file named “test.txt”, read its contents one character at a time, prints it and finally and closes the file.\n");
        printf("  [2] The following program is an improvement of the previous program. In the following program, the user is allowed to input any filename.\n");
        printf("  [3] This is a simple primitive version of the DOS command “type” or the UNIX command “cat”\n");
        printf("  [4] This is a very simple text file copy utility program.\n");
        printf("  [5] The following program shows how to perform formatted text file OUTPUT using the primitive data types.\n");
        printf("  [6] The following program shows how to perform formatted text file INPUT using the primitive data types. \n");

        // for(int i = 1; i <= 7; i++)
        //     printf("  Example [%d]\n", i);

        int choice, min = -1, max = 6;
        get_int(&choice, min, max, "> Please select an option: ");
        system("cls");

        switch(choice)
        {
            case -1: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
                break;
            }
            case 0: {
                char answer = yes_or_no("Return to previous menu? (y/n): ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: fp_sample1(); break;
            case 2: fp_sample2(); break;
            case 3: fp_sample3(); break;
            case 4: fp_sample4(); break;
            case 5: fp_sample5(); break;
            case 6: fp_sample6(); break;
        }
        system("pause");
    }
}