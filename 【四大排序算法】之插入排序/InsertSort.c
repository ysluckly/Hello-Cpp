
#include "InsertSort.h"




void Print(int* arr, int n)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

//插入排序
void InsertSort(int* arr, int n)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < n - 1; ++i)
	{
		int end = i;
		int temp = arr[end + 1];
		while (end >= 0 && temp < arr[end])
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end] = temp;

	}

	
}
//插入排序升华-希尔排序
void ShellSort(int* arr, int n)
{
	//1.预排序（接近有序）gap越小越有序，但是比较次数越多越接近插入排序
	//2.插入排序
	assert(arr);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int i = 0;
		for (i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0 && tmp < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = tmp;
		}
	}

}
