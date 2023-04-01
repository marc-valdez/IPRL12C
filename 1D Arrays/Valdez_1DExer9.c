#include <stdio.h>
// Marc Valdez

void arrcpy(int A[], int B[], int n);
void arrcpy_rev(int A[], int B[], int n);
int arrcomp(int A[], int B[], int n);

void main()
{
	printf("9. Check if both array A and B have the same values\n\n");
	
	int n = 5;
	int A[] = {10, 20, 30, 40, 50};
	int B[n];
	
	printf("Array A: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);
	
//	arrcpy(A, B, n);
	arrcpy_rev(A, B, n);
	
	printf("\nArray B: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", B[i]);
		
	if(arrcomp(A, B, n) == 1)
		printf("\n\nArrays have the same values.\n");
	else
		printf("\n\nArrays DON'T have the same values.\n");
}

// Copies the contents of array A to B
void arrcpy(int A[], int B[], int n)
{
	for(int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
}

// Copies the contents of array A to B, but in reverse
void arrcpy_rev(int A[], int B[], int n)
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