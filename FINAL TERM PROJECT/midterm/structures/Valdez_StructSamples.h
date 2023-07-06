// Marc Valdez

void struct_sample_1(void);
void struct_sample_2(void);
void struct_sample_3(void);
void struct_sample_4(void);

void struct_samples()
{
    char *menu_items[] = {
        "Display the value of the members of structure variable.",
        "Structure to structure assignment.",
        "Passing Structure as a function parameter.",
        "Structure Array"
    };
    int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);

    while(1)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("Midterm Activities | [0] Go back | [-1] Exit\n");
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
            case 1: struct_sample_1(); break;
            case 2: struct_sample_2(); break;
            case 3: struct_sample_3(); break;
            case 4: struct_sample_4(); break;
        }
        system("pause");
    }
}

/* Example 1 */
void struct_sample_1(void)
{
    printf("\nExample 1:\n");

    struct {
        int x;
        int y;
    } point;

    //assign value to the members of structure variable point
    point.x = 10;
    point.y = 5;

    //display the value of the members of structure variable point
    printf("\nx=%d,\ty=%d\n\n", point.x, point.y);
}
/* Example 1 */

/* Example 2 */
void struct_sample_2(void)
{
    printf("\nExample 2:\n");

    struct pointType {
        int x;
        int y;
    };

    struct pointType point1, point2;
    point1.x = 5;
    point1.y = 100;

    point2 = point1; //structure to structure assignment

    //display the value of the members of structure point2
    printf("\npoint2.x=%d,\tpoint2.y=%d\n\n", point2.x, point2.y);
}
/* Example 2 */

/* Example 3 */
struct pointType {
    int x;
    int y;
};
struct pointType point1;

void PrintPoint(struct pointType p);

void struct_sample_3(void)
{
    printf("\nExample 3:\n");

    point1.x = 100;
    point1.y = 200;

    PrintPoint(point1);
}

void PrintPoint(struct pointType p)
{
    printf("\nx=%d\n", p.x);
    printf("y=%d\n\n", p.y);
}
/* Example 3 */

/* Example 4 */
void struct_sample_4(void)
{
    printf("\nExample 4:\n");

    struct pointType {
        int x;
        int y;
        int z;
    };

    struct pointType PointArray[5] = {
        {100, 20, 80}, // {x, y, z}
        {200, 30, 1},
        {400, 50, 7},
        {600, 70, 6},
        {800, 90, 8}
    };


    for(int i = 0; i < 5; i++)
        printf("\nPointArray[%d].x=%d,\tPointArray[%d].y=%d,\tPointArray[%d].z=%d\n\n", i, PointArray[i].x, i, PointArray[i].y, i, PointArray[i].z);
}
/* Example 4 */