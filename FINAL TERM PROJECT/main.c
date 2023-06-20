#include "valdez_v3.h"
#include "prelim.h"
// #include "midterm.h"
// #include "finals.h"

void main()
{
    while(1)
    {
        system("cls");
        printf("Welcome to the FINAL PROJECT!!!\n\n");
        printf("Main Menu | [0] Exit\n");
        printf("  [1] Prelim\n");
        printf("  [2] Midterm\n");
        printf("  [3] Finals\n");
        
        int choice, min = 0, max = 3;
        get_int(&choice, min, max, "> Please select an option: ");
        
        system("cls");
        switch (choice)
        {
            case 0: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                if (answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
            }
            case 1: prelim(); break;
            // case 2: midterm(); break;
            // case 3: finals(); break;
        }
    }
}