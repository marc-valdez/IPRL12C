#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Mystery(int x, int y)
{
    if(y == 0)
        return x;
    else
        return (Mystery(y, x % y));
}

void exercise1()
{
    printf("%d\n", Mystery(10, 25));
}

void BLIP(int n)
{
    if(n != 0)
    {
        printf("BLIP = %d\n", n);
        BLIP(n - 1);
    }
}

void BLAP(int n)
{
    if(n != 0)
    {
        BLIP(n);
        BLAP(n - 1);
    }
}

void exercise2()
{
    BLAP(4);
}

int fib(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

void exercise3()
{
    printf("\nFibonnaci(6) = %d\n", fib(6));
}

int ackermann(int m, int n)
{
    if(m == 0)
        return n + 1;
    else if(n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

void exercise4()
{
    printf("\nAckermann(0, 10) = %d\n", ackermann(0, 10));
    printf("Ackermann(1, 2) = %d\n", ackermann(1, 2));
    printf("Ackermann(2, 1) = %d\n", ackermann(2, 1));
    printf("Ackermann(3, 0) = %d\n", ackermann(3, 0));
}

void recursion_machine_exercises()
{
    // this is just a simple selection menu for the exercise codes above
    while(1)
    {
        system("cls");
        puts("----------------------------------------------\n");
        printf("Recursion Machine Exercises | [0] Go back | [-1] Exit\n");
        for(int i = 1; i <= 4; i++)
            printf("  Exercise [%d]\n", i);

        int choice, min = -1, max = 4;
        get_int(&choice, min, max, "> Please select an option: ");

        system("cls");
        switch(choice)
        {
            case -1: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
            }
            case 0: {
                char answer = yes_or_no("Return to previous menu? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: exercise1(); break;
            case 2: exercise2(); break;
            case 3: exercise3(); break;
            case 4: exercise4(); break;
        }
        system("pause");
    }
}