#include <stdio.h>
// Marc Valdez

const int row = 3, col = 3;
void d_init(double arr[row][col]);

void main()
{
	printf("3. Write a function that will display all the elements of the 2D array.\n\nElements should be printed starting from the first row up to the last row,\nand from the first column to the last column within the same row.\n\nElements of the same row should be printed on the same line separated by two spaces.\nPass the array as parameter.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	print_arr(d_arr);
	
	printf("\n");
}

// Initializes a double 2D array that has element values of 0.0
void d_init(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][j] = 0.0+j-i;
}

void print_arr(double arr[row][col])
{
	for(int i = 0; i < row; i++)
	{
		printf("Row %d:\t", i+1);
		for(int j = 0; j < col; j++)
			printf("%.2f  ", arr[i][j]);
		printf("\n");
	}
}