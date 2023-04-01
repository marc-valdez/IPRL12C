#include <stdio.h>
// Marc Valdez

const int row = 5, col = 5;
void d_init(double arr[row][col]);
void sum_row(double arr[row][col], int buffer);

void main()
{
	printf("6. Write a function that will return the sum of the elements on a specified row.\n\tPass the array and the row as parameters.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
	
	int buffer = 0;
	printf("\nPlease enter a row [1-5]: ");
	scanf("%d", &buffer);
	
	sum_row(d_arr, buffer);
}

// Initializes a double 2D array
void d_init(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			if(i == j)
				arr[i][j] = -j-i;
			else
				arr[i][j] = 0.0+j+i;
		}	
}

// Prints the sum of an inputted row
void sum_row(double arr[row][col], int buffer)
{
	--buffer;
	
	int sum = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			if(i == buffer)
				sum += arr[i][j];
		}
	printf("The sum of row %d is %d", ++buffer, sum);
}