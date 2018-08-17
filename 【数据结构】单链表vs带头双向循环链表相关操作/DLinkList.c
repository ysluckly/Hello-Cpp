
#include "DLinkList.h"

//////////////////////////////带头结点循环双链表/////////////////////////////////////
void DLinkListInit(DLinkList* pHead)
{
	assert((pHead));
	DLinkList tmp = (DLinkList)malloc(sizeof(pDLinkList));
	assert(tmp);
	*pHead = tmp;
	(*pHead)->pNext = (*pHead);
	(*pHead)->pPrev = (*pHead);
}
void DLinkListDestory(DLinkList* pHead)
{
	assert((pHead));
	DLinkList ptr = (*pHead)->pNext;;
	while (ptr != (*pHead))
	{
		DLinkList pCur = ptr->pNext;
		free(ptr);
		ptr = pCur;
	}
	free(*pHead);
	(*pHead) = NULL;
	printf("销毁成功\n");
}

void DLinkListPushBack(DLinkList* pHead, DataType x)
{
	assert((pHead));
	DLinkListInsert((pHead), (*pHead), x);
}
void DLinkListPushFront(DLinkList* pHead, DataType x)
{
	assert((pHead));

	DLinkListInsert((pHead), (*pHead)->pNext, x);

}
void DLinkListPopBack(DLinkList* pHead)
{
	assert((pHead));

	DLinkListErase((pHead), (*pHead)->pPrev);

}
void DLinkListPopFront(DLinkList* pHead)
{
	assert((pHead));

	DLinkListErase((pHead), (*pHead)->pNext);

}

 DLinkList BuyNode(DataType x)
{
	DLinkList tmp = (DLinkList)malloc(sizeof(pDLinkList));
	assert(tmp);
	tmp->data = x;
	tmp->pNext = NULL;
	tmp->pPrev = NULL;
	return tmp;

}
DLinkList DLinkListFind(DLinkList* pHead, DataType x)
{
	assert((pHead));
	DLinkList pCur = (*pHead)->pNext;
	while (pCur != (*pHead))
	{
		if (pCur->data == x)
		{
			return pCur;
		}
		pCur = pCur->pNext;
	}
	return NULL;

}
void DLinkListInsert(DLinkList* pHead, DLinkList pos, DataType x)
{
	assert(pos && (pHead));
	DLinkList pre = pos->pPrev;
	DLinkList pNewNode = BuyNode(x);
	pre->pNext = pNewNode;
	pNewNode->pPrev = pre;
	pNewNode->pNext = pos;
	pos->pPrev = pNewNode;

}
void DLinkListErase(DLinkList* pHead, DLinkList pos)
{
	assert(pos && (pHead));
	if ((*pHead) == pos)
	{
		printf("非法删除\n");
		return;
	}
	else
	{
		DLinkList next = pos->pNext;
		DLinkList pre = pos->pPrev;
		pre->pNext = next;
		next->pPrev = pre;
		free(pos);
		pos = NULL;
	}
}

int DLinkListSize(DLinkList* pHead)
{
	assert((pHead));
	int len = 0;
	DLinkList pCur = (*pHead)->pNext;
	while (pCur!= (*pHead))
	{
		len++;
		pCur = pCur->pNext;
	}
	return len;
}
int DLinkListEmpty(DLinkList* pHead)
{
	assert((pHead));
	return (*pHead)->pNext == (*pHead);
}

void PrintDLinkList(DLinkList pHead)
{
	assert((pHead));
	DLinkList pCur = (pHead)->pNext;
	while (pCur != (pHead))
	{
		printf("%d ",pCur->data);
		pCur = pCur->pNext;
	}
	printf("\n");
}


void testDLinkList()
{
	DLinkList dl;
	DLinkListInit(&dl);


	DLinkListPushBack(&dl, 4);
	DLinkListPushBack(&dl, 5);
	DLinkListPushBack(&dl, 6);
	DLinkListPushBack(&dl, 7);
	DLinkListPushBack(&dl, 8);

	PrintDLinkList(dl);

	printf("大小 %d\n",DLinkListSize(&dl));
	if (DLinkListFind(&dl, 4) != NULL)
	{
		printf("查找           %d\n", DLinkListFind(&dl, 4)->data);
	}
	else
	{
		printf("找不到\n");
	}
	printf("为空： %d\n", DLinkListEmpty(&dl));

	DLinkListInsert(&dl, DLinkListFind(&dl, 4), 0);
	PrintDLinkList(dl);

	printf("大小%d\n", DLinkListSize(&dl));
	if (DLinkListFind(&dl, 7) != NULL)
	{
		printf("查找           %d\n", DLinkListFind(&dl, 7)->data);
	}
	else
	{
		printf("找不到\n");
	}
	printf("为空： %d\n", DLinkListEmpty(&dl));

	DLinkListErase(&dl, DLinkListFind(&dl, 8));
	PrintDLinkList(dl);

	printf("大小 %d\n", DLinkListSize(&dl));
	if (DLinkListFind(&dl, 8) != NULL)
	{
		printf("查找           %d\n", DLinkListFind(&dl, 8)->data);
	}
	else
	{
		printf("找不到\n");
	}
	printf("为空： %d\n", DLinkListEmpty(&dl));


	DLinkListDestory(&dl);



}