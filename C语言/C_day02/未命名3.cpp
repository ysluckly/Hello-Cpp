#include<stdio.h>
#define N 10
int main()
{
	int i = 0,j = 0,t = 0;
	int arr[N] = {1,6,6,8,2,9,1,77,66,3};
	for(i=0; i<N; i++)
	{
	    printf("%d\t",arr[i]);	
	}
	printf("\n"); 
	for(i=0; i<N-1; i++)
	{
		for(j=i+1; j<N; j++)
		{
			if(arr[i] > arr[j])
		    {   t = arr[i];
		        arr[i] = arr[j];
		        arr[j] = t;
			}
		}
	}	
         for(i=0; i<N; i++)
			 printf("%d\t",arr[i]);	
	return 0;
}
