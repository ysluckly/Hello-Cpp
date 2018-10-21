#include<stdio.h>
int main()
{
	int i = 0;
	int a = 0;
	int n = 0;
	int sum = 0;
	scanf("%d %d",&a,&n);
	int temp = a; 
	for(i=0; i<n; i++)
	{
		sum+=a;
		a=a*10+a; 
	 	
	}
	printf("%d",sum);
	
	return 0;
 } 
