#include <stdio.h>

int main()
{
	
	int i = 0;
	int ret = 0;
	int arr[]={1,2,3,4,5,4,3,2,1};
	int size =  sizeof(arr)/sizeof(arr[0]);
	for(i= 0;i<size;i++)
	{
      ret^=arr[i];
	  	}

	printf("%d",ret);
	return 0;
}
