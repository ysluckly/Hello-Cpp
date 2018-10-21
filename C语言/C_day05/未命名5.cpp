#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h> 
int main()
{
	char ch = 0;
	while ((ch = getchar()) != EOF);
	{
		if (ch > 'a'&&ch < 'z')
 
			printf("%c\n",tolower(ch));
		if (ch > 'A'&&ch < 'Z')
			printf("%c\n", toupper(ch));
	}
	system("pause");
	return 0;
}
