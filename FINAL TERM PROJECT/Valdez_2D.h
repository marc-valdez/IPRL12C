#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Marc Valdez

char get_char(char *prompt, char *limit);
int get_int(char *prompt, char *limit, int min, int max);
float get_float(char *prompt, char *limit, float min, float max);
double get_double(char *prompt, char *limit, double min, double max);

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
void exit_prompt_2D(void);

void twoD()
{
	while(1)
	{
		printf("=======================================================================================================\n\n");
		
		// I would prefer if you commented this out from here...
		for(int i = 1, j = 5; i <= 8/2; i++, j++)
			printf("  [%d] Exercise %d\t\t[%d] Exercise %d\n", i, i, j, j);
		printf("\n  [9] Go back\t\t\t[10] Exit\n\n");
		// ...to here.
		
		char *prompt = "> Enter Exercise Number [1-8] / Go back [9] / Exit [10]: ";
		int buffer = get_int(prompt, "0123456789\n", 1, 10);
		system("cls");

		switch(buffer)
		{
			case 1: twoD_exer1(); break;
			case 2: twoD_exer2(); break;
			case 3: twoD_exer3(); break;
			case 4: twoD_exer4(); break;
			case 5: twoD_exer5(); break;
			case 6: twoD_exer6(); break;
			case 7: twoD_exer7(); break;
			case 8: twoD_exer8(); break;
			case 9: {
                char answer = yes_or_no("Go back? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                return;
            }
            case 10: {
                char answer = yes_or_no("Are you sure you want to exit? (y/n): ");
                system("cls");
                if (answer == 'N' || answer == 'n')
                    break;
                exit_prompt("Thank you for using this program!\n");
            }
			default:
				printf("\nInvalid Input.\n\n");
				break;
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
		{
			char prompt[50];
            sprintf(prompt, "Enter value of array element [%d][%d]: ", i, j);
			arr[i][j] = get_double(prompt, "0123456789.\n", 0.0, 100.0);
		}
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
		printf("Row %d:\t", i+1);
		for(int j = 0; j < col; j++)
			printf("%.2f\t", d_arr[i][j]);
		printf("\n");
	}
	printf("\n");
	int input = get_int("Please enter a row number: ", "1234567890\n", 1, row);
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
	printf("\n7. Write a function that will return the sum of the elements on a specified row.\nPass the array and the column as parameters.\n\n");
	
	double d_arr[row][col];
	
	d_init_2D(d_arr);
	
	for(int j = 0; j < col; j++)
		printf("\tCol %d:", j+1);
	printf("\n");	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)		
			printf("\t%.2f", d_arr[i][j]);
		printf("\n");
	}
	
	printf("\n");
	int input = get_int("Please enter a column number: ", "1234567890\n", 1, col);
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

// Prompts for exit
void exit_prompt_2D(void)
{
	printf("\n");
	char in = get_char("Would you like to exit? [Y-N]: ", "YyNn\n");
	if(in == 'Y' || in == 'y')
		exit(0);
	printf("\n");
}

// from valdez.h
char get_char(char *prompt, char *limit)
{
	char buffer[MAX];
	
	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
        if(strlen(buffer) > 2)
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Character limit is: %d\n\n", 1);
            continue;
        }
        
        if(strlen(buffer) < 2)
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a character.\n\n");
            continue;
        }
        
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts: %s\n", limit);
            continue;
        }
		
        return buffer[0];
	}
}

int get_int(char *prompt, char *limit, int min, int max)
{
	char buffer[MAX];
	int user_input;
	
	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts %s\n", limit);
            continue;
        }
        
        if(sscanf(buffer, "%d", &user_input) != 1)
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number.\n\n");
            continue;
        }
        
        if(user_input < min || user_input > max) 
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number between %d and %d.\n\n", min, max);
            continue;
        }
		
        return user_input;
	}
}

float get_float(char *prompt, char *limit, float min, float max)
{
	char buffer[MAX];
	float user_input;
	
	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts %s\n", limit);
            continue;
        }
        
        if(sscanf(buffer, "%f", &user_input) != 1)
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number.\n\n");
            continue;
        }
        
        if(user_input < min || user_input > max) 
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number between %.2f and %.2f.\n\n", min, max);
            continue;
        }
		
        return user_input;
	}
}

double get_double(char *prompt, char *limit, double min, double max)
{
	char buffer[MAX];
	double user_input;
	
	while(1)
	{
        printf("%s", prompt);
		fgets(buffer, sizeof(buffer), stdin);
		
		if(strspn(buffer, limit) != strlen(buffer))
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Prompt only accepts %s\n", limit);
            continue;
        }
        
        if(sscanf(buffer, "%lf", &user_input) != 1)
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number.\n\n");
            continue;
        }
        
        if(user_input < min || user_input > max) 
        {
            strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number between %.2f and %.2f.\n\n", min, max);
            continue;
        }
		
        return user_input;
	}
}