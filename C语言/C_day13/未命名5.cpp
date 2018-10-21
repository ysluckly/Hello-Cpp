#include <stdio.h>

int main()
{
	int arr[] ={1,3,4,4,5,67,8,8,3,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int left = 0;
	int i = 0;
	int right = size-1;
	int temp = 0;
	while(left<right)
{
		while(arr[left]%2==1)
	{
		left++;
	}
	while(arr[right]%2==0)
	{
		right--;
	}
	if(left<right){
		temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
		
	}
	
}
for(i= 0;i<size;i++)
{
	printf("  %d",arr[i]);
}
	return 0;
}
