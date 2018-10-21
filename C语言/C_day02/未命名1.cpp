#include<stdio.h>
int main()
{
	int i = 25;
	int j = 2;
	printf("交换前i,j的值：%d,%d\n",i,j);
	int temp = 0;
	temp = i;
	i = j;
	j = temp;
	printf("交换后i,j的值：%d,%d\nn",i,j);
	return 0;
	
 } 
