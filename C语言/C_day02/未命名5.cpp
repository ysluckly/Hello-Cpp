#include<stdio.h>
int main()
{
	int m = 0,n = 0,k = 0;
	scanf("%d%d",&m,&n);
	int ji = m * n; 
	//最大公约数与最小公倍数 
    k = m>n? n: m;
	for(;m%k||n%k;)
    {
		k--;
	} 
	printf("最大公约数%d，最小公倍数%d ",k,ji/k);
	return 0;  
}
