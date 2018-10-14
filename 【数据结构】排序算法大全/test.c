#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"



int main()
{

	int arr[] = { 2, 3, 8, 1, 23, 56, 848, 21, 15 };
	int len = sizeof(arr) / sizeof(arr[0]);

	/*InsertSort(arr,len);
	Print(arr, len);
	ShellSort(arr,len);
	Print(arr, len);*/
	/*
	SelectSort(arr,len);
	Print(arr, len);
	HeapSort(arr, len);
	Print(arr, len);*/

	BubbleSort(arr, len);
	Print(arr, len);

	QuickSort(arr, 0, len - 1);
	Print(arr, len);

	MergeSort(arr, len);
	Print(arr, len);

	//	CountSort(arr,len);
	//Print(arr, len);

	system("pause");
	return 0;
}

