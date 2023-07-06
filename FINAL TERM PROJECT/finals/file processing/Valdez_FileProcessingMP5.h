/*
    Write a program that will count the number of vowel letters in a text file.
*/

int fp_exer5()
{
    system("cls");
    
    FILE *fp = open_file("> Input the filename only (without the extension) of the input text file: ", ".txt");
    if(fp == NULL)
        return 1;

    char c;
    int count = 0;
    while((c = fgetc(fp)) != EOF)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
    }
    printf("There are %d vowel letters in the file.\n", count);

    fclose(fp);

    return 0;
}
