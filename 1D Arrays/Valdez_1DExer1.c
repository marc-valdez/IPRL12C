#include <stdio.h>
// Marc Valdez

void d_init(double arr[], int n);

void main()
{
	printf("1. Initialize a double array for all elements to contain 0.0\n\n");
	
	int n = 3;
	double d_arr[n];
	
	d_init(d_arr, n);
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
}

// Initializes a double array that has element values of 0.0
void d_init(double arr[], int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0;
}