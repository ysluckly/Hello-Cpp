#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> 
void play(int x)
{
	if (x != 0)
	{play(x / 10);
		printf("%5d", x % 10);
		
	}

	//printf("%d", x);  
}

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	scanf("%d", &k);
	play(k);
 
	return 0;

}
