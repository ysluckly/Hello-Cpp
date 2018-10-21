#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0 ;
	int n = 0;
	scanf("%d",&n);
	for(i = 2;i <= n;i++)
	{
		int j = 0;
		for(j = 2;j<=sqrt(i);j++)
		{
			if(0 == i%j)
			{
				break; 
			}
		}
		if(j > sqrt(i))
		{
			printf("%d ",i);
		}
	}
	return 0;
 } 
