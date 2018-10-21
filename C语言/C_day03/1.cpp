#include<stdio.h>
int main()
{
	int arr1[] = {1,2,9,7,4};
	int arr2[] = {5,4,5,6,3};
	//长度相同
	int length = sizeof(arr1)/sizeof(arr1[0]);
	int i = 0 ,temp = 0;
	for(i=0; i<length; i++)
	{
			temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp;
	} 
	for(i=0; i<length; i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\n");
	for(i=0; i<length; i++)
	{
		printf("%d\t",arr2[i]);
	}
	return 0;
}
