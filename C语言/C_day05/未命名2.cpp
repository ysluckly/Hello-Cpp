#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int key = 5;
	int size = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = ((right - left) >> 1) + left;
	if (arr[mid] == key)
	{
		printf("找到了\n");
		return mid;
	}
	else if (arr[mid] > key)
	{
		right = mid - 1;
	}
	else
		left = mid + 1;
	}
	printf("幸好不到");
	return -1;
}
