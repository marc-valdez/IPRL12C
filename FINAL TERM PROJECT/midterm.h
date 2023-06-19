#include "Valdez_PointerSamples.h"
#include "Valdez_PointerMEs.h"
#include "Valdez_StructATM.h"

void midterm()
{
    while(1)
    {
        printf("Midterm Activities | [0] Go back | [-1] Exit\n");
        printf("  [1] Pointer Samples\n");
        printf("  [2] Pointer Machine Exercises\n");
        printf("  [3] Struct-based ATM System\n");

        int choice = *(int *)get_number(INTEGER, "> Please select an option: ", -1, 6);
        system("cls");

        switch (choice)
        {
            case -1: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
            }
            case 0: {
                char answer = yes_or_no("Return to main menu? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: pointer_samples(); break;
            case 2: pointer_machine_exercises(); break;
            case 3: struct_ATM(); break;
        }
    }
}