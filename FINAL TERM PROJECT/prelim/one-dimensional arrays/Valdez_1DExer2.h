#include <stdio.h>
// Marc Valdez

void d_init2(double arr[], int n);

void oneD_exer2()
{
    printf("2. Allow user to enter size, and value of array\n\n");

    int n;
    get_int(&n, 0, 4, "Enter array size (%d-%d): ", 0, 4);

    printf("\n");

    double d_arr[n];
    d_init2(d_arr, n);

    printf("\n");

    for(int i = 0; i < n; i++)
        printf("%.2f\t", d_arr[i]);

    printf("\n\n");
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init2(double arr[], int n)
{
    for(int i = 0; i < n; i++)
        get_double(&arr[i], 0.0, 1000.0, "Enter value of array element %d: ", i);
}