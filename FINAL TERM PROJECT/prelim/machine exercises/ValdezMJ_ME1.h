// Online C compiler to run C program online
// Marc Valdez
// Machine Exercise 1 - March 23, 2023

int sum(int a, int b);
int product(int a, int b);
void printMessage();

void prelim_ME1() {
    printf("=====================================================================\n");
    printf("Machine Exercise 1 - March 23, 2023\n\n");
    int x = 100, y = 250;
    printf("The sum of %d and %d is %d\n", x, y, sum(x, y)); // 1st function call

    printf("%d\n", sum(35, 45)); // 2nd function call

    printf("The sum is %d\n", sum(x + 1, y)); // 3rd function call

    printf("The product is %d\n", product(10, 2));

    for(int i = 0; i < 5; i++)
        printMessage();

    printf("\n");
}

int sum(int a, int b)
{
    int total = 0; // local variable
    total = a + b;
    return total;
}

int product(int a, int b)
{
    return a * b;
}

void printMessage()
{
    printf("I love C Programming!!!\n");
}