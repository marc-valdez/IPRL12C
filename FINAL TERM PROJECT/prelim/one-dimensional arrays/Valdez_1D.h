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
    char *menu_items[] = {
        "Initialize a double array for all elements to contain 0.0",
        "Allow the user to enter size, and value of array",
        "Return the lowest value",
        "Return the sum of all elements",
        "Return the number of negative values",
        "See if an integer is found in an array",
        "Copy contents of array A to B",
        "Copy contents of array A to B in reverse",
        "Check if both array A and B have the same values"
    };
    int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);

    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("One Dimensional Array Activities: | [0] Go back | [-1] Exit\n");
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