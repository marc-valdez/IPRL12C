#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "valdez_v2.h"

#define INITIAL_BALANCE 5000.0
#define MAX_WITHDRAWAL_AMOUNT 4000.0

typedef struct Account {
    char *name;
    char *pin_number;

    float balance;

    int withdrawal_count;
    float amount_withdrawn;

    int deposit_count;
    float amount_deposited;
} Account;

Account users[] = {
    {"Valdez, Marc Joshua", "1111", INITIAL_BALANCE, 0, 0.0, 0, 0.0},
    {"Binegas, John Daniel", "2222", INITIAL_BALANCE, 0, 0.0, 0, 0.0},
    {"Bautista, Glen Angelo", "3333", INITIAL_BALANCE, 0, 0.0, 0, 0.0},
    {"Ubaldo, Rhay Allein", "4444", INITIAL_BALANCE, 0, 0.0, 0, 0.0},
    {"Manuel, Joshua", "5555", INITIAL_BALANCE, 0, 0.0, 0, 0.0}
};

Account *account_login();
void main_menu(Account *user);
void balance_inquiry(Account *user);
void deposit(Account *user);
void withdrawal(Account *user);
void generate_report(Account *user);

void main()
{
    while(1)
    {
        Account *user = account_login();

        main_menu(user);
        system("cls");
    }
}

void main_menu(Account *user)
{
    cprintf(DEFAULT, "\nWelcome to %s[1;%dmLPU%s[0;%dm Bank\n", COLOR, RED, COLOR, DEFAULT);

    while(1)
    {
        printf("\n%s[%dm[1]%s[%dm Balance Inquiry\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[2]%s[%dm Deposit\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[3]%s[%dm Withdrawal\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[4]%s[%dm Logout \\ Change Account\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[5]%s[%dm Exit\n", COLOR, CYAN, COLOR, DEFAULT);

        printf("\n%s[%dm[6]%s[%dm Generate Reports\n", COLOR, CYAN, COLOR, DEFAULT);

        int transaction = *(int *)get_number(INTEGER, "\nEnter transaction number >> ", 1.0, 6.0);

        switch(transaction)
        {
            case 1:
            {
                balance_inquiry(user);
                char answer = yes_or_no("\nWould you like to do another transaction? (Y/N) >> ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                {
                    answer = yes_or_no("\nWould you like to exit(Y) or logout(N)? >> ");
                    if(answer == 'Y' || answer == 'y')
                        exit_prompt("Thank you for banking with us!\n");
                    return;
                }
                break;
            }
            case 2:
            {
                deposit(user);
                char answer = yes_or_no("\nWould you like to do another transaction? (Y/N) >> ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                {
                    answer = yes_or_no("\nWould you like to exit(Y) or logout(N) >> ");
                    if(answer == 'Y' || answer == 'y')
                        exit_prompt("Thank you for banking with us!\n");
                    return;
                }
                break;
            }
            case 3:
            {
                withdrawal(user);
                char answer = yes_or_no("\nWould you like to do another transaction? (Y/N) >> ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                {
                    answer = yes_or_no("\nWould you like to exit(Y) or logout(N)? >> ");
                    if(answer == 'Y' || answer == 'y')
                        exit_prompt("Thank you for banking with us!\n");
                    return;
                }
                break;
            }
            case 4:
            {
                char answer = yes_or_no("\nAre you sure you want to logout? (Y/N) >> ");
                system("cls");
                if(answer == 'Y' || answer == 'y')
                    return;
                break;
            }
            case 5:
            {
                char answer = yes_or_no("\nAre you sure you want to exit? (Y/N) >> ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                    break;
                exit_prompt("Thank you for banking with us!\n");
            }
            case 6:
            {
                generate_report(user);
                char answer = yes_or_no("\nWould you like to exit? (Y/N) >> ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                    break;
                exit_prompt("Thank you for banking with us!\n");
            }
        }
    }
}

Account *account_login()
{
    while(1)
    {
        char *pin_number = (char *)get_text(STRING, "%s[%dm\nPIN Number %s[0;%dm>> ", COLOR, DEFAULT, COLOR, CYAN);

        if(strspn(pin_number, "1234567890") != strlen(pin_number))
        {
            cprintf(YELLOW, "\n! Invalid PIN format. Please remove any non-numeric characters and try again (ex: 1234).\n");
            continue;
        }
        
        if(strlen(pin_number) != 4)
        {
            cprintf(YELLOW, "\n! Invalid PIN format. PIN must be exactly 4 digits long.\n");
            continue;
        }

        for(int i = 0; i < sizeof(users)/sizeof(users[0]); i++)
        {
            if(strcmp(pin_number, users[i].pin_number) == 0)
                return &users[i];
            else
                continue;
        }
        
        cprintf(RED, "\n! Wrong PIN.\n");
    }
}

void balance_inquiry(Account *user)
{
    system("cls");
    printf("\nYour current balance is %.2f\n", user->balance);
}

void deposit(Account *user)
{
    while(1)
    {
        float deposit = *(float *)get_number(FLOAT, "\nDeposit amount >> ", INT_MIN, INT_MAX);

        if(deposit <= 0.0)
            cprintf(YELLOW, "\n! Deposit amount should be greater than zero.\n");
        else
        {
            user->balance += deposit;
            user->amount_deposited += deposit;
            user->deposit_count += 1;
            balance_inquiry(user);
            break;
        }
    }
}

void withdrawal(Account *user)
{
    while(1)
    {
        float withdrawal = *(float *)get_number(FLOAT, "\nWithdrawal amount >> ", INT_MIN, INT_MAX);

        if(withdrawal <= 0.0)
            cprintf(YELLOW, "\n! Withdrawal amount should be greater than zero.\n");
        else if(withdrawal > MAX_WITHDRAWAL_AMOUNT)
            cprintf(YELLOW, "\n! Withdrawal exceeded the maximum amount of %.2f\n", MAX_WITHDRAWAL_AMOUNT);
        else if(withdrawal > user->balance)
            cprintf(RED, "\n! Withdrawal exceeds the available balance of %.2f\n", user->balance);
        else
        {
            user->balance -= withdrawal;
            user->amount_withdrawn += withdrawal;
            user->withdrawal_count++;
            balance_inquiry(user);
            break;
        }
    }
}

void generate_report(Account *user)
{
    cprintf(CYAN, "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    cprintf(CYAN, "\tAccount name: %s[%dm%s\n", COLOR, DEFAULT, user->name);
    cprintf(CYAN, "\tPIN number: %s[%dm%s\n", COLOR, DEFAULT, user->pin_number);

    cprintf(CYAN, "\n\tNo. of times deposited: %s[%dm%d\n", COLOR, DEFAULT, user->deposit_count);
    cprintf(CYAN, "\tTotal amount deposited: %s[%dm%.2f\n", COLOR, DEFAULT, user->amount_deposited);
    
    cprintf(CYAN, "\n\tNo. of times withdrawn: %s[%dm%d\n", COLOR, DEFAULT, user->withdrawal_count);
    cprintf(CYAN, "\tTotal amount withdrawn: %s[%dm%.2f\n", COLOR, DEFAULT, user->amount_withdrawn);
    
    cprintf(CYAN, "\n\tAccount balance: %s[%dm%.2f", COLOR, DEFAULT, user->balance);
    cprintf(CYAN, "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}