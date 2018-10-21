#include <stdio.h>   
int Lenth(int arr[])
{
	return sizeof(arr) / sizeof(arr[0]);
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
	int ret = 0;
	ret = Lenth(arr);
	printf("%d\n", ret);
 
	return 0;
}
