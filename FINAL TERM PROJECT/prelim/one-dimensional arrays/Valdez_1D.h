#include "Valdez_1DExer1.h"
#include "Valdez_1DExer2.h"
#include "Valdez_1DExer3.h"
#include "Valdez_1DExer4.h"
#include "Valdez_1DExer5.h"
#include "Valdez_1DExer6.h"
#include "Valdez_1DExer7.h"
#include "Valdez_1DExer8.h"
#include "Valdez_1DExer9.h"

void oneD_MEs()
{
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("One Dimensional Array Activities: | [0] Go back | [-1] Exit\n");
        printf("  [1] Initialize a double array for all elements to contain 0.0\n");
        printf("  [2] Allow the user to enter size, and value of array\n");
        printf("  [3] Return the lowest value\n");
        printf("  [4] Return the sum of all elements\n");
        printf("  [5] Return the number of negative values\n");
        printf("  [6] See if an integer is found in an array\n");
        printf("  [7] Copy contents of array A to B\n");
        printf("  [8] Copy contents of array A to B in reverse\n");
        printf("  [9] Check if both array A and B have the same values\n");

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
                break;
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