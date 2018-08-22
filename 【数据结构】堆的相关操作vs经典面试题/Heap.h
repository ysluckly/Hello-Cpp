#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//////////////////////////////////////////堆相关操作【动态顺序表结构】////////////////////////////////////////

typedef int HDataType;
typedef struct HeapNode
{
	HDataType* data;
	int size;
	int capacity;

}Heap;

//创建堆
void HeapInit(Heap* hp, HDataType* arr, int size);
//销毁
void HeapDestory(Heap* hp);

//插入数据
void HeapPush(Heap* hp, HDataType x);
//删除数据
void HeapPop(Heap* hp);
//堆顶元素
HDataType HeapTop(Heap* hp);
//判空
int HeapEmpty(Heap* hp);
//堆的大小
int HeapSize(Heap* hp);

//打印
void HeapPrint(Heap* hp);
//测试
void testHeap();


//////////////////////////////////////////堆经典面试题////////////////////////////////////////

#endif //__HEAP_H__