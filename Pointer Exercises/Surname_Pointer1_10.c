#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exer1()
{
    // Write a program that declares one float variable and one double data type variable.
    float f;
    double d;

    // Declare also pointers to these variables.
    float *pf;
    double *pd;

    // Initialize the float and double data tpe variables to any value that you like.
    f = 3.1416;
    d = 105.1;

    // Thereafter, initialize the float pointer such that it has the address of the float variable;
    pf = &f;

    // and do the same thing for the double data the pointer.
    pd = &d;

    // Print the values dereferenced through the pointers.
    printf("f = %f\n", *pf);
    printf("d = %lf\n", *pd);
}

void exer2()
{
    double d, *pd;

    // Explain the result of the following statements:
    
    // This assigns the address of d to the pointer pd.
    pd = &d;

    // The following statements asks the user for input.
    printf("Input a value: ");
    // Then places the scanned value inside pd, which is an address to d.
    scanf("%lf", pd);

    // This works because scanf() typically looks for &d, and pd is equal to &d.

    printf("\nWhat is the value of d after executing scanf()?\n");
    printf("d = %lf\n", d);

    // The value of d is whatever the user decided to input.
}

int sum(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

void add(int *pc, int a, int b)
{
    *pc = a + b;
}

void exer3()
{
    int a = 10, b = 20;
    int c;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    c = sum(a, b);
    printf("\nsum() returned c = %d\n", c);

    add(&c, a, b);
    printf("add() returned c = %d\n", c);

    printf("\nI prefer to use add() because its shorter.\n");
}

void main()
{
    while(1)
    {
        char *buffer = malloc(sizeof(char) * 256);
        int choice = 0;

        puts("----------------------------------------------\n");
        for(int i = 1; i <= 10; i++)
        {
            printf("\tExercise [%d]", i);
            ++i;
            printf("\tExercise [%d]\n", i);
        }

        printf("\nEnter a exercise number [1-10] >> ");
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
            case 1: exer1(); break;
            case 2: exer2(); break;
            case 3: exer3(); break;
        }

        puts("\nPress enter to continue...");
        while(getchar() != '\n'); // consume newline character left by scanf()
        while(getchar() != '\n'); // wait for user to press enter
        system("cls");
    }
}