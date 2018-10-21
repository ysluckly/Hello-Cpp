#include <stdio.h>
#include <assert.h>
#include <string.h>


void left_move(char *str, int k)
{   assert(str);
	char temp = 0;
	int len = strlen(str);
	while(k--)
	{
		char *cur = str;
		temp = *cur;
		while(*(cur+1) != '\0')
		{
			*str = *(str+1);
			cur++;
		}
		*cur = temp;
	}
}

int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf("%d",&k);
	left_move(arr,k);
	printf("%s",arr);
	return 0;
 } 
