#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
void meau()
{
	printf("****************************************\n");
	printf("**********     1.play         **********\n");
	printf("**********     0.exit         **********\n");
	printf("****************************************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int put = 0;
	while (1)
	{
		printf("请输入一个数\n");
		scanf("%d",&put);
		if (put > ret)
		{
			printf("输入大了\n");
		}
		else if (put < ret)
		{
			printf("输入小了\n");
		}
		else
		{
			printf("恭喜你，可以买彩票了\n");
			break;
		}
		 
	}
	

}
int main()
{

	int input = 0;
	srand((unsigned)time(NULL));
	do{
		meau();
		printf("请输入-》");
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:game();
			break;
		case 0:
			break;
		default:
			printf("输入有误");
			break;
		}
	} while (input);
	 
	return 0;
}

