#define _CRT_SECURE_NO_WARNINGS 1  

#include <stdio.h>
#define FSWAP(N) (((N&0X55555555)<<1)|((N&0xaaaaaaaa)>>1))

int main()
{
	int n = 0;
	printf("请输入一个数字\n");  
	scanf("%d",&n);
    printf("%d",FSWAP(n));	
	return 0;
 } 
