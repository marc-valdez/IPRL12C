#include "valdez_v3.h"

/*
    Assume that there are two text files.
    Write a program that will determine whether these two text files are identical or not (i.e., the contents are the same).
*/

int main()
{
    system("cls");

    FILE *fp1 = open_file("> Input the filename only (without the extension) of the first text file: ", ".txt");
    if(fp1 == NULL)
        exit(1);

    FILE *fp2 = open_file("> Input the filename only (without the extension) of the second text file: ", ".txt");
    if(fp2 == NULL)
        exit(1);

    char c1 = getc(fp1);
    char c2 = getc(fp2);

    while(c1 != EOF && c2 != EOF)
    {
        if(c1 != c2)
        {
            printf("File 1 and File 2 are not identical.\n");
            break;
        }
        c1 = getc(fp1);
        c2 = getc(fp2);
    }
    printf("File 1 and File 2 are identical.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}