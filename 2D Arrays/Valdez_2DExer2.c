#include <stdio.h>
// Marc Valdez

const int row = 2, col = 3;

void d_init(double arr[row][col]);

void main()
{
	printf("2. Same as the problem 1, but allow the user to input the value of the array element via scanf() statement.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
}

// Initializes a double 2D array that asks the user for inputs
void d_init(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			printf("Enter value of array element [%d][%d]: ", i, j);
			scanf(" %lf", &arr[i][j]);
		}
	printf("\n");
}