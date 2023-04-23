#include <stdio.h>
#include <stdlib.h>
#include "valdez_v2.h"

#define INITIAL_BALANCE 5000.00

void balance_inquiry();
void deposit();
void withdrawal();
void change_account();

void main()
{
    printf("WELCOME TO LPU BANK\n");

    printf("[1] Balance Inquiry\n");
    printf("[2] Deposit\n");
    printf("[3] Withdrawal\n");
    printf("[4] Logout \\ Change Account\n");
    printf("[5] Balance Inquiry\n");

    int min = 1, max = 5;
    int in = *(int *)get_number(INTEGER, "\nEnter transaction number. >> ", &min, &max);

    switch(in)
    {
        case 1:
        {
            balance_inquiry();
            break;
        }
        case 2:
        {
            deposit();
            break;
        }
        case 3:
        {
            withdrawal();
            break;
        }
        case 4:
        {
            change_account();
            break;
        }
        case 5:
        {
            exit(0);
            break;
        }
            
    }
}

void balance_inquiry()
{
    printf("You chose [1]\n");
}
void deposit()
{
    printf("You chose [2]\n");
}
void withdrawal()
{
    printf("You chose [3]\n");
}
void change_account()
{
    printf("You chose [4]\n");
}