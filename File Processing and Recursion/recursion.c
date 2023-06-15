#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Mystery(int x, int y)
{
	if (y == 0)
		return x;
	else
		return (Mystery(y, x % y));
}

void exercise1()
{
	printf("%d\n", Mystery(10, 25));
}

void BLIP(int n)
{
	if (n != 0)
	{
		printf("BLIP = %d\n", n);
		BLIP(n - 1);
	}
}

void BLAP(int n)
{
	if (n != 0)
	{
		BLIP(n);
		BLAP(n-1);
	}
}

void exercise2()
{
	BLAP(4);
}

void main()
{
    // this is just a simple selection menu for the exercise codes above
    while (1)
    {
        char *buffer = malloc(sizeof(char) * 256);
        int choice = 0;

        puts("----------------------------------------------\n");
        for (int i = 1, j = 6; i <= 5, j <= 10; i++, j++)
        {
            printf("\tExercise [%d]", i);
            printf("\tExercise [%d]\n", j);
        }

        printf("\nEnter an exercise number [1-10] >> ");
        fgets(buffer, strlen(buffer) + 1, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (sscanf(buffer, "%d", &choice) != 1)
        {
            printf("! Please input a number.\n");
            continue;
        }

        if (choice < 1 || choice > 10)
        {
            printf("! Input a number between 1 and 10.\n");
            continue;
        }

        switch (choice)
        {
            case 1: exercise1(); break;
            case 2: exercise2(); break;
            // case 3: exercise3(); break;
            // case 4: exercise4(); break;
            // case 5: exercise5(); break;
            // case 6: exercise6(); break;
            // case 7: exercise7(); break;
            // case 8: exercise8(); break;
            // case 9: exercise9(); break;
            // case 10: exercise10(); break;
        }

        puts("\nPress enter to continue...");
        // if (choice >= 2 && choice <= 6)
        //     getchar();
        getchar();
        system("cls");
    }
}