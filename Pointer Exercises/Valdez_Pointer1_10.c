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
    getchar();
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

void array_average(float *array, int count, float *sum, float *average)
{
    for(int i = 0; i < count; i++)
    {
        printf("A[%d] = %f\n", i, array[i]);
        *sum += array[i];
    }
    *average = *sum / count;
}

void exer4()
{
    // Assume that A is a one-dimensional array of 10 float data type values.
    float A[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float sum = 0.0, average = 0.0;

    // Write a function that will compute the sum and average of the elements of the array.
    array_average(A, sizeof(A)/sizeof(A[0]), &sum, &average);

    printf("sum = %f\n", sum);
    printf("average = %f\n", average);
}

void exer5()
{
    // Assume that A is a one-dimensional array of 10 float data type values.
    float A[10];
    
    // Assume also that pf is a float pointer.
    float *pf;

    // Write a program that will (1) initialize the array.
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        A[i] = i * 3.1416;
    
    // (2) set the pointer pf such that it points to the first element of the array
    pf = A;

    // (3) print all the elements of the array from the first down to the last
    // by performing pointer arithmetic and dereferencing on pf.

    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        printf("A[%d] = %f\n", i, *(pf + i));
}

void exer6()
{
    // Assume that A is a one-dimensional array of 10 double data type values.
    double A[10];
    
    // Assume also that pf is a double pointer.
    double *pd;

    // Write a program that will (1) initialize the array.
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        A[i] = i * 1.618;
    
    // (2) set the pointer pf such that it points to the first element of the array
    pd = A;

    // (3) print all the elements of the array from the first down to the last
    // by performing pointer arithmetic and dereferencing on pf.

    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        printf("A[%d] = %lf\n", i, *(pd + i));
}

void exer7()
{
    // Assume that A is a one-dimensional array of 10 float data type values.
    float A[10];
    
    // Assume also that pf is a float pointer.
    float *pf;

    // Write a program that will (1) initialize the array.
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        A[i] = i * 3.1416;
    
    // (2) set the pointer pf such that it points to the LAST element of the array
    pf = &A[sizeof(A)/sizeof(A[0]) - 1];

    // (3) print all the elements of the array from the last element up to the first
    // by performing pointer arithmetic and dereferencing on pf.
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        printf("A[%d] = %f\n", i, *(pf - i));
}

void exer8()
{
    // Assume that A is a one-dimensional array of 10 double data type values.
    double A[10];
    
    // Assume also that pf is a double pointer.
    double *pd;

    // Write a program that will (1) initialize the array.
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        A[i] = i * 1.618;
    
    // (2) set the pointer pf such that it points to the LAST element of the array
    pd = &A[sizeof(A)/sizeof(A[0]) - 1];

    // (3) print all the elements of the array from the last element up to the first
    // by performing pointer arithmetic and dereferencing on pf.
    for(int i = 0; i < sizeof(A)/sizeof(A[0]); i++)
        printf("A[%d] = %lf\n", i, *(pd - i));
}

void exer9()
{
    // Write a program that will dynamically allocate contigous memory for 10 floating point values.
    float *pf = malloc(sizeof(float) * 10);

    // Initialize them to any value you like, and print the contents.
    for(int i = 0; i < 10; i++)
        *(pf + i) = i * 3.1416;

    for(int i = 0; i < 10; i++)
        printf("pf[%d] = %f\n", i, *(pf + i));
}

void exer10()
{
    // Write a program that will dynamically allocate contigous memory for 10 double point values.
    float *pd = malloc(sizeof(double) * 10);

    // Initialize them to any value you like, and print the contents.
    for(int i = 0; i < 10; i++)
        *(pd + i) = i * 1.618;

    for(int i = 0; i < 10; i++)
        printf("pd[%d] = %f\n", i, *(pd + i));
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
            case 4: exer4(); break;
            case 5: exer5(); break;
            case 6: exer6(); break;
            case 7: exer7(); break;
            case 8: exer8(); break;
            case 9: exer9(); break;
            case 10: exer10(); break;
        }

        puts("\nPress enter to continue...");
        getchar();
        system("cls");
    }
}