#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h> 
int main()
{
	int i = 0;
	int a = 0;
	scanf("%d", &a);
	for (i = 31; i >=0; i-=2)
	{
		printf("%4d", ((a >> i) & 1));
	}
	printf("\n");
 
	for (i = 30; i >= 0; i-=2)
	{
		printf("%4d", ((a >> i) & 1));

	}
	printf("\n");
	return 0;
}
