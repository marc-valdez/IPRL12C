#include ".\file processing\Valdez_FileProcessingMP1.h"
#include ".\file processing\Valdez_FileProcessingMP2.h"

void recursion_MEs()
{
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("File Processing Machine Exercises | [0] Go back | [-1] Exit\n");
        for(int i = 1; i <= 2; i++)
            printf("  Exercise [%d]\n", i);

        int choice, min = -1, max = 2;
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
                char answer = yes_or_no("Return to previous menu? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: exercise1(); break;
            case 2: exercise2(); break;
        }
        system("pause");
    }
}