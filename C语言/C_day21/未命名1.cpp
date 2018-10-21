/*#include <stdio.h>

int add(int x, int y)
{
        return x+y;
}

int sub(int x, int y)
{
        return x-y;

}
int mul(int x, int y)
{
        return x*y;

}
 
int div(int x,int y)
{
        return x/y;
}

int main()
{
        int input = 1;
        int x =0,y = 0;
        int ret = 0;
        int (*fen[5])(int,int) = {0,add,sub,mul,div};
        while(input)
        {
        printf("******************************\n");
        printf("**1.add      2.sub             *");
        printf("**3.mul      4.div              ");
        printf("******************************\n");
        scanf("%d",&input);
        if(input <=4 && input >= 0)
        {
        printf("请输入操作数");
        scanf("%d%d",&x,&y);
        ret = fen[input](x,y);
        printf("%d\n",ret);
        }
        else
        {
        printf("输入有误");
        }
        }
        return 0;
}
*/       
	   
#include<stdio.h>

void Swap(void *p1, void *p2,int size)
{
	int i =0;
	for(i = 0;i<=size;i++)
	{
		char rmp = *((char *)p1 +i);
		*((char*)p1 +i) = *((char *)p2 +i);
		*((char *)p2 +i) = rmp;
	}
}

int int_cmp(const void*p1,const void*p2)
{
	return (*(int *)p1 > *(int *)p2);
}



void  bubble(void *base,int count ,int size,int (*cmp)(void *,void *))
{
	
	int i =0;
	int j = 0;
	 
	for(i = 0;i<count-1;i++)
	{
		for(j =0;j<count-i-1;j++)
		{
			if(cmp((char *)base + j*size,(char *)base + (j+1)*size)>0)
			{
				Swap((char *)base + j*size ,(char *)base+(j+1)*size, size); 
			}
			
		}
	}
 } 
int main()
	
   {
   		//char *arr[] = {"aaaa","daaad","affaf","qwfq"};
		int arr[] = {1,3,4,5,6,4,2,5,33,5};
		int i =0;
		bubble(arr,sizeof(arr)/sizeof(arr[0]),sizeof(int),int_cmp);
		for(int i =0;i<sizeof(arr)/sizeof(arr[0]);i++)
		{
			printf("%d",arr[i]);
		}
		printf("\n");
		return 0;
	 } 
