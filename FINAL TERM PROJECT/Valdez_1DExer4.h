#include <stdio.h>
// Marc Valdez

void d_init4(double arr[], int n);
double summate(double arr[], int n);

void oneD_exer4()
{
	printf("4. Return the sum of all elements\n\n");
	
	int n = *(int *)get_number(INTEGER, "Enter array size (0-4): ", 0.0, 4.0);
	
	double d_arr[n];
	d_init4(d_arr, n);
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
	
	double sum = summate(d_arr, n);
	printf("\n\nSum: %.2f\n\n", sum);
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init4(double arr[], int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0-i;
}

// Returns the sum of all elements in a double array
double summate(double arr[], int n)
{
	double sum;
	for(int i = 0; i < n; i++)
		sum+=arr[i];
	return sum;
}