#include "valdez_v3.h"

int main()
{
    system("cls");

    // Write a program that will read the text stored in the file generated by the program in the previous exercise.
    // Use fgetc() for character input.

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
    while((c = fgetc(inputf)) != EOF)
        printf("%c", c);

    return 0;
}