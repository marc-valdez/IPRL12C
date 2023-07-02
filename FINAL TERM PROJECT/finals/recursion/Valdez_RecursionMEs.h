#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Series1(int n)
{
    if(n > 0)
    {
        printf("n = %d\n", n);
        Series1(n - 1);
    }
}

void Series2(int n)
{
    if(n > 0)
    {
        Series2(n - 1);
        printf("n = %d\n", n);
    }
}

void rec_sample1()
{
    Series1(5);
    puts("\n");
    Series2(5);
}

// struct node
// {
//     int data;           // data, of course can be any type
//     struct node *left;  // pointer to the left subtree
//     struct node *right; // pointer to the right subtree
// };

// void Visit(struct node *p)
// {
//     // The visit operation can be any operation
//     // depending on the application. In this
//     // fp_sample, we simply print the value of the data.
//     printf("%d ", p->data);
// }

// void PreOrder(struct node *p)
// {
//     if (p != NULL)
//     {
//         Visit(p);
//         PreOrder(p->left);
//         PreOrder(p->right);
//     }
// }
// void InOrder(struct node *p)
// {
//     if (p != NULL)
//     {
//         InOrder(p->left);
//         Visit(p);
//         InOrder(p->right);
//     }
// }

// void PostOrder(struct node *p)
// {
//     if (p != NULL)
//     {
//         PostOrder(p->left);
//         PostOrder(p->right);
//         Visit(p);
//     }
// }

int Mystery(int x, int y)
{
    if(y == 0)
        return x;
    else
        return (Mystery(y, x % y));
}

void rec_exer1()
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

void rec_exer2()
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

void rec_exer3()
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

void rec_exer4()
{
    printf("\nAckermann(0, 10) = %d\n", ackermann(0, 10));
    printf("Ackermann(1, 2) = %d\n", ackermann(1, 2));
    printf("Ackermann(2, 1) = %d\n", ackermann(2, 1));
    printf("Ackermann(3, 0) = %d\n", ackermann(3, 0));
}

void recursion_MEs()
{
    // this is just a simple selection menu for the rec_exer codes above
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Recursion Machine Exercises | [0] Go back | [-1] Exit\n");
        printf("  [1] Series\n");
        printf("  [2] Mystery\n");
        printf("  [3] BLIP BLAP\n");
        printf("  [4] Fibonnaci\n");
        printf("  [5] Ackermann\n");

        int choice, min = -1, max = 5;
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
            case 1: rec_sample1(); break;
            case 2: rec_exer1(); break;
            case 3: rec_exer2(); break;
            case 4: rec_exer3(); break;
            case 5: rec_exer4(); break;
        }
        system("pause");
    }
}