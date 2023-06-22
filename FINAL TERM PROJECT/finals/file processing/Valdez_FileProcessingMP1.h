void fp_exer1()
{
    system("cls");

    // Write a program that will output the characters ‘A’ to ‘Z’ (one character per line) onto a text file whose filename is specified by the user.  
    // Use fputc() for character output.

    FILE *outputf;
    char outputfilename[MAX];

    get_string(outputfilename, MAX, "> Input name of output text file: ");
    outputf = fopen(outputfilename, "w");
    if(outputf == NULL)
    {
        printf("ERROR: %s cannot be opened.\n", outputfilename);
        exit(1);
    }

    for(char i = 'A'; i <= 'Z'; i++)
    {
        fputc(i, outputf);
        fprintf(outputf, "\n");
    }

    fclose(outputf);
    return;
}