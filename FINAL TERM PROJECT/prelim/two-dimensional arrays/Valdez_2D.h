#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Marc Valdez

// Edit these to change 2D array size (Max 10)
const int row = 3, col = 3;

void twoD_exer1(void);
void twoD_exer2(void);
void twoD_exer3(void);
void twoD_exer4(void);
void twoD_exer5(void);
void twoD_exer6(void);
void twoD_exer7(void);
void twoD_exer8(void);

void twoD_MEs()
{
	char *menu_items[] = {
		"Write a function that will initialize the contents of a double data type 2D array to 0.0.",
		"Same as problem 1, but allow the user to input the value of the array element via scanf() statement.",
		"Write a function that will display all the elements of the 2D array.",
		"Write a function that will return the number of negative elements in the 2D array.",
		"Write a function that will print only the elements on the main diagonal of the 2D array.",
		"Write a function that will return the sum of the elements on a specified row.",
		"Write a function that will return the sum of the elements on a specified column.",
		"Write a function that will add two matrices, A and B, and store the sum to C."
	};
	int menu_size = sizeof(menu_items) / sizeof(menu_items[0]);

	while(1)
	{
		system("cls");
		printf("=====================================================================\n");
		printf("Two Dimensional Array Activities: | [0] Go back | [-1] Exit\n");
		print_menu(menu_items, menu_size);

		int choice = get_int(-1, menu_size, "> Please select an option: ");

		system("cls");
		switch(choice)
		{
			case -1: {
				char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
				if(answer == 'N' || answer == 'n')
					continue;
				exit_prompt("Thank you for using this program!\n");
				break;
			}
			case 0: {
				char answer = yes_or_no("Return to previous menu? (y/n): ");
				if(answer == 'N' || answer == 'n')
					continue;
				return;
			}
			case 1: twoD_exer1(); break;
			case 2: twoD_exer2(); break;
			case 3: twoD_exer3(); break;
			case 4: twoD_exer4(); break;
			case 5: twoD_exer5(); break;
			case 6: twoD_exer6(); break;
			case 7: twoD_exer7(); break;
			case 8: twoD_exer8(); break;
		}
		system("pause");
	}
}

// Initializes a double 2D array that has element values of 0.0
void d_init_zero(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][j] = 0.0;
}

void twoD_exer1(void)
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
			arr[i][j] = get_double(0.0, 100.0, "Enter value of array element [%d][%d]: ", i, j);
	printf("\n");
}

void twoD_exer2(void)
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
void d_init_2D(double arr[row][col])
{
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			arr[i][j] = 0.0 + j - i;
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

void twoD_exer3(void)
{
	printf("\n3. Write a function that will display all the elements of the 2D array.\n\nElements should be printed starting from the first row up to the last row,\nand from the first column to the last column within the same row.\n\nElements of the same row should be printed on the same line separated by two spaces.\nPass the array as parameter.\n\n");

	double d_arr[row][col];

	d_init_2D(d_arr);
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

void twoD_exer4(void)
{
	printf("\n4. Write a function that will return the number of negative elements in the 2D array.\nPass the array as parameter\n\n");

	double d_arr[row][col];

	d_init_2D(d_arr);
	print_arr(d_arr);
	printf("\nThe number of negative values are: %d\n", count_negative(d_arr));

	printf("\n");
}

// Prints the numbers along the main diagonal
void print_diagonal(double arr[row][col])
{
	printf("\nMain Diagonal:\n");
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

void twoD_exer5()
{
	printf("\n5. Write a function that will print only the elements on the main diagonal of the 2D array.\nPass the array as parameter.\n\n");

	double d_arr[row][col];

	d_init_2D(d_arr);

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}

	print_diagonal(d_arr);
}

// Adds the numbers on a specified row
int sum_row(double arr[row][col], int buffer)
{
	--buffer;
	int sum = 0;
	for(int j = 0; j < col; j++)
		sum += arr[buffer][j];
	return sum;
}

void twoD_exer6()
{
	printf("\n6. Write a function that will return the sum of the elements on a specified row.\nPass the array and the row as parameters.\n\n");

	double d_arr[row][col];

	d_init_2D(d_arr);

	for(int i = 0; i < row; i++)
	{
		printf("Row %d:\t", i + 1);
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
	printf("\n");
	int input = get_int(1, row, "Please enter a row number: ");
	int sum = sum_row(d_arr, input);
	printf("\nThe sum of row %d is %d\n\n", input, sum);
}

// Adds the numbers on a specified column
int sum_column(double arr[row][col], int buffer)
{
	--buffer;
	int sum = 0;

	for(int i = 0; i < row; i++)
		sum += arr[i][buffer];
	return sum;
}

void twoD_exer7()
{
	printf("\n7. Write a function that will return the sum of the elements on a specified Column.\nPass the array and the column as parameters.\n\n");

	double d_arr[row][col];

	d_init_2D(d_arr);

	for(int j = 0; j < col; j++)
		printf("\tCol %d:", j + 1);
	printf("\n");
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			printf("\t%.2f", d_arr[i][j]);
		printf("\n");
	}

	printf("\n");
	int input = get_int(1, col, "Please enter a column number: ");
	int sum = sum_column(d_arr, input);
	printf("\nThe sum of column %d is %d\n\n", input, sum);
}

// Adds two arrays of the same size and stores it to another
void add_arrays(int A[3][3], int B[3][3], int C[3][3])
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			C[i][j] = A[i][j] + B[i][j];
}

void twoD_exer8(void)
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