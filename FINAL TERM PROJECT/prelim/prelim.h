#include ".\one-dimensional arrays\Valdez_1D.h"
#include ".\machine exercises\ValdezMJ_ME1.h"
#include ".\machine exercises\ValdezMJ_ME2.h"
#include ".\two-dimensional arrays\Valdez_2D.h"
#include ".\lrt system\Binegas_Valdez_LRTSYS.h"

void prelim()
{
    while(1)
    {
        system("cls");
        printf("Prelim Activities | [0] Go back | [-1] Exit\n");
        printf("  [1] 1D Arrays\n");
        printf("  [2] Machine Exercises 1\n");
        printf("  [3] Machine Exercises 2\n");
        printf("  [4] 2D Arrays\n");
        printf("  [5] LRT System\n");

        int choice, min = -1, max = 5;
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
            case 1: oneD(); break;
            case 2: prelim_ME1(); system("pause"); break;
            case 3: prelim_ME2(); system("pause"); break;
            case 4: twoD(); break;
            case 5: lrt_main(); system("pause"); break;
        }
    }
}