#include <stdio.h>
// Marc Valdez

void d_init2(double arr[], int n);

void oneD_exer2()
{
	printf("2. Allow user to enter size, and value of array\n\n");
	
	int n = *(int *)get_number(INTEGER, "Enter array size (0-4): ", 0.0, 4.0);
	 
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
		arr[i] = *(double *)get_number(DOUBLE, "Enter value of array element %d: ", 0.0, 1000.0, i);
}