#include <stdio.h>
// Marc Valdez

int find(int arr[], int n, int x);

void main()
{
	printf("6. See if an integer is found in an array\n\n");
	
	int n = 0;
	printf("Enter array size: ");
	scanf("%d", &n);
	
	int i_arr[n];
	for(int i = 0; i < n; i++)
	{
		i_arr[i] = i;
		printf("%d\t", i_arr[i]);
	}

	int x = 0;
	printf("\n\nInput integer to find: ");
	scanf("%d", &x);
	
	if(find(i_arr, n, x) == 1)
		printf("\n== Integer %d Found inside array! ==", x);
	else
		printf("\n== Integer %d Not Found inside array! ==", x);
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