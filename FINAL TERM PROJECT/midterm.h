

void midterm()
{
    while(1)
    {
        printf("Midterm Activities | [0] Go back | [-1] Exit\n");

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
            
        }
    }
}