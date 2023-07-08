#define MAX_ACCOUNTS 5
#define MAX_WITHDRAWAL_AMOUNT 4000.0

int return_code = 0;

/*
 The struct definition below can be treated as a database table. The fields look like this, with two sample records:
 | PK_student_id | pin  | student_name         | account_balance  | withdraw_history | deposit_history | withrawal_count | deposit_count | is_locked | login_attempts_left |
 | 2022-1-01130  | 1111 | Valdez, Marc Joshua  | 5000.0           | 18000.0          | 25000.0         | 3               | 7             | true      | 0                   |
 | 2022-1-01377  | 2222 | Binegas, John Daniel | 17000.0          | 200.0            | 17200.0         | 1               | 18            | false     | 2                   |
*/
typedef struct Account
{
    char account_number[20];
    char pin_number[10];
    char account_name[30];

    float account_balance;
    float amount_withdrawn;
    float amount_deposited;

    int withdrawal_count;
    int deposit_count;

    int is_locked;
    int pin_tries;
} Account;

/* The following array is for debug purposes only. */
// Account users[] = {
//     {"2022-1-01130", "1111", "Valdez, Marc Joshua", 5000, 0.0, 0.0, 0, 0, false, 3},
//     {"2022-1-01377", "2222", "Binegas, John Daniel", 5000, 0.0, 0.0, 0, 0, true, 3},
//     {"2022-1-01604", "3333", "Bautista, Glen Angelo", 5000, 0.0, 0.0, 0, 0, false, 3},
//     {"2022-1-01764", "4444", "Ubaldo, Rhay Allein", 5000, 0.0, 0.0, 0, 0, true, 3},
//     {"2022-1-01643", "5555", "Manuel, Joshua", 5000, 0.0, 0.0, 0, 0, false, 3}
// };

Account users[MAX_ACCOUNTS];
int users_size = (int)(sizeof(users) / sizeof(users[0]));

Account *account_login();
void pin_login(Account *user);
void transactions(Account *user);

/*
 The program flow is as follows:
 1. Load users from a binary file.
 2. Login a user.
 3. Authenticate the user.
 4. Ask the user for a transaction/s
 5. Process the transaction
 6. Repeat until the user exits/logs off
*/
void struct_ATM()
{
    return_code = 0;
    while(true)
    {
        if(return_code)
            return;

        Account *user = account_login();
        pin_login(user);

        if(user->is_locked)
            continue;

        transactions(user);
        system("cls");
    }
}

/* The next two functions are used to load and save user data to and from a binary file. */
void load_users()
{
    FILE *input = fopen("users.bin", "rb");
    if(input == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }
    users_size = fread(users, sizeof(Account), MAX_ACCOUNTS, input);
    fclose(input);
}

void save_users()
{
    FILE *output = fopen("users.bin", "wb");
    if(output == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }
    fwrite(users, sizeof(Account), users_size, output);
    fclose(output);
}

/*
 The following function is used to login a user.
 It first checks if the input is a valid account number.
 If it is, it then checks if the account is locked.
 If it's not, it returns the address of that account.
 Otherwise, it loops until it finds a valid account.
*/
Account *account_login()
{
    load_users();
    while(true)
    {
        char account_number[MAX];
        get_string(account_number, MAX, "%s[%dm\nStudent ID %s[0;%dm>> ", COLOR, DEFAULT, COLOR, CYAN);

        if(strspn(account_number, "1234567890-") != strlen(account_number))
        {
            cprintf(YELLOW, "\n! Invalid Student ID format. Please remove any non-numeric characters and try again (ex: 20XX-1-12345).\n");
            continue;
        }

        if(account_number[4] != '-' || account_number[6] != '-')
        {
            cprintf(YELLOW, "\n! Invalid Student ID format. Please be mindful of the dashes (ex: 20XX-1-12345).\n");
            continue;
        }

        if(strlen(account_number) != 12)
        {
            cprintf(YELLOW, "\n! Invalid Student ID format. ID must be exactly 12 digits long.\n");
            continue;
        }

        for(int i = 0; i < users_size; i++)
        {
            if(strcmp(account_number, users[i].account_number) == 0)
            {
                if(!users[i].is_locked)
                    return &users[i];
                cprintf(RED, "\n! Your account has been locked. Please contact the IT department to reset your account.\n");
                break;
            }
        }
        cprintf(RED, "\n! Account does not exist.\n");
    }
}

