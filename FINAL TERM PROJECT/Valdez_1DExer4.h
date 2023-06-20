#include <stdio.h>
// Marc Valdez

void d_init4(double arr[], int n);
double summate(double arr[], int n);

void oneD_exer4()
{
	printf("4. Return the sum of all elements\n\n");

	int n;
	get_int(&n, 0, 4, "Enter array size (%d-%d): ", 0, 4);

	double d_arr[n];
	d_init4(d_arr, n);

	for(int i = 0; i < n; i++)
		printf("%.2lf\t", d_arr[i]);

	double sum = summate(d_arr, n);
	printf("\n\nSum: %.2lf\n\n", sum);
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init4(double arr[], int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0 - i;
}

// Returns the sum of all elements in a double array
double summate(double arr[], int n)
{
	double sum;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}