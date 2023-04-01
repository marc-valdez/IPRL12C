// NOTE! No Error Correction!
// Code will infinitely loop if you enter a non-integer in the prompts that require only numbers!

#include <stdio.h>
#include <stdlib.h>
// Marc Valdez

// Edit these to change 2D array size (Max 10)
const int row = 10, col = 10;

void exercise_1(void);
void exercise_2(void);
void exercise_3(void);
void exercise_4(void);
void exercise_5(void);
void exercise_6(void);
void exercise_7(void);
void exercise_8(void);
void exit_prompt(void);

void main()
{
	int buffer = 0;
	printf("=======================================================================================================\n\n> Enter Activity Number [1-8] / Exit [9]: ");
	scanf(" %d", &buffer);
	
	switch(buffer)
	{
		case 1: exercise_1(); break;
		case 2: exercise_2(); break;
		case 3: exercise_3(); break;
		case 4: exercise_4(); break;
		case 5: exercise_5(); break;
		case 6: exercise_6(); break;
		case 7: exercise_7(); break;
		case 8: exercise_8(); break;
		case 9: exit_prompt(); break;
		default:
			printf("\nInvalid Input.\n\n");
			break;
	}
	main();
}

// Initializes a double 2D array that has element values of 0.0
void d_init_zero(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][j] = 0.0;
}

void exercise_1(void)
{
	printf("\n1. Write a function that will initialize the contents of a double data type 2D array to 0.0. \nPass the array as parameter.\n\n");
	
	double d_arr[row][col];
	
	d_init_zero(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("\t%.2f", d_arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

// Initializes a double 2D array that asks the user for inputs
void d_init_scan(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			printf("Enter value of array element [%d][%d]: ", i, j);
			scanf(" %lf", &arr[i][j]);
		}
	printf("\n");
}

void exercise_2(void)
{
	printf("\n2. Same as problem 1, but allow the user to input the value of the array element via scanf() statement.\n\n");
	
	double d_arr[row][col];
	
	d_init_scan(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("\t%.2f", d_arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

// Initializes a double 2D array
void d_init(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][j] = 0.0+j-i;
}

// Prints an array with double space
void print_arr(double arr[row][col])
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("%.2f  ", arr[i][j]);
		printf("\n");
	}
}

void exercise_3(void)
{
	printf("\n3. Write a function that will display all the elements of the 2D array.\n\nElements should be printed starting from the first row up to the last row,\nand from the first column to the last column within the same row.\n\nElements of the same row should be printed on the same line separated by two spaces.\nPass the array as parameter.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	print_arr(d_arr);
	
	printf("\n");
}

// Returns the amount of negative numbers inside an array
int count_negative(double arr[row][col])
{
	int count = 0;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			if(arr[i][j] < 0.0)
				count++;
	return count;
}

void exercise_4(void)
{
	printf("\n4. Write a function that will return the number of negative elements in the 2D array.\nPass the array as parameter\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	print_arr(d_arr);
	printf("\nThe number of negative values are: %d\n", count_negative(d_arr));
	
	printf("\n");
}

// Prints the numbers along the main diagonal
void print_diagonal(double arr[row][col])
{
	printf("\nMain Diagonal:\n\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(i == j)
				printf("%.2f\t", arr[i][j]);
			else
				printf("\t");
		}
		printf("\n");
	}
}

void exercise_5()
{
	printf("\n5. Write a function that will print only the elements on the main diagonal of the 2D array.\nPass the array as parameter.\n\n");
	
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

// Adds the numbers on a specified row
void sum_row(double arr[row][col], int buffer)
{
	--buffer;
	int sum = 0;
	for(int j = 0; j < col; j++)
		sum += arr[buffer][j];
	printf("\nThe sum of row %d is %d\n", ++buffer, sum);
}

void exercise_6()
{
	printf("\n6. Write a function that will return the sum of the elements on a specified row.\nPass the array and the row as parameters.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	
	for(int i = 0; i < row; i++)
	{
		printf("Row %d:\t", i+1);
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
	
	int buffer = 0;
	printf("\nPlease enter a row [1-%d]: ", row);
	scanf("%d", &buffer);
	
	sum_row(d_arr, buffer);
	printf("\n");
}

// Adds the numbers on a specified column
void sum_column(double arr[row][col], int buffer)
{
	--buffer;
	int sum = 0;
	
	for(int i = 0; i < row; i++)
		sum += arr[i][buffer];
	printf("\nThe sum of column %d is %d\n", ++buffer, sum);
}

void exercise_7()
{
	printf("\n7. Write a function that will return the sum of the elements on a specified row.\nPass the array and the column as parameters.\n\n");
	
	double d_arr[row][col];
	
	d_init(d_arr);
	
	for(int j = 0; j < col; j++)
		printf("\tCol %d:", j+1);
	printf("\n");	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)		
			printf("\t%.2f", d_arr[i][j]);
		printf("\n");
	}
	
	int buffer = 0;
	printf("\nPlease enter a [1-%d]: ", col);
	scanf("%d", &buffer);
		
	sum_column(d_arr, buffer);
	printf("\n");
}

// Adds two arrays of the same size and stores it to another
void add_arrays(int A[3][3], int B[3][3], int C[3][3])
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			C[i][j] = A[i][j] + B[i][j];
}

void exercise_8(void)
{
	printf("\n8. Assume three matrices of the same size, say matrix A, B and C.\n\nWrite a function that will add the two matrices A and B and store the sum to C.\nPass the three arrays as parameters.\n\n");
	
	int A[3][3] = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
	};
	
	int B[3][3] = {
		{4, 5, 6},
		{4, 5, 6},
		{4, 5, 6},
	};
	
	int C[3][3];
	
	add_arrays(A, B, C);
	
	printf("    A               B               C    ");
	printf("\n\n");
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			printf("[%d]", A[i][j]);
		if(i == 1)
			printf("   +   ");
		else
			printf("       ");
		for(int j = 0; j < 3; j++)
			printf("[%d]", B[i][j]);
		if(i == 1)
			printf("   =   ");
		else
			printf("       ");
		for(int j = 0; j < 3; j++)
			printf("[%d]", C[i][j]);
		printf("\n");
	}
		
	printf("\n");
}

// Prompts for exit
void exit_prompt(void)
{
	char in;
	printf("\nWould you like to exit? [Y-N]: ");
	scanf(" %c", &in);
	
	if(in == 'Y' || in == 'y')
		exit(0);
	printf("\n");
}