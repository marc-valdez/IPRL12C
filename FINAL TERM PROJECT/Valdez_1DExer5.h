#include <stdio.h>
// Marc Valdez

void d_init5(double arr[], int n);
int count(double arr[], int n);

void oneD_exer5()
{
	printf("5. Return the number of negative values\n\n");
	
	int n = *(int *)get_number(INTEGER, "Enter array size (0-4): ", 0.0, 4.0);
	
	double d_arr[n];
	d_init5(d_arr, n);
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
	
	int c = count(d_arr, n);
	printf("\n\nCount: %d\n\n", c);
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init5(double arr[], int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0-i;
}

// Returns the number of negative values in a double array
int count(double arr[], int n)
{
	int c;
	for(int i = 0; i < n; i++)
		if(arr[i] < 0)
			c++;	
	return c;
}