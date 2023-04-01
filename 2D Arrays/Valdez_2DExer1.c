#include <stdio.h>
// Marc Valdez

const int row = 10, col = 10;

void d_init(double arr[row][col]);

void main()
{
	printf("1. Write a function that will initialize the contents of a double data type 2D array to 0.0. \n\tPass the array as parameter.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
}

// Initializes a double 2D array that has element values of 0.0
void d_init(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][j] = 0.0+j-i;
}