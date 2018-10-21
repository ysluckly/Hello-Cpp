#include<stdio.h>
int main()
{
	int i = 0;
	int cut = 0;
	for(i=1; i<=100; i++)
	{
		if(i%10 == 9) 
		cut++;
		if(i/10 == 9)
		cut++;
	}
	printf("%d",cut);
	return 0;
 } 
