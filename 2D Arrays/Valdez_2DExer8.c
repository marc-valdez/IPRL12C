#include <stdio.h>
// Marc Valdez

void add_arrays(int A[3][3], int B[3][3], int C[3][3])
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			C[i][j] = A[i][j] + B[i][j];
}

void main()
{
	printf("\n8. Assume three matrices of the same size, say matrix A, B and C.\n\nWrite a function that will add the two matrices A and B and store the sum to C.\n\nMatrix addition is done component-wise, i.e., C[i ,j] = A[i, j] + B[i, j]\nwhere i, j are the row and column index respectively.\n\nPass the three arrays as parameters.\n\n");
	
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