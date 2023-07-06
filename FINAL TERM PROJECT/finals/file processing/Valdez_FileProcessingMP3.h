/*
    Write a program that will ask the user to input two integers, say n1 and n2.
    The second integer should be greater than the second integer, i.e., n1 < n2.
    Thereafter, the program should output to a text file the integers from n1 to n2(i.e., n1, n1 + 1, …, n2 - 1, n2).
    Output one integer per line.
*/

int fp_exer3()
{
    system("cls");

    int n1 = get_int(0, 100, "Enter the first integer: ");
    int n2 = get_int(n1, 100, "Enter the second integer: ");

    FILE *fp;
    fp = fopen("integers.txt", "w");
    for(int i = n1; i <= n2; i++)
        fprintf(fp, "%d\n", i);
    fclose(fp);

    return 0;
}
