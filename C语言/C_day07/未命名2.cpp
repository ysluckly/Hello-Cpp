#include<stdio.h>
void Swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int m = 0;
	int n = 0;
	scanf("%d%d",&m,&n);
	Swap(&m,&n);
	printf("%d%d",m,n);
	return 0;
}
