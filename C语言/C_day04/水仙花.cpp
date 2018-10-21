#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0; 
	int a = 0, b = 0, c = 0;
	for (i = 100; i < 1000; i++)
	{
		a = i % 10;
		b = (i / 10) % 10;
		c = i / 100;
		if ((a+b*10+c*100 )== (a*a*a+b*b*b+c*c*c));
		{      printf("%d\n", i);
		}
	}
	return 0;
}
