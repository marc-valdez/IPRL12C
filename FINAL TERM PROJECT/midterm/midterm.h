#include ".\pointers\Valdez_PointerSamples.h"
#include ".\pointers\Valdez_PointerMEs.h"
#include ".\structures\Valdez_StructSamples.h"
#include ".\atm system\Valdez_StructATM.h"

void midterm()
{
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Midterm Activities | [0] Go back | [-1] Exit\n");
        printf("  [1] Pointer Samples\n");
        printf("  [2] Pointer Machine Exercises\n");
        printf("  [3] Struct Samples\n");
        printf("  [4] Struct-based ATM System\n");

        int choice, min = -1, max = 6;
        get_int(&choice, min, max, "> Please select an option: ");

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