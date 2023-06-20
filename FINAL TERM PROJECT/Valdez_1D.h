#include "Valdez_1DExer1.h"
#include "Valdez_1DExer2.h"
#include "Valdez_1DExer3.h"
#include "Valdez_1DExer4.h"
#include "Valdez_1DExer5.h"
#include "Valdez_1DExer6.h"
#include "Valdez_1DExer7.h"
#include "Valdez_1DExer8.h"
#include "Valdez_1DExer9.h"

void oneD()
{
    while(1)
    {
        system("cls");
        printf("=======================================================================================================\n");
        printf("One Dimensional Array Activities: | [0] Go back | [-1] Exit\n");
        printf("  [1] Exercise 1\n");
        printf("  [2] Exercise 2\n");
        printf("  [3] Exercise 3\n");
        printf("  [4] Exercise 4\n");
        printf("  [5] Exercise 5\n");
        printf("  [6] Exercise 6\n");
        printf("  [7] Exercise 7\n");
        printf("  [8] Exercise 8\n");
        printf("  [9] Exercise 9\n");

        int choice, min = -1, max = 9;
        get_int(&choice, min, max, "> Please select an option: ");

        system("cls");
        switch(choice)
        {
            case -1: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                exit_prompt("Thank you for using this program!\n");
            }
            case 0: {
                char answer = yes_or_no("Return to previous menu? (y/n): ");
                if(answer == 'N' || answer == 'n')
                    continue;
                return;
            }
            case 1: oneD_exer1(); break;
            case 2: oneD_exer2(); break;
            case 3: oneD_exer3(); break;
            case 4: oneD_exer4(); break;
            case 5: oneD_exer5(); break;
            case 6: oneD_exer6(); break;
            case 7: oneD_exer7(); break;
            case 8: oneD_exer8(); break;
            case 9: oneD_exer9(); break;
        }
        system("pause");
    }
}