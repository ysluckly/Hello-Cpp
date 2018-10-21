#include<stdio.h>
int main()
{
	int a = 6;
	int b = 56;
	printf("交换前a,b的值：%d,%d\n",a,b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("交换后a,b的值：%d,%d",a,b);
	return 0;
}
