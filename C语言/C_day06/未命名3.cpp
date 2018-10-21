#include<stdio.h> 
int count_one_bits(int x)
{
	// 返回 1的位数 
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (((x >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	int a = 0;
	scanf("%d%d",&m,&n);
    a = count_one_bits(m^n);
    printf("%d",a);
    return 0;
    
    
}


