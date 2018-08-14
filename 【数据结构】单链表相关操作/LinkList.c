#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"

//初始化
//改变传地址，不改变传值
void InitList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}
//打印
//改变传地址，不改变传值
void PrintList(pList pplist)
{
	//值传递不需要断言
	pNode pCur = pplist;
	while (pCur)
	{			    
		printf("%d ",pCur->data);
		pCur = pCur->pNext;
	}
	printf("\n");
	
}
//销毁链表
void DestoryList(pList* pplist)
{
	pNode pDel = NULL;
	assert(pplist);
	while (*pplist)
	{
		pDel = *pplist;
		*pplist = pDel->pNext;
		free(pDel);
		pDel = NULL;
	}
	*pplist = NULL;
	printf("销毁成功\n");
}
//开辟新节点
static pNode BuyNode(DataType d)
{
	pNode tmp = (pNode)malloc(sizeof(Node));
	if (NULL == tmp)
	{
		perror("malloc faile");
		return NULL;
	}
	tmp->data = d;
	tmp->pNext = NULL;
	return tmp;

}
//尾插 (1.检查链表是否存在
//		2.存在为空直接插入
//		3.存在不为空先找到最后节点）
void  PushBack(pList* pplist, DataType d)
{
	pNode pNewNode = NULL;
	//判断是否存在
	assert(pplist);

	pNewNode = BuyNode(d);
	if (NULL == pNewNode)
	{
		exit(EXIT_FAILURE);
	}
	//为空直接插入
	if (NULL == *pplist)
	{
		*pplist = pNewNode;
	}
	//存在不为空找到最后节点
	else
	{
		pNode pCur = *pplist;
		while (pCur->pNext)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNewNode;

	}

}
//尾删（1.空链表返回
//		2.只有一个直接删
//		3.多个找到最后一个删除 ）
void PopBack(pList* pplist)
{
	//判断链表是否存在
	assert(pplist);
	// 1.空链表返回
	if (NULL == *pplist)
	{
		return;
	}
	// 2.只有一个直接删
	else if (NULL == (*pplist)->pNext)
	{
		free(*pplist);
		*pplist = NULL;
		
	}
	// 3.多个找到倒数第二个删除
	else
	{
		pNode pCur = *pplist;
		while (pCur->pNext->pNext)
		{
			pCur = pCur->pNext;
		}
		free(pCur->pNext);
		pCur->pNext = NULL;
	}
}
//头插
void  PushFront(pList* pplist, DataType d)
{
	pNode pNewNode = NULL;
	assert(pplist);
	pNewNode = BuyNode(d);

	if (NULL == pNewNode)
	{
		return;
	}

	pNewNode->pNext = *pplist;
	*pplist = pNewNode;
}
//头删
void PopFront(pList* pplist)
{
	pNode pDel = NULL;
	assert(pplist);

	if (NULL == *pplist)
	{
		return;
	}

	pDel = *pplist;
	*pplist = pDel->pNext;
	free(pDel);
	pDel = NULL;
}


//任意插
void Insert(pList* pplist,pNode pos, DataType d)
{
	pNode pCur = NULL;
	pNode pNewNode = NULL;
	assert(pplist);

	if ((NULL == *pplist) || (pos == NULL))
	{
		return;
	}

	pNewNode = BuyNode(d);
	if (NULL == pNewNode)
	{
		return;
	}
	////插入节点后面
	//pNewNode->pNext = pos->pNext;
	//pos->pNext = pNewNode;

	//插入节点前面
	//第一个节点
	if (pos == (*pplist))
	{
		pNewNode->pNext = pos;
		(*pplist) = pNewNode;
	}
	else  //多节点
	{
		pCur = *pplist;
		while (pCur && pCur->pNext != pos)
		{
			pCur = pCur->pNext;
		}
		if (pCur)
		{
			pNewNode->pNext = pCur->pNext;
			pCur->pNext = pNewNode;

		}
	}

}
//任意删除
void Erase(pList* pplist, pNode pos)
{
	pNode pCur = NULL;
	assert(pplist);
	if ((NULL == *pplist) || (pos == NULL))
	{
		return;
	}
	if (pos == *pplist)
	{
		PopFront(pplist);
	}
	else
	{
		pNode pCur = *pplist;
		while (pCur && pCur->pNext != pos)
		{
			pCur = pCur->pNext;
		}
		if (pCur)
		{
			pCur->pNext = pos->pNext;
			free(pos);
			pos = NULL;
		}
	}

}

//删除指定元素 (法一)
void ReMove(pList* pplist, DataType d)
{
	pNode pPre = NULL;
	pNode pCur = NULL;
	assert(pplist);

	if (*pplist == NULL)
	{
		return;
	}

	pCur = *pplist;
	while (pCur)
	{
		if (pCur->data == d)
		{
			if (pCur == (*pplist))
			{
				PopFront(pplist);
			}
			else
			{
				pPre->pNext = pCur->pNext;
				free(pCur);
				pCur = NULL;

			}
			return;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
	}

}

//删除指定元素 (法二)
void ReMove_OP(pList* pplist, DataType d)
{
	pNode pos = NULL;
	assert(pplist);

	if (*pplist == NULL)
	{
		return;
	}

	//值传递
	pos = Find(*pplist, d);

	if (pos)
	{
		//址传递
		Erase(pplist,pos);
	}
}



//删除指定所有元素
void ReMoveAll(pList* pplist, DataType d)
{
	pNode pPre = NULL;
	pNode pCur = NULL;
	assert(pplist);

	if (*pplist == NULL)
	{
		return;
	}

	pCur = *pplist;
	while (pCur)
	{
		if (pCur->data == d)
		{
			if (pCur == (*pplist))
			{
				PopFront(pplist);
				pCur = *pplist;
			}
			else
			{
				pPre->pNext = pCur->pNext;
				free(pCur);
				pCur = pPre->pNext;

			}
		}
		else
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
	}

}

//查找
pNode Find(pList pplist,DataType d)
{
	pNode pCur = NULL;
	assert(pplist);

	pCur = pplist;
	while (pCur)
	{
		if (d == pCur->data)
		{
			return pCur;
		}
		pCur = pCur->pNext;
	}
	return NULL;


}
//清空
void Clear(pList* pplist)
{
	pNode pDel = NULL;
	assert(pplist);
	while (*pplist)
	{
		pDel = *pplist;
		*pplist = pDel->pNext;
		free(pDel);
		pDel = NULL;
	}
	printf("清空成功");

}
//链表大小
int Size(pList pplist)
{
	pNode pCur = NULL;
	int count = 0;
	assert(pplist);

	pCur = pplist;
	while (pCur)
	{
		count++;
		pCur = pCur->pNext;
	}
	return count;


}
