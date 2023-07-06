#include "valdez_v3.h"
#include ".\prelim\prelim.h"
#include ".\midterm\midterm.h"
#include ".\finals\finals.h"

int main()
{
    system("cls");
    printf("     === IPRL12C Final Project ===\n");
    printf("      Author: Marc Joshua Valdez\n");
    printf(" Contact: marc.valdez@lpunetwork.edu.ph\n\n");
    system("pause");

    char *menu_items[] = {
        "Prelim",
        "Midterm",
        "Finals"
    };
    int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);
    
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Main Menu | [0] Exit\n");
        print_menu(menu_items, menu_size);

        int choice = get_int(0, menu_size, "> Please select an option: ");

        system("cls");
        switch(choice)
        {
            case 0: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
                break;
            }
            case 1: prelim(); break;
            case 2: midterm(); break;
            case 3: finals(); break;
        }
    }
    return 0;
}