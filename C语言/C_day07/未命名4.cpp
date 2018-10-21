#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void inint(int a[], int sz)                  //清零
{
	int i = 0;
	for (i = 0; i <sz; i++)
	{
		a[i] = i;
		printf("%d ", a[i]);
	}
	printf("\n");
}
void empty(int a[])                         //清空
{
	int i = 0;
	for (i = 0; i<10; i++)
	{
		a[i] = 0;
		printf("%d ", a[i]);
	}
	printf("\n");
}
void reverse(int a[],int as)      //逆置
{
	int i = 0;
	int left = 0;
	int right = as - 1;
    while(left<right)
	{
	 
			int tmp = a[left];
			a[left] = a[right];
			a[right] = tmp;
			left++;
			right--;
		
	 
	} 
	printf("\n");
}
void print(int a[], int as)
{
	int i = 0;
	for(i = 0;i<as ;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int a[10] = { 0 };
	int as = sizeof(a) / sizeof(a[0]);
	printf("初始化数组>\n");
	inint(a, as);
	printf("逆置数组>\n");
	reverse(a, as);
	printf("清空数组>\n");
	 print(a,as);
	empty(a);
 
	return 0;
}
