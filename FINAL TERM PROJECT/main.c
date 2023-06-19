#include "valdez_v3.h"
#include "prelim.h"

void oneD()
{
    while(1)
    {
        printf("One Dimensional Array Activities: \n");
        printf("  1. Exercise 1\n");
        printf("  2. Exercise 2\n");
        printf("  3. Exercise 3\n");
        printf("  4. Exercise 4\n");
        printf("  5. Exercise 5\n");
        printf("  6. Exercise 6\n");
        printf("  7. Exercise 7\n");
        printf("  8. Exercise 8\n");
        printf("  9. Exercise 9\n");
        printf("  10. Go back\n");
        printf("  11. Exit\n");
        
        int choice = *(int *)get_number(INTEGER, "Please select an option: ", 0, 11);
        system("cls");

        switch (choice)
        {
            case 1: oneD_exer1(); break;
            case 2: oneD_exer2(); break;
            case 3: oneD_exer3(); break;
            case 4: oneD_exer4(); break;
            case 5: oneD_exer5(); break;
            case 6: oneD_exer6(); break;
            case 7: oneD_exer7(); break;
            case 8: oneD_exer8(); break;
            case 9: oneD_exer9(); break;
            case 10: {
                char answer = yes_or_no("Go back? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                return;
            }
            case 11: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                exit_prompt("Thank you for using this program!\n");
            }
        }
        system("pause");
    }
}

void prelim()
{
    while(1)
    {
        printf("Prelim Activities: \n");
        printf("  1. 1D Arrays\n");
        printf("  2. 2D Arrays\n");

        printf("  4. Go back\n");
        printf("  5. Exit\n");

        int choice = *(int *)get_number(INTEGER, "Please select an option: ", 1, 4);
        cprintf(MAGENTA, "\n\t~!! debug choice:[%d]\n\n", choice);

        switch (choice)
        {
            case 1: oneD(); break;
            case 2: twoD(); break;
            case 4: {
                char answer = yes_or_no("Return to main menu? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                return;
            }
            case 5: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                exit_prompt("Thank you for using this program!\n");
            }
        }
    }
}
void midterms();
void finals();

void main_menu()
{
    while(1)
    {
        printf("Welcome to my FINAL PROJECT!!!\n");
        printf("What would you like see first?\n");
        printf("  1. Prelim\n");
        printf("  2. Midterms\n");
        printf("  3. Final\n");
        printf("  4. Exit\n");
        int choice = *(int *)get_number(INTEGER, "Please select an option: ", 1, 4);
        cprintf(MAGENTA, "\n\t~!! debug choice:[%d]\n\n", choice);

        switch (choice)
        {
            case 1: prelim(); break;
            // case 2: midterms(); break;
            // case 3: finals(); break;
            case 4: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                exit_prompt("Thank you for using this program!\n");
            }
        }
    }
}

void main()
{
    main_menu();
    // system("cls");
}