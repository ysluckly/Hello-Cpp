#include<stdio.h> 
int main()
{
	int i = 0;
	int line = 0;
	printf("ÇëÊäÈëĞĞÊı");
	scanf("%d",&line);
	printf("\n");
	for(i=0; i<line; i++)
	{
		int j = 0;
		for(j=0; j<line-1-i; j++)
		{
			printf(" ");
		}
		for(j=0; j<2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");	
	}
	for(i=0; i<line-1; i++)
	{
		int k = 0;
		for(k=0; k<i+1; k++)
		{
			printf(" ");
		}
		for(k=0; k<2*(line-1-i)-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
