#include<stdio.h>
int main()
{
	int a = 0,b = 0,c = 0,t = 0;
	scanf("%d%d%d",&a,&b,&c);
	printf("≈≈–Ú«∞£∫%d %d %d \n",a,b,c);
	if(a<b)
	{
		t = a;a = b;b = t;
	}
	if(a<c)
	{
		t = a;a = c;c = t;
	}
	if(b<c)
	{
		t = b;b = c;c = t;
	}
	printf("≈≈–Ú∫Û£∫%d %d %d",a,b,c);
	return 0;
	 
 } 