/*
 The following function is used to authenticate the user.
 It first checks if the input is a valid PIN.
 If it is, it then checks if the PIN is correct.
 If it's not, it loops until it finds a valid PIN.
 After too many wrong PIN attempts, the account is locked.
 Otherwise, it allows the user to login.
*/
void pin_login(Account *user)
{
    while(true)
    {
        char pin_number[MAX];
        get_string(pin_number, MAX, "%s[%dm\nPIN Number %s[0;%dm>> ", COLOR, DEFAULT, COLOR, CYAN);

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

        for(int i = 0; i < users_size; i++)
        {
            if(strcmp(pin_number, user->pin_number) == 0)
                return;
            else
                continue;
        }

        if(user->pin_tries != 1)
            cprintf(RED, "\n! Wrong PIN. You have %d tries left before your account is locked.\n", --user->pin_tries);
        else
        {
            user->is_locked = true;
            cprintf(RED, "\n! You entered the wrong PIN too many times. Your account has been locked.\nPlease contact the IT department to reset your account.\n");
            system("pause");
            system("cls");
            return;
        }
    }
}

/*
 The following function is used to extract the name of the user.
 It is primarily used for greeting the user in the main menu.
*/
void extract_name(Account *user, char *first_name, char *last_name)
{
    int i = 0;
    while(true)
    {
        last_name[i] = user->account_name[i];
        i++;

        if(user->account_name[i] == ',')
        {
            last_name[i] = '\0';
            i += 2;
            break;
        }
    }

    int j = 0;
    while(true)
    {
        first_name[j] = user->account_name[i];
        i++;
        j++;

        if(user->account_name[i] == '\0')
        {
            first_name[j] = '\0';
            break;
        }
    }
}

/*
 The following function is used to display the balance of the user.
 It also saves the transaction details to a binary file.
*/
void balance_inquiry(Account *user)
{
    save_users();
    system("cls");
    printf("\nYour current balance is %.2f\n", user->account_balance);
}

/*
 The following function is used to deposit money into the user's account.
 It has no deposit limit.
 It also tracks the number of deposits.
 And lastly, it calls the balance_inquiry function to update the user and save the data to a binary file.
*/
void deposit(Account *user)
{
    while(true)
    {
        float deposit = get_float(INT_MIN, INT_MAX, "\nDeposit amount >> ");

        if(deposit <= 0.0)
            cprintf(YELLOW, "\n! Deposit amount should be greater than zero.\n");
        else
        {
            user->account_balance += deposit;
            user->amount_deposited += deposit;
            user->deposit_count += 1;
            balance_inquiry(user);
            break;
        }
    }
}

/*
 The following function is used to withdraw money from the user's account.
 It has a maximum withdrawal limit of 4000 PHP.
 This limit can be changed by modifying the MAX_WITHDRAWAL_AMOUNT constant.
 It also tracks the number of withdrawals.
 It also calls the balance_inquiry function to update the user and save the data to a binary file.
*/
void withdrawal(Account *user)
{
    while(true)
    {
        float withdrawal = get_float(INT_MIN, INT_MAX, "\nWithdrawal amount >> ");

        if(withdrawal <= 0.0)
            cprintf(YELLOW, "\n! Withdrawal amount should be greater than zero.\n");
        else if(withdrawal > MAX_WITHDRAWAL_AMOUNT)
            cprintf(YELLOW, "\n! Withdrawal exceeded the maximum amount of %.2f\n", MAX_WITHDRAWAL_AMOUNT);
        else if(withdrawal > user->account_balance)
            cprintf(RED, "\n! Withdrawal exceeds the available balance of %.2f\n", user->account_balance);
        else
        {
            user->account_balance -= withdrawal;
            user->amount_withdrawn += withdrawal;
            user->withdrawal_count++;
            balance_inquiry(user);
            break;
        }
    }
}

/*
 The following function is used to generate a report of the user's account.
 It then saves the data to a binary file.
*/
void generate_report(Account *user)
{
    cprintf(CYAN, "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    cprintf(CYAN, "\tAccount name: %s[%dm%s\n", COLOR, DEFAULT, user->account_name);
    cprintf(CYAN, "\tPIN number: %s[%dm%s\n", COLOR, DEFAULT, user->pin_number);

    cprintf(CYAN, "\n\tNo. of times deposited: %s[%dm%d\n", COLOR, DEFAULT, user->deposit_count);
    cprintf(CYAN, "\tTotal amount deposited: %s[%dm%.2f\n", COLOR, DEFAULT, user->amount_deposited);

    cprintf(CYAN, "\n\tNo. of times withdrawn: %s[%dm%d\n", COLOR, DEFAULT, user->withdrawal_count);
    cprintf(CYAN, "\tTotal amount withdrawn: %s[%dm%.2f\n", COLOR, DEFAULT, user->amount_withdrawn);

    cprintf(CYAN, "\n\tAccount balance: %s[%dm%.2f", COLOR, DEFAULT, user->account_balance);
    cprintf(CYAN, "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    save_users();
}

/*
 The next function is a selection menu for the user.
 It displays the menu and waits for the user to select an option.
 The following transactions are available:
 1. Balance Inquiry
 2. Deposit
 3. Withdrawal
 4. Logout / Change Account
 5. Exit
 6. Generate Report
*/
void transactions(Account *user)
{
    char last_name[MAX];
    char first_name[MAX];
    extract_name(user, first_name, last_name);

    cprintf(DEFAULT, "\nGreetings, %s %s!", first_name, last_name);
    cprintf(DEFAULT, "\nWelcome to %s[1;%dmLPU%s[0;%dm Bank!\n", COLOR, RED, COLOR, DEFAULT);

    while(true)
    {
        printf("\n%s[%dm[1]%s[%dm Balance Inquiry\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[2]%s[%dm Deposit\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[3]%s[%dm Withdrawal\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[4]%s[%dm Logout \\ Change Account\n", COLOR, CYAN, COLOR, DEFAULT);
        printf("%s[%dm[5]%s[%dm Exit\n", COLOR, CYAN, COLOR, DEFAULT);

        printf("\n%s[%dm[6]%s[%dm Generate Report\n", COLOR, CYAN, COLOR, DEFAULT);

        int transaction = get_int(1, 6, "\nEnter transaction number >> ");

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
                    {
                        printf("Thank you for banking with us!\n");
                        return_code = 1;
                        return;
                    }
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
                    {
                        printf("Thank you for banking with us!\n");
                        return_code = 1;
                        return;
                    }
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
                    answer = yes_or_no("\nWould you like to exit the program (Y) or logout (N)? >> ");
                    if(answer == 'Y' || answer == 'y')
                    {
                        printf("Thank you for banking with us!\n");
                        return_code = 1;
                        return;
                    }
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
                char answer = yes_or_no("\nAre you sure you want to exit the program? (Y/N) >> ");
                system("cls");
                if(answer == 'N' || answer == 'n')
                    break;
                printf("Thank you for banking with us!\n");
                return_code = 1;
                return;
            }
            case 6:
            {
                generate_report(user);
                char answer = yes_or_no("\nWould you like to exit the program? (Y/N) >> ");
                if(answer == 'N' || answer == 'n')
                {
                    system("cls");
                    answer = yes_or_no("\nWould you like to switch accounts? (Y/N) >> ");
                    if(answer == 'N' || answer == 'n')
                    {
                        system("cls");
                        break;
                    }
                }
                printf("Thank you for banking with us!\n");
                return_code = 1;
                return;
            }
        }
    }
}