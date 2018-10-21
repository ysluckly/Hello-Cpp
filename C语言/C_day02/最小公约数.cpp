#include<stdio.h>
int main()
{
	int max;
	int a = 3;
	int b = 8;
	max = a*b;
	while(a%b)
	{
		int temp = a%b;
		a = b;
		b = temp;
		 
	} 
	printf("%d，%d",b,max/b);//公约数，公倍数 
	return 0;
 } 
