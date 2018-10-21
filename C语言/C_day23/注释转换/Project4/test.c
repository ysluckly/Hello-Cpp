#define _CRT_SECURE_NO_WARNINGS 1

#include "CommentConvert.h"

void test()
{
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;
	pfIn = fopen("input.c","r");
	if (NULL == pfIn)
	{
		perror("the file for read");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen("output.c", "w");
	if (NULL == pfOut)
	{
		perror("the file for write");
		fclose(pfIn);
		exit(EXIT_FAILURE);
	}
	//×¢ÊÍ×ª»»
	CommentConvert(pfIn,pfOut);
	fclose(pfIn);
	fclose(pfOut);

}

int main()
{
	test();
	system("pause");
	return 0;
}

