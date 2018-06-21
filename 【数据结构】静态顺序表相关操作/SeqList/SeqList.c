#define _CRT_SECURE_NO_WARNINGS 1
#include  "SeqList.h"

//初始化
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}

//打印静态顺序表
void PrintSeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->data[i]);
	}
}

//尾部插入
void PushBack(pSeqList pSeq, DataType d)
{	//断言
	assert(pSeq);
	//判满
	if (pSeq->size == MAX)
	{
		printf("为满无法插入\n");
		return;
	}
	//存储
	pSeq->data[pSeq->size] = d;
	pSeq->size++;

}

//尾部删除
void PopBack(pSeqList pSeq)
{
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("为空不能删\n");
		return;
	}
	pSeq->size--;
}

//头部插入
void PushFront(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == MAX)
	{
		printf("为满无法插入\n");
		return;
	}
	for (i = pSeq->size - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->size++;

}

//头部删除
void PoPFront(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("为空不能删\n");
		return;
	}
	for (i = 0; i < pSeq->size-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;

}

//查找
int Find(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}

//指定个数插入（第几个）
void Insert(pSeqList pSeq, size_t pos, DataType d)
{
	int i = 0;
	assert(pSeq);
	assert(pos >= 0&& pos <= pSeq->size);
	if (pSeq->size == MAX)
	{
		printf("为满无法插入\n");
		return;
	}
	 
	//i>pos 按坐标插入
	//i>=pos 按个数插入
	for (i = pSeq->size - 1; i >= pos; i--) 
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[i + 1] = pSeq->data[i];
	pSeq->data[i] = d;
	pSeq->size++;
}

//指定下标删除
void Erase(pSeqList pSeq, size_t pos)
{
	int i = 0;
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);
	if (pSeq->size == 0)
	{
		printf("为空不能删\n");
		return;
	}
	for (i = pos; i < pSeq->size; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;

}
//删除指定元素
void ReMove(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("为空不能删\n");
		return;
	}
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			break;
		}
	}
	if (i == pSeq->size)
	{
		printf("删除元素不存在");
		return;
	}
	for (; i < pSeq->size; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->size--;
}
//删除所有指定元素
void ReMoveAll(pSeqList pSeq, DataType d)
{
	int i = 0;
	int count = 0;
	//DataType* tmp = (DataType*)malloc(sizeof(DataType)*pSeq->size);
	assert(pSeq);
	if (pSeq->size == 0)
	{
		printf("为空不能删\n");
		return;
	}

#if 0
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] == d)
		{
			int j = 0;
			for (j = i; j < pSeq->size; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->size--;
			i--;
		}
	}
#endif

#if	0
	
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] != d)
		{
			tmp[count++] = pSeq->data[i];
		}
	}
	memcpy(pSeq->data, tmp, count*sizeof(DataType));
	pSeq->size = count;
	free(tmp);
	tmp = NULL;

#endif

#if 1
	for (i = 0; i < pSeq->size; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[count++] = pSeq->data[i];
		}
	}
	pSeq->size = count;
#endif

}
//返回顺序表大小
int Size(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->size;

}
//判断顺序表是否为空
int Empty(pSeqList pSeq)
{
	assert(pSeq);
	return pSeq->size = 0;

}
//交换函数
static void Swap(DataType* a, DataType* b)
{
	DataType* tmp = NULL;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//冒泡排序
void BubbleSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	int flag = 0;
	for (i = 0; i < pSeq->size - 1; i++)
	{
		for (j = 0; j < pSeq->size - i - 1; j++)
		{
			if (pSeq->data[j]>pSeq->data[j + 1])
			{
				//Swap(&pSeq->data[j], &pSeq->data[j + 1]);
				Swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}

}
//选择排序：找最大移到合适位置
#if 0
void SelectSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq);
	for (i = 0; i < pSeq->size - 1; i++)
	{
		int max = 0;   //默认最大下标
		for (j = 1; j < pSeq->size-i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}
		if (max != pSeq->size - 1 - i)
		{
			Swap(pSeq->data + max, pSeq->data + pSeq->size - 1 - i);
		}
	}

}
#endif
//选择排序优化：边找最大边找最小
#if 1
void SelectSort(pSeqList pSeq)
{
	
	int start = 0;
	int end = pSeq->size - 1;
	assert(pSeq);

	while (start < end)
	{
		int max = start;
		int min = start;
		int i = 0;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[i] > pSeq->data[max])
			{
				max = i;
			}
			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}
		if (max != end)
		{
			Swap(pSeq->data + max, pSeq->data + end);
		}
		if (max == start)
		{
			max = min;
		}
		if (min != start)
		{
			Swap(pSeq->data + min, pSeq->data + start);
		}
			
		start++;
		end--;
		
	}

}
#endif

//二分排序非递归
#if 0
int BinarySearch(pSeqList pSeq, DataType d)
{
	int left = 0;
	int right = pSeq->size - 1;
	while (left <= right)
	{
		//...
		int mid = left + ((right - left)>>1);
		if (pSeq->data[mid] == d)
		{
			return mid;
		}
		else if (d < pSeq->data[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		 
	}
	return -1;
}
#endif

//二分递归
#if 0
int BinarySearch(pSeqList pSeq, int left, int right, DataType d)
{
	int mid = 0;
	if (left > right)
		return -1;
	mid = left + ((right - left) >> 1);
	if (pSeq->data[mid] == d)
	{
		return mid;
	}
	else if (pSeq->data[mid] > d)
		return BinarySearch(pSeq, left, mid - 1, d);
	else
		return BinarySearch(pSeq, mid + 1, right, d);

}
#endif
 


 