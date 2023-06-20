#include <stdio.h>
// Marc Valdez

void arrcpy_rev(int A[], int B[], int n);

void oneD_exer8()
{
	printf("8. Copy contents of array A to B in reverse\n\n");

	int n = 5;
	int A[] = {10, 20, 30, 40, 50};
	int B[n];

	printf("Array A: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);

	arrcpy_rev(A, B, n);

	printf("\nArray B: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", B[i]);

	printf("\n\n");
}

// Copies the contents of array A to B, but in reverse
void arrcpy_rev(int A[], int B[], int n)
{
	for(int i = 0, j = n - 1; i < n; i++, j--)
	{
		B[j] = A[i];
	}
}