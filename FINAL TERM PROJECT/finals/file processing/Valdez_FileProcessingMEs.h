#include "Valdez_FileProcessingMP1.h"
#include "Valdez_FileProcessingMP2.h"
#include "Valdez_FileProcessingMP3.h"
#include "Valdez_FileProcessingMP4.h"

void fileprocessing_MEs()
{
    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("File Processing Machine Exercises | [0] Go back | [-1] Exit\n");
        printf("  [1] Write a program that will output the characters A to Z (one character per line) onto a text file whose filename is specified by the user. \n");
        printf("  [2] Write a program that will read the text stored in the file generated by the program in the previous exercise.\n");
        printf("  [3] Write a program that asks the user to input two integers, then print all integers from n1 to n2 on to a text file. \n");
        printf("  [4] Write a program that will read the integers from the file generated in the previous exercise.\n");

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
            case 1: fp_exer1(); break;
            case 2: fp_exer2(); break;
            case 3: fp_exer3(); break;
            case 4: fp_exer4(); break;
        }
        system("pause");
    }
}