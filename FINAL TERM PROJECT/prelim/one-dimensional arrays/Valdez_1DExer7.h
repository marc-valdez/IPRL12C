// Marc Valdez

void arrcpy(int A[], int B[], int n);

void oneD_exer7()
{
	printf("7. Copy contents of array A to B\n\n");

	int n = 5;
	int A[] = {10, 20, 30, 40, 50};
	int B[n];

	printf("Array A: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", A[i]);

	arrcpy(A, B, n);

	printf("\nArray B: ");
	for(int i = 0; i < n; i++)
		printf("%d\t", B[i]);

	printf("\n\n");
}

// Copies the contents of array A to B
void arrcpy(int A[], int B[], int n)
{
	for(int i = 0; i < n; i++)
	{
		B[i] = A[i];
	}
}