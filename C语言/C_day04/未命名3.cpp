#include<stdio.h>
int main()
{
	char ch;
	int count = 0; 
	while((ch=getchar()) != '\n')
	{
		if(ch == '{')
		count++;
		else if(ch == '}'&&count == 0)
		{
			printf(" ‰»Î≤ª∆•≈‰");
			return 0; 
		}
		else if(ch == '}')
		count--;
	}
	if(count == 0)
	{
		printf(" ‰»Î∆•≈‰"); 
	}
	else
	{
		printf("≤ª∆•≈‰");
	}
	return 0;
}
