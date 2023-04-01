#include <stdio.h>
// Marc Valdez

const int row = 10, col = 10;

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
		for(int j = 0; j < col; j++)
			printf("\t%.2f", arr[i][j]);
		printf("\n");
	}
}

int count_negative(double arr[row][col])
{
	int count = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(arr[i][j] < 0.0)
				count++;
	return count;
}

void main()
{
	printf("\n4. Write a function that will return the number of negative elements in the 2D array.\nPass the array as parameter\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	print_arr(d_arr);
	printf("\nThe number of negative values are: %d", count_negative(d_arr));
	
	printf("\n");
}