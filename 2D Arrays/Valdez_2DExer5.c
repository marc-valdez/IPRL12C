#include <stdio.h>
// Marc Valdez

const int row = 10, col = 10;

void d_init(double arr[row][col]);
void print_diagonal(double arr[row][col]);

void main()
{
	printf("5. Write a function that will print only the elements on the main diagonal of the 2D array. Pass the array as parameter.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
	
	print_diagonal(d_arr);
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

// Prints the numbers along the diagonal
void print_diagonal(double arr[row][col])
{
	printf("\nMain Diagonal:\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			if(i == j)
				printf("%.2f\t", arr[i][j]);
			else
				printf("\t");
		printf("\n");
	}
}