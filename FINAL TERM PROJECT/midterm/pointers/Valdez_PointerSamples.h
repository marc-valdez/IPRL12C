#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ptr_sample1()
{
    // variable declaration
    char ch;
    int i;
    float f;
    double d;

    // pointer variable declaration
    char *pch;
    int *pi;
    float *pf;
    double *pd;

    // variable data assignment
    ch = 'A';
    i = 10;
    f = 3.1416;
    d = 105.1;

    // ptr_sample use of the address-of operator
    // the addresses of each variable is assigned to their corresponding pointers
    pch = &ch;
    pi = &i;
    pf = &f;
    pd = &d;

    // each data is then printed using the dereferenced pointers
    printf("ch = %d\n", *pch);
    printf("i = %d\n", *pi);
    printf("f = %f\n", *pf);
    printf("d = %lf\n", *pd);
}

void ptr_sample2()
{
    // variable and pointer declarations
    int i;
    int *p1, *p2, *p3;

    // address assignments
    p1 = &i;
    p2 = p1;
    p3 = p1; // p1, p2, p3 all points to i

    // dereferenced assignments to alter the value of i
    *p1 = 10; // note that i will be also be 10

    // access the value 10 directly via i
    printf("i = %d\n", i);

    // access the same value indirectly via pointers p1, p2 and p3
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);
    printf("*p3 = %d\n", *p3);
}

void ptr_sample3()
{
    // variable and pointer declaration
    int i;
    int *p1;

    // the first statement prints out garbage becuase i is not initialized, logic error
    // printf("p1 = %d\n", p1);   // ERROR: p1 not initialized

    // the second statement also prints out garbage because pi isn't pointing to anything, logic error
    // printf("*p1 = %d\n", *p1); // ERROR: no real memory block

    // the first assignment is invalid because an int is being assigned to an int *, compile error
    // p1 = i;   // ERROR: p1 is pointer, i is integer

    // the second assignment is also invalid because a static int is being assigned to an int *, compile error
    // p1 = 100; // ERROR: not really a memory address

    // this is a valid assignment
    p1 = &i;

    // again, i doesn't contain anything so garbage values
    printf("*p1 = %d\n", *p1); // ERROR: i not initialized
}

void wrong_swap(int x, int y)
{
    // this function does swap the values of x and y
    // but these are local variables to the function
    // once the function gives the control back to main()
    // x and y in this function will cease to exist

    int temp;
    temp = x;
    x = y;
    y = temp;

    // a workaround to this would be to perform any other operations that use x and y within this function
    // say printing x and y, you can do it inside here instead of main
    printf("wrong swap: x = %d, y = %d\n", x, y);
    // however, do take note that x and y in main is still not swapped
}

void ptr_sample4()
{
    int x, y;

    x = 5;
    y = 10;

    wrong_swap(x, y);

    // here, x = 5, y = 10 because the function above passes by value,
    // therefore the copies of x and y that swapped within the function dies with it

    printf("x = %d, y = %d\n", x, y);
}

void correct_swap(int *px, int *py)
{
    // this function correctly swaps the values of x and y by utilizing pointers
    // passing by address instead of by value allows us to effectively "overwrite" contents inside memory without needing a return value

    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void ptr_sample5()
{
    int x, y;

    x = 5;
    y = 10;

    correct_swap(&x, &y); // pass the addresses of x and y as parameters

    // because the above function modifies the values inside the memory addresses,
    // x and y's values does swap properly
    printf("x = %d, y = %d\n", x, y);
}

void ptr_sample6()
{
    // declares an array of integers and an integer pointer
    int a[5];
    int *pa;

    // initialize the array
    for(int i = 0; i < 5; i++)
        a[i] = 5 - i;

    puts("\n---------------------------------------\nExample 1:\n");
    // print the contents of the array
    for(int i = 0; i < 5; i++)
    {
        pa = &a[i]; // get i'th element address
        printf("a[%d] = %d\n", i, *pa);
    }

    puts("\n---------------------------------------\nExample 2:\n");
    // same as above but in a different syntax
    pa = &a[0];
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(pa + i));
    }

    // *(pa + i) is the same as a[i]

    puts("\n---------------------------------------\nExample 3:\n");
    // print in reverse
    pa = &a[4];
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(pa - i));
    }

    puts("\n---------------------------------------\nExample 4:\n");
    // through pointer arithmetic without using the pointer pa
    for(int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(a + i));
    }
}

void ptr_sample7()
{
    // declares an integer array, along with an integer pointer and an integer variable
    int a[5];
    int *pa;
    int i;

    // initialize the array
    for(i = 0; i < 5; i++)
        a[i] = 5 - i;

    // assign the address of the first element to pa
    pa = &a[0];

    // print the value of a[0] by derefencing pa
    printf("a[0] = %d\n", *pa);
    pa++;

    // after incrementing by 1 address, dereference and print again
    printf("a[1] = %d\n", *pa);
    pa++;

    // and again...
    printf("a[2] = %d\n", *pa);
    pa++;

    // and again...
    printf("a[3] = %d\n", *pa);
    pa++;

    // and lastly the last element, 
    // any further printf's will cause a garbage value or index out of bounds error
    printf("a[4] = %d\n", *pa);
}

void ptr_sample8()
{
    // declarations
    int a[5];
    int *pa;
    int i;

    // initialize the array
    for(i = 0; i < 5; i++)
        a[i] = 5 - i;

    // assigns the address of the first element of array a to pa
    pa = &a[0];

    // the following lines show different ways of changing the memory address inside pa
    // it can be done by adding blocks of memory, subtracting blocks of memory,
    // incrementing (++) or decrementing (--) by 1 block of memory

    printf("*pa = %d\n", *pa);
    pa = pa + 3;

    printf("*pa = %d\n", *pa);
    pa = pa - 2;

    printf("*pa = %d\n", *pa);
    pa--;

    printf("*pa = %d\n", *pa);

    puts("\n");
    // alternative array access
    // this for loop simplifies the process of incrementing pa by 1 memory block per loop
    pa = &(a[0]);
    for(i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *pa);
        pa++;
    }
}

void ptr_sample9()
{
    // pointer declarations
    char *pch;
    int *pi;
    float *pf;
    double *pd;

    // allocate memory dynamically
    pch = (char *)malloc(sizeof(char));
    pi = (int *)malloc(sizeof(int));
    pf = (float *)malloc(sizeof(float));
    pd = (double *)malloc(sizeof(double));

    // assign data to dynamically allocated memory
    *pch = 'A';
    *pi = 10;
    *pf = 3.1416;
    *pd = 88.3;

    // some other operations…
    printf("%c\n", *pch);
    printf("%d\n", *pi);
    printf("%f\n", *pf);
    printf("%lf\n", *pd);

    // free memory
    free(pch);
    free(pi);
    free(pf);
    free(pd);
}

void ptr_sample10()
{
    // declarations
    int *pa;
    int i;

    // the if statement below checks if pa contains NULL
    // this happens when malloc fails to allocate memory
    // to avoid a memory leakage or logic errors,
    // the code simply exits and sends a 1 to show that the program didn't exit properly

    pa = (int *)malloc(sizeof(int) * 5);
    if(pa == NULL)
    {
        printf("ERROR: no more memory.\n");
        exit(1);
    }

    // initialize the memory block
    for(i = 0; i < 5; i++)
        *(pa + i) = 5 - i;

    // print the contents of memory block
    for(i = 0; i < 5; i++)
        printf("Element %d = %d\n", i, *(pa + i));

    puts("\n---------------------------------------\nAlternative:\n");
    // initialize can be rewritten to this
    for(i = 0; i < 5; i++)
        pa[i] = 5 - i;

    // printing can be rewritten to this
    for(i = 0; i < 5; i++)
        printf("Element %d = %d\n", i, pa[i]);

    free(pa);
}

void pointer_samples()
{
    // this is just a simple selection menu for the ptr_sample codes above
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Pointer Sample Programs | [0] Go back | [-1] Exit\n");
        for(int i = 1; i <= 10; i++)
        {
            printf("  Sample [%d]", i);
            ++i;
            printf("\tSample [%d]\n", i);
        }

        int choice, min = -1, max = 10;
        get_int(&choice, min, max, "> Please select an option: ");

        system("cls");
        switch(choice)
        {
            case -1: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
                break;
            }
            case 0: {
                char answer = yes_or_no("Return to previous menu? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: ptr_sample1(); break;
            case 2: ptr_sample2(); break;
            case 3: ptr_sample3(); break;
            case 4: ptr_sample4(); break;
            case 5: ptr_sample5(); break;
            case 6: ptr_sample6(); break;
            case 7: ptr_sample7(); break;
            case 8: ptr_sample8(); break;
            case 9: ptr_sample9(); break;
            case 10: ptr_sample10(); break;
        }
        system("pause");
    }
}