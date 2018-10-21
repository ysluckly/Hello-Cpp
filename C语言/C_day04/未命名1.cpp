 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int count = 0;

	int i = 0;
	int a= 0;
	int temp = 0;
	for (i = 0; i < 1000; i++)
	{	int sum = 0;
		count = 1;
		temp = i;
		while (temp / 10)
		{
			count++;
			temp /= 10;
		}
		temp = i;
		while (temp)
		{
			sum += pow(temp % 10, count);
			temp /= 10;
		}
		if (sum == i)
		{	a++;
		printf("%d ", i);
		}
	}
	printf("\n×ÜÊý%d",a);
	return 0;
}
