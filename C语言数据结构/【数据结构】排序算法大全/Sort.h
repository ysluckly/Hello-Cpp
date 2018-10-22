#ifndef __INSERTSORT_H__
#define __INSERTSORT_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/************************************   ±»Ωœ≈≈–Ú     ********************************/
//≤Â»Î≈≈–Ú
//1.÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int* arr, int n);
//2.œ£∂˚≈≈–Ú
void ShellSort(int* arr, int n);


//—°‘Ò≈≈–Ú
//1.—°‘Ò≈≈–Ú
void SelectSort(int* arr, int n);
//2.∂—≈≈–Ú
void HeapSort(int* arr, int n);


//Ωªªª≈≈–Ú
//1.√∞≈›≈≈–Ú
void BubbleSort(int* arr, int n);
//2.øÏÀŸ≈≈–Ú
void QuickSort(int* arr, int begin, int end);

//πÈ≤¢≈≈–Ú£®ø…Õ‚≤ø≈≈–Ú£©
void MergeSort(int* arr, int n);

/************************************   ∑«±»Ωœ≈≈–Ú     ********************************/
//º∆ ˝≈≈–Ú
void CountSort(int* arr, int n);


#endif //__INSERTSORT_H__