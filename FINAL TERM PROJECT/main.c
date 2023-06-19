#include "valdez_v3.h"
#include "prelim.h"

void main_menu()
{
    while(1)
    {
        printf("Welcome to my FINAL PROJECT!!!\n");
        printf("What would you like see first?\n");
        printf("  1. Prelim\n");
        printf("  2. Midterm\n");
        printf("  3. Finals\n");
        printf("  4. Exit\n");
        int choice = *(int *)get_number(INTEGER, "Please select an option: ", 1, 4);
        system("cls");

        switch (choice)
        {
            case 1: prelim(); break;
            // case 2: midterms(); break;
            // case 3: finals(); break;
            case 4: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    continue;;
                exit_prompt("Thank you for using this program!\n");
            }
        }
    }
}

void main()
{
    main_menu();
    // system("cls");
}