#include <stdio.h>
// Marc Valdez

void d_init(double arr[], int n);
double lowest(double arr[], int n);

void main()
{
	printf("3. Return the lowest value\n\n");
	int n = 0;
	printf("Enter array size: ");
	scanf("%d", &n);
	
	double d_arr[n];
	d_init(d_arr, n);
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
	
	double min = lowest(d_arr, n);
	printf("\n\nLowest: %.2f", min);
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init(double arr[], int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0-i;
}

// Returns the lowest value from a double array
double lowest(double arr[], int n)
{
	double min = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(min > arr[i])
			min = arr[i];	
	}
	return min;
}