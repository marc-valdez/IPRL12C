#include "valdez_v3.h"

int main()
{
    system("cls");

    // Write a program that will count the number of upper case letters in a text file.

    FILE *inputf;
    char inputfilename[MAX];

    get_string(inputfilename, MAX, "> Input name of input text file: ");
    inputf = fopen(inputfilename, "r");
    if(inputf == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", inputfilename);
        exit(1);
    }

    char c;
    int count = 0;
    while((c = fgetc(inputf)) != EOF)
    {
        if(isupper(c))
            count++;
    }
    printf("There are %d upper case letters in the file.\n", count);

    return 0;
}