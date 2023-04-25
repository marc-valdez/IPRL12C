#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "valdez_v2.h"

#define INITIAL_BALANCE 5000.0
#define MAX_WITHDRAW 4000.0

typedef struct Account {
    char *name;
    char *pin_number;
    float balance;
    float withdrawal_amount;
    float deposit;
} Account;

Account users[] = {
    {"Valdez, Marc Joshua", "1111", INITIAL_BALANCE, 0.0, 0.0},
    {"Binegas, John Daniel", "2222", INITIAL_BALANCE, 0.0, 0.0},
    {"Bautista, Glen Angelo", "3333", INITIAL_BALANCE, 0.0, 0.0}
};

Account *account_login();
void print_menu(Account *user);
void balance_inquiry(Account *user);
void deposit(Account *user);
void withdrawal(Account *user);

void main()
{
    while(1)
    {
        Account *user = account_login();
        
        printf("\nAccount Name: %s\n", user->name);
        printf("PIN Number: %s\n", user->pin_number);
        printf("Account Balance: %.2f\n", user->balance);
        printf("Last Withdrawal Amount: %.2f\n", user->withdrawal_amount);
        printf("Last Deposit Amount: %.2f\n\n", user->deposit);

        print_menu(user);
        system("cls");
    }
}

void print_menu(Account *user)
{
    printf("WELCOME TO LPU BANK\n");

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
                char in = *(char *)get_text(CHAR, "\nWould you like to do another transaction? [Y/N] >> ", "YyNn");
                if(in == 'n' || in == 'n')
                    return;
                break;
            }
            case 2:
            {
                deposit(user);
                char in = *(char *)get_text(CHAR, "\nWould you like to do another transaction? [Y/N] >> ", "YyNn");
                if(in == 'n' || in == 'n')
                    return;
                break;
            }
            case 3:
            {
                withdrawal(user);
                char in = *(char *)get_text(CHAR, "\nWould you like to do another transaction? [Y/N] >> ", "YyNn");
                if(in == 'n' || in == 'n')
                    return;
                break;
            }
            case 4:
            {
                char in = *(char *)get_text(CHAR, "\nAre you sure you want to Logout? [Y/N] >> ", "YyNn");
                if(in == 'Y' || in == 'y')
                    return;
                break;
            }
            case 5:
            {
                char in = *(char *)get_text(CHAR, "\nAre you sure you want to Exit? [Y/N] >> ", "YyNn");
                if(in == 'n' || in == 'n')
                    break;
                printf("\nThank you for banking with us!\n");
                exit(0);
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
                return &users[i];
            else
                continue;
        }
        print_error("\n\t* Wrong PIN.\n");
    }
}

void balance_inquiry(Account *user)
{
    printf("\nYour current balance is %.2f\n", user->balance);
}

void deposit(Account *user)
{
    while(1)
    {
        float min = INT_MIN, max = INT_MAX;
        user->deposit = *(float *)get_number(FLOAT, "\nDeposit amount >> ", &min, &max);

        if(user->deposit <= 0.0)
            print_error("\n\t* Deposit amount should be greater than zero.\n");
        else
        {
            user->balance += user->deposit;
            balance_inquiry(user);
            break;
        }
    }
}

void withdrawal(Account *user)
{
    while(1)
    {
        float min = INT_MIN, max = INT_MAX;
        user->withdrawal_amount = *(float *)get_number(FLOAT, "\nWithdrawal amount >> ", &min, &max);

        if(user->withdrawal_amount > user->balance)
            print_error("\n\t* Withdrawal exceeds the available balance of %.2f\n", user->balance);
        else if(user->withdrawal_amount <= 0.0)
            print_error("\n\t* Withdrawal amount should be greater than zero.\n"); 
        else if(user->withdrawal_amount > MAX_WITHDRAW)
            print_error("\n\t* Withdrawal exceeded the maximum amount of %.2f\n", MAX_WITHDRAW);
        else
        {
            user->balance -= user->withdrawal_amount;
            balance_inquiry(user);
            break;
        }
    }
}