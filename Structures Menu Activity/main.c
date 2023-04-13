#include <stdio.h>
#include <stdlib.h>
#include "valdez.h"

// Marc Valdez

void example_1(void);
void example_2(void);
void example_3(void);
void exit_prompt(void);

void main()
{
	while(1)
	{
		printf("=======================================================================================================\n\n");
		
		//* I would prefer if you commented this out from here...
		for(int i = 1; i < 4; i++)
			printf("[%d] Example %d\t", i, i);
		printf("[4] Exit\n\n");
		// ...to here. */
		
		char *prompt = "> Enter Example Number [1-3] / Exit [4]: ";
		int buffer = get_int(prompt, "1234\n", 1, 4);
		
		switch(buffer)
		{
			case 1: example_1(); break;
			case 2: example_2(); break;
			case 3: example_3(); break;
			case 4: exit_prompt(); break;
			default:
				printf("\nInvalid Input.\n\n");
				break;
		}
	}
}

void example_1(void)
{
    printf("\nExample 1:\n");

    struct {
        int x;
        int y;
    } point;

    //assign value to the members of structure variable point
    point.x=10;
    point.y=5;

    //display the value of the members of structure variable point

    printf("\nx=%d\t,y=%d\n\n",point.x, point.y);
}

void example_2(void)
{
    printf("\nExample 2:\n");
    
    struct pointType{
        int x;
        int y;
    };

    struct pointType point1, point2;
    point1.x=5;
    point1.y=100;

    point2=point1; //structure to structure assignment

    //display the value of the members of structure point2
    printf("\npoint2.x=%d,\tpoint2.y=%d\n\n",point2.x, point2.y);
}

struct pointType{
    int x;
    int y;
};
struct pointType point1;

void PrintPoint(struct pointType p);

void example_3(void)
{
	printf("\nExample 3:\n");
    
    point1.x=100;
    point1.y=200;

    PrintPoint(point1);
}

void PrintPoint(struct pointType p)
{
    printf("\nx=%d\n",p.x);
    printf("y=%d\n\n",p.y);
}


// Prompts for exit
void exit_prompt(void)
{
	printf("\n");
	char in = get_char("Would you like to exit? [Y-N]: ", "YyNn\n");
	if(in == 'Y' || in == 'y')
		exit(0);
	printf("\n");
}