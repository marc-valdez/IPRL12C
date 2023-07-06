#include ".\file processing\Valdez_FileProcessingSamples.h"
#include ".\recursion\Valdez_RecursionMEs.h"
#include ".\file processing\Valdez_FileProcessingMEs.h"
#include ".\file processing\Valdez_FileProcessingQuiz.h"

void finals()
{
    char *menu_items[] = {
        "File Processing Samples",
        "Recursion Machine Exercises",
        "File Processing Machine Exercises",
        "File Processing Quiz",
        "THIS PROGRAM!!!"
    };
    int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Finals Activities | [0] Go back | [-1] Exit\n");
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
            case 1: fileprocessing_samples(); break;
            case 2: recursion_MEs(); break;
            case 3: fileprocessing_MEs(); break;
            case 4: fileprocessing_quiz(); break;
        }
    }
}