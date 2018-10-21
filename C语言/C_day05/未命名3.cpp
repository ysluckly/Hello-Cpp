#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h> 
int main()
{
	char password[20] = "";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("ÇëÊäÈëÃÜÂë");
		scanf("%s",password);
		if (0 == (strcmp("123456", password)))
		{
			break;
		}
		 
	}
	if (3 == i)
	{
		printf("ÊäÈëÃÜÂë³¬Ê±");
	}
	else
		printf("login");
	system("pause");
	return 0;
}
