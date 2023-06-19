#include "Valdez_FileProcessingSamples.h"
#include "Valdez_RecursionMEs.h"

void finals()
{
    while(1)
    {
        printf("Midterm Activities | [0] Go back | [-1] Exit\n");
        printf("  [1] File Processing Samples\n");
        printf("  [2] Recursion Machine Exercises\n");
        printf("  [ ] THIS PROGRAM!!!\n");

        int choice = *(int *)get_number(INTEGER, "> Please select an option: ", -1, 2);
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
            case 1: file_processing_examples(); break;
            case 2: recursion_machine_exercises(); break;
        }
    }
}