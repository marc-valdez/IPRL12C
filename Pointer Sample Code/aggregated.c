#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sample1()
{
    char ch;
    int i;
    float f;
    double d;

    char *pch;
    int *pi;
    float *pf;
    double *pd;

    ch = 'A';
    i = 10;
    f = 3.1416;
    d = 105.1;

    // sample use of the address-of operator

    pch = &ch;
    pi = &i;
    pf = &f;
    pd = &d;

    // sample use of the dereference operator

    printf("ch = %d\n", *pch);
    printf("i = %d\n", *pi);
    printf("f = %f\n", *pf);
    printf("d = %lf\n", *pd);
}

void sample2()
{
    int i, j;
    int *p1, *p2, *p3;

    p1 = &i;
    p2 = p1;
    p3 = p1; // p1, p2, p3 all points to i

    *p1 = 10; // note that i will be also be 10

    // access the value 10 directly via i
    printf("i = %d\n", i);

    // access the same value indirectly via pointers p1, p2 and p3
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);
    printf("*p3 = %d\n", *p3);
}

void sample3()
{
    int i;
    int *p1;

    printf("p1 = %d\n", p1);   // ERROR: p1 not initialized
    printf("*p1 = %d\n", *p1); // ERROR: no real memory block

    //p1 = i;   // ERROR: p1 is pointer, i is integer
    //p1 = 100; // ERROR: not really a memory address
    p1 = &i;

    printf("*p1 = %d\n", *p1); // ERROR: i  not initialized
}

void wrong_swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void sample4()
{
    int x, y;

    x = 5;
    y = 10;

    wrong_swap(x, y);

    printf("x = %d, y = %d\n", x, y);
}

void correct_swap(int *px, int *py)
{
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void sample5()
{
    int x, y;

    x = 5;
    y = 10;

    correct_swap(&x, &y); // pass the addresses of x and y as parameters

    printf("x = %d, y = %d\n", x, y);
}

void sample6()
{
    int a[5];
    int *pa;

    // initialize the array
    for (int i = 0; i < 5; i++)
        a[i] = 5 - i;

    puts("\n---------------------------------------\nExample 1:\n");
    // print the contents of the array
    for (int i = 0; i < 5; i++)
    {
        pa = &a[i]; // get i’th element address
        printf("a[%d] = %d\n", i, *pa);
    }

    puts("\n---------------------------------------\nExample 2:\n");
    // same as above but in a different syntax
    pa = &a[0];
    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(pa + i));
    }

    puts("\n---------------------------------------\nExample 3:\n");
    // print in reverse
    pa = &a[4];
    for (int i  = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(pa - i));
    }

    puts("\n---------------------------------------\nExample 4:\n");
    // through pointer arithmetic without using the pointer pa
    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *(a + i));
    }
}

void sample7()
{
    int a[5];
    int *pa;
    int i;

    // initialize the array
    for (i = 0; i < 5; i++)
        a[i] = 5 - i;

    pa = &a[0];

    printf("a[0] = %d\n", *pa);
    pa++;

    printf("a[1] = %d\n", *pa);
    pa++;

    printf("a[2] = %d\n", *pa);
    pa++;

    printf("a[3] = %d\n", *pa);
    pa++;

    printf("a[4] = %d\n", *pa);
}

void sample8()
{
    int a[5];
    int *pa;
    int i;

    // initialize the array
    for (i = 0; i < 5; i++)
        a[i] = 5 - i;

    pa = &a[0];

    printf("*pa = %d\n", *pa);
    pa = pa + 3;

    printf("*pa = %d\n", *pa);
    pa = pa - 2;

    printf("*pa = %d\n", *pa);
    pa--;

    printf("*pa = %d\n", *pa);

    // alternative array access
    pa = &(a[0]);
    for (i = 0; i < 5; i++)
    {
        printf("a[%d] = %d\n", i, *pa);
        pa++;
    }
}

void main()
{
    while(1)
    {
        char *buffer = malloc(sizeof(char) * 256);
        int choice = 0;

        printf("Enter a sample number [1-8] >> ");
        fgets(buffer, strlen(buffer) + 1, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(sscanf(buffer, "%d", &choice) != 1)
        {
            printf("! Please input a number.\n");
        }

        if(choice <= 0 || choice >= 9)
        {
            printf("! Input a number between 1 and 8.\n");
        }

        switch (choice)
        {
            case 1: sample1(); break;
            case 2: sample2(); break;
            case 3: sample3(); break;
            case 4: sample4(); break;
            case 5: sample5(); break;
            case 6: sample6(); break;
            case 7: sample7(); break;
            case 8: sample8(); break;
        }
    }
}