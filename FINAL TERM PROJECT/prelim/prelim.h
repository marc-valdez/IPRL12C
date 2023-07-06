#include ".\one-dimensional arrays\Valdez_1D.h"
#include ".\machine exercises\ValdezMJ_ME1.h"
#include ".\machine exercises\ValdezMJ_ME2.h"
#include ".\two-dimensional arrays\Valdez_2D.h"
#include ".\lrt system\Binegas_Valdez_LRTSYS.h"

void prelim()
{
    char *menu_items[] = {
        "1D Array Machine Exercises",
        "General Machine Exercise 1",
        "General Machine Exercise 2",
        "2D Array Machine Exercises",
        "LRT System"
    };
    int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);

    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Prelim Activities | [0] Go back | [-1] Exit\n");
        print_menu(menu_items, menu_size);

        int choice = get_int(-1, menu_size, "> Please select an option: ");

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
                char answer = yes_or_no("Return to main menu? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: oneD_MEs(); break;
            case 2: prelim_ME1(); system("pause"); break;
            case 3: prelim_ME2(); system("pause"); break;
            case 4: twoD_MEs(); break;
            case 5: lrt_main(); system("pause"); break;
        }
    }
}