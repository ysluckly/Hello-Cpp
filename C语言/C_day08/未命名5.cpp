#include <stdio.h>
#define N 10

int main()
{
	int arr[N][N] = {0};
	int i = 0;
	for(i = 0; i<N; i++)
	{
		int m = 0;
		for(m = 0;m<N-i;m++)
		{
			printf("  ");
		}
		int j = 0;
		for(j = 0; j<=i; j++)
		{
		if((0 == j)||(i == j))
		{
			arr[i][j] = 1;
			 
		}
		else
		{
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			 
		}
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
 } 
