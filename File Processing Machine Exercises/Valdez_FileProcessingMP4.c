#include "valdez_v3.h"

/*
    Write a program that will read the integers from the file generated in the previous exercise.
    The program should also print the integers onto the standard output device.
*/

int main()
{
    system("cls");

    FILE *fp;
    fp = fopen("output.txt", "r");
    if(fp == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", "output.txt");
        exit(1);
    }

    int num;
    while(fscanf_s(fp, "%d", &num) == 1) {
        printf("%d\n", num);
    }

    fclose(fp);

    return 0;
}
