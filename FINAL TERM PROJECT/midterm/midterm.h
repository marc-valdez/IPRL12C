#include ".\pointers\Valdez_PointerSamples.h"
#include ".\pointers\Valdez_PointerMEs.h"
#include ".\structures\Valdez_StructSamples.h"
#include ".\atm system\Valdez_StructATM.h"

void midterm()
{
    char *menu_items[] = {
        "Pointer Samples",
        "Pointer Machine Exercises",
        "Struct Samples",
        "Struct-based ATM System"
    };
    int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);
    
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Midterm Activities | [0] Go back | [-1] Exit\n");
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
            case 1: pointer_samples(); break;
            case 2: pointer_MEs(); break;
            case 3: struct_samples(); break;
            case 4: struct_ATM(); break;
        }
    }
}