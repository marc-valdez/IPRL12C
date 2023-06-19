#include "valdez_v3.h"
#include "prelim.h"
#include "midterm.h"
#include "finals.h"

void main_menu()
{
    while(1)
    {
        printf("Welcome to the FINAL PROJECT!!!\n\n");
        printf("Main Menu | [0] Exit\n");
        printf("  [1] Prelim\n");
        printf("  [2] Midterm\n");
        printf("  [3] Finals\n");
        int choice = *(int *)get_number(INTEGER, "> Please select an option: ", 0, 3);
        system("cls");

        switch (choice)
        {
            case 0: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    continue;;
                exit_prompt("Thank you for using this program!\n");
            }
            case 1: prelim(); break;
            case 2: midterm(); break;
            case 3: finals(); break;
        }
    }
}

void main()
{
    main_menu();
}