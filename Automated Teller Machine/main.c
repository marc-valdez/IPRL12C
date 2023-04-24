#include <stdio.h>
#include <stdlib.h>
#include "valdez_v2.h"

#define INITIAL_BALANCE 5000.00

typedef struct Account {
    char *name;
    char *pin_number;
    float balance;
    float withdrawal_amount;
    float deposit;
} Account;

Account users[] = {
    {"Valdez, Marc Joshua", "000000", INITIAL_BALANCE, 0.0, 0.0},
    {"Binegas, John Daniel", "123123", INITIAL_BALANCE, 0.0, 0.0},
    {"Bautista, Glen Angelo", "456456", INITIAL_BALANCE, 0.0, 0.0}
};

Account *account_login();
void print_menu(Account *user);
void balance_inquiry();
void deposit(Account *user);
void withdrawal();
void change_account();

void main()
{
    Account *user = account_login();
    
    printf("\nAccount Name: %s\n", user->name);
    printf("PIN Number: %s\n", user->pin_number);
    printf("Initial Balance: %.2f\n", user->balance);
    printf("Withdrawal Amount: %.2f\n", user->withdrawal_amount);
    printf("Deposit Amount: %.2f\n\n", user->deposit);

    print_menu(user);
}

void print_menu(Account *user)
{
    printf("WELCOME TO LPU BANK");

    while(1)
    {
        printf("\n[1] Balance Inquiry\n");
        printf("[2] Deposit\n");
        printf("[3] Withdrawal\n");
        printf("[4] Logout \\ Change Account\n");
        printf("[5] Exit\n");

        int min = 1, max = 5;
        int in = *(int *)get_number(INTEGER, "\nEnter transaction number >> ", &min, &max);

        switch(in)
        {
            case 1:
            {
                balance_inquiry(user);
                break;
            }
            case 2:
            {
                deposit(user);
                balance_inquiry(user);
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
                printf("\nThank you for banking with us!\n");
                exit(0);
                break;
            }
        }
    }
}

Account *account_login()
{
    while(1)
    {
        char *pin_number = get_text(STRING, "PIN Number >> ", "1234567890");
        for(int i = 0; i < sizeof(users)/sizeof(users[0]); i++)
        {
            if(strcmp(pin_number, users[i].pin_number) == 0)
            {
                printf("Pin %d: %s\n", i, users[i].pin_number);
                return &users[i];
                break;
            }
            else
            {
                continue;
            }
        }
        printf("Wrong PIN.\n");
    }
}

void balance_inquiry(Account *user)
{
    printf("Current Balance: %.2f\n", user->balance);
}

void deposit(Account *user)
{
    while(1)
    {
        float min = -10000.0, max = 10000.00;
        user->deposit = *(float *)get_number(FLOAT, "Deposit amount >> ", &min, &max);

        if(user->deposit <= 0.0)
            printf("\n\t* Deposit amount should be greater than zero.\n\n");
        else
        {
            user->balance += user->deposit;
            break;
        }
    }
}

void withdrawal()
{
    printf("You chose [3]\n");
}
void change_account()
{
    printf("You chose [4]\n");
}