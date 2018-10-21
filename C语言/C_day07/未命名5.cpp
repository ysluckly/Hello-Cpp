#include<stdio.h>
#include<math.h>
int is_prime_su(int n)
{
	int j = 0;
	for(j = 2; j<=sqrt(n);j++)
	{
		if(n%j==0)
		{	return 0;
		}
	
	}
	return 1;
}
int main()
{
	int i = 0;
	for(i = 100;i<=200;i++)
	{
		if(is_prime_su(i))
	
	{
			printf("%5d",i);
		}
	 
	}
	return 0;
}
