#include <stdio.h>
// Marc Valdez

void d_init(double arr[], int n);

void main()
{
	printf("2. Allow user to enter size, and value of array\n\n");
	
	int n = 0;
	printf("Enter array size: ");
	scanf("%d", &n);
	
	printf("\n");
	
	double d_arr[n];
	d_init(d_arr, n);
	
	printf("\n");
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init(double arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Enter value of array element %d: ", i);
		scanf("%lf", &arr[i]);
	}
}