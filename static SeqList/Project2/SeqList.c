#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

int main()
{
	test1();
	system("pause");
	return 0;
}
void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void SeqListInit(SeqList* pSeq)
{
	memset(pSeq->_arr, 0, sizeof(typedata)*N);
	pSeq->_size = 0;
}
void SeqListPrint(SeqList* pSeq)
{
	size_t i = 0;
	for (; i < pSeq->_size; i++)
	{
		printf("%3d", pSeq->_arr[i]);
	}
	printf("\n");
}

void SeqListPushFront(SeqList* pSeq, typedata x)
{
	assert(pSeq);//∑¿”˘ Ω±‡≥Ã£¨∑¿÷π¥´»Îø’÷∏’Î÷¬ π≥Ã–Ú±¿¿£ ,”¶…∆”√∂œ—‘
	if ( pSeq->_size >= N)
	{
		printf("The SeqList is full\n");
	}
	else
	{
		int end = pSeq->_size - 1;
		while (end >= 0)
		{		 
			pSeq->_arr[end + 1] = pSeq->_arr[end];
		    end--;
		}	
		pSeq->_arr[0] = x;
		pSeq->_size++;	
	}

}
void SeqListPushBack(SeqList* pSeq, typedata x)
{
	assert(pSeq);
	if (pSeq->_size >= N)
	{
		printf("The SeqList is full\n");
	}
	else
	{
		 
		pSeq->_arr[pSeq->_size] = x;
		pSeq->_size++;
	}
}
void SeqLIstInsert(SeqList* pSeq, size_t pos, typedata x)
{
	assert(pSeq);
	assert(pSeq->_size);
	if (pSeq->_size >= N)
	{
		printf("The SeqList is full");
	}
	else
	{
		int end = pSeq->_size - 1;
		for (; end >= (int)pos; end--)
		{
			pSeq->_arr[end + 1] = pSeq->_arr[end];
		}
		pSeq->_arr[pos] = x;
		pSeq->_size++;
	}
}

void test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s, 2);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 2);

	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 8);

	SeqLIstInsert(&s, 4, 9);
	SeqLIstInsert(&s, 3, 2);
	SeqLIstInsert(&s, 9, 1);
	SeqListPrint(&s);

}

void SeqListPopFront(SeqList* pSeq)
{
	assert(pSeq);
	if (0 == pSeq->_size)
	{
		printf("empty\n");
	}
	else
	{
		size_t i = 0;
		for (; i < pSeq->_size - 1; i++)
		{
			pSeq->_arr[i] = pSeq->_arr[i + 1];
		}
		pSeq->_size--;
	}
}
void SeqListPopBack(SeqList* pSeq)
{
	assert(pSeq);
	if (0 == pSeq->_size)
	{
		printf("empty");
	}
	else
	{ 
		pSeq->_size--;
	}
}
void SeqListErase(SeqList* pSeq, size_t pos)
{
	assert(pSeq);
	assert(pSeq->_size);
	if (0 == pSeq->_size)
	{
		printf("empty");
	}
	else
	{
		size_t i = pos;
		for (; i < pSeq->_size - 1; i++)
		{
			pSeq->_arr[i] = pSeq->_arr[i + 1];
		}
		pSeq->_size--;
	}

}

void SeqListFind(SeqList* pSeq, typedata x)
{
	assert(pSeq);
	size_t i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		if (pSeq->_arr[i] == x)
			return i;
	}
	return -1;

}
void SeqListModify(SeqList* pSeq, size_t pos, typedata x)
{
	assert(pSeq);
	pSeq->_arr[pos] = x;

}

void SeqListEraseAll(SeqList* pSeq, typedata x)
{
	assert(pSeq);
	size_t index = 0, i = 0, count = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		if (pSeq->_arr[i] != x)
		{
			pSeq->_arr[index++] = pSeq->_arr[i];
		}
		else
		{
			count++;
		}
		pSeq->_size -= count;
	}
}
void SeqListBubbleSort(SeqList* pSeq)
{
	int i = 0;
	int end = pSeq->_size;
	int IsChange = 1;
	assert(pSeq);
	while (end > 1)
	{
	  //µ•ÃÀ≈≈–Ú
	   for (i = 0; i < end; i++)
	  {
		if (pSeq->_arr[i] > pSeq->_arr[i + 1])
		{
			Swap(&pSeq->_arr[i], &pSeq->_arr[i + 1]);
			IsChange = 0;
		}
		if (1 == IsChange)
		{
			break;
		}

	    }
	   end--;
	}

}
void SeqListSlectSort(SeqList* pSeq)
{
	int left = 0, right = pSeq->_size - 1;
	while (left < right)
	{
		int max = left, min = left;
		int i = left;
		while (i <= right)
		{
			if (pSeq->_arr[i] > pSeq->_arr[max])
			{
				max = i;
			}

			if (pSeq->_arr[i] < pSeq->_arr[min])
			{
				min = i;
			}
			Swap(&pSeq->_arr[left], &pSeq->_arr[min]);
			if (left == max)
			{
				max = min;
			}
			Swap(&pSeq->_arr[right], &pSeq->_arr[max]);
			left++;
			right--;
		}
		++i;
	}


}
int SeqListBinarySearch(SeqList* pSeq, typedata x)
{
	int left = 0;
	int right = pSeq->_size - 1;
	assert(pSeq);
	while (left <= right)
	{
		int mid = left + (right - left) >> 1;
		if (pSeq->_arr[mid] == x)
		{
			return mid;
		}
		else if (pSeq->_arr[mid] < x)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;

	}
	return -1;
}
			   