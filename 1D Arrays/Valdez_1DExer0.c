#include <stdio.h>
// Marc Valdez

void d_init(double *arr, int n);
void d_init2(double *arr, int n);
double lowest(double arr[], int n);
double summate(double arr[], int n);
int count(double arr[], int n);
int find(int arr[], int n, int x);
void arrcpy(int *A, int *B, int n);
void arrcpy_rev(int *A, int *B, int n);
int arrcomp(int A[], int B[], int n);

void main()
{
	// Problem 1
	printf("1. Initialize a double array for all elements to contain 0.0\n");
	
	int n = 3;
	double d_arr[n];
	
	d_init(d_arr, n);
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
	
	// Problem 2
	printf("\n\n");
	printf("2. Allow user to enter size\n");
	
	printf("Enter array size: ");
	scanf("%d", &n);
	
	d_arr[n];
	d_init2(d_arr, n);
	
	for(int i = 0; i < n; i++)
		printf("%.2f\t", d_arr[i]);
	
	// Problem 3
	printf("\n\n");
	printf("3. Return the lowest value\n");
	
	double min = lowest(d_arr, n);
	printf("Lowest: %.2f", min);
	
	// Problem 4
	printf("\n\n");
	printf("4. Return the sum of all elements\n");
	
	double sum = summate(d_arr, n);
	printf("Sum: %.2f", sum);
	
	// Problem 5
	printf("\n\n");
	printf("5. Return the number of negative values\n");
	
	int c = count(d_arr, n);
	printf("Count: %d", c);
	
	// Problem 6
	printf("\n\n");
	printf("6. See if an integer is found in an array\n");
	
	int i_arr[n];
	for(int i = 0; i < n; i++)
	{
		i_arr[i] = i;
		printf("%d\t", i_arr[i]);
	}

	int x = 0;
	printf("\nInput integer to find: ");
	scanf("%d", &x);
	
	if(find(i_arr, n, x) == 1)
		printf("\n== Integer %d Found inside array! ==", x);
	else
		printf("\n== Integer %d Not Found inside array! ==", x);
		
	// Problem 7
	printf("\n\n");
	printf("7. Copy contents of array A to B\n");
	
	n = 5;
	int A[] = {10, 20, 30, 40, 50};
	int B[n];
	
	printf("Array A: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	
	arrcpy(A, B, n);
	
	printf("\nArray B: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", B[i]);
	
	// Problem 8
	printf("\n\n");
	printf("8. Copy contents of A to B but in Reverse\n");
	
	printf("Array A: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	
	arrcpy_rev(A, B, n);
	
	printf("\nArray B: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", B[i]);
	
	// Problem 9
	printf("\n\n");
	printf("9. Check if both array A and B have the same values\n");
	
	if(arrcomp(A, B, n) == 1)
		printf("Arrays have the same values.\n");
	else
		printf("Arrays DON'T have the same values.\n");
}

// Initializes a double array that has element values of 0.0
void d_init(double *arr, int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0;
}

// Initializes a double array that has element values decreasing by 1.0 from 0.0
void d_init2(double *arr, int n)
{
	for(int i = 0; i < n; i++)
		arr[i] = 0.0-i;
}

// Returns the lowest value from a double array
double lowest(double arr[], int n)
{
	double min = arr[0];
	for(int i = 0; i < n; i++)
	{
		if(min > arr[i])
			min = arr[i];	
	}
	return min;
}

// Returns the sum of all elements in a double array
double summate(double arr[], int n)
{
	double sum;
	for(int i = 0; i < n; i++)
		sum+=arr[i];
	return sum;
}

// Returns the number of negative values in a double array
int count(double arr[], int n)
{
	int c;
	for(int i = 0; i < n; i++)
		if(arr[i] < 0)
			c++;	
	return c;
}

// Returns 1 if x is found in an integer array, returns 0 otherwise
int find(int arr[], int n, int x)
{
	int c = 0;
	for(int i = 0; i < n; i++)
		if(arr[i] == x)
			c++;
	return c > 0 ? 1 : 0;
}

// Copies the contents of array A to B
void arrcpy(int *A, int *B, int n)
{
	for(int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
}

// Copies the contents of array A to B, but in reverse
void arrcpy_rev(int *A, int *B, int n)
{
	for(int i = 0, j = n-1; i < n; i++, j--)
	{
		B[j] = A[i];
	}
}

// Compares the values of two arrays and returns 1 if they are the same, returns 0 otherwise
int arrcomp(int A[], int B[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(A[i] != B[i])
			return 0;
	}
	return 1;
}