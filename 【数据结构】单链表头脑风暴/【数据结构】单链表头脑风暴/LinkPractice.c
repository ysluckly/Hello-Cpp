#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkPractice.h"

//逆序打印单链表（递归）
void ReversPrintLinkList(pList plist)
{
	if (plist == NULL)
	{
		return;
	}
	if (plist->pNext == NULL)
	{
		printf("%d ",plist->data);
		return;
	}
	ReversPrintLinkList(plist->pNext);
	printf("%d ", plist->data);


}
//逆序打印单链表（非递归）
void ReversPrintLinkList_OP(pList plist)
{
	pNode pCur = NULL;
	pNode pTail = NULL;
	if (plist == NULL)
	{
		return;
	}
	if (plist->pNext == NULL)
	{
		printf("%d ", plist->data);
		return;
	}

	pCur = plist;
	while (pCur != pTail)
	{
		while (pCur->pNext != pTail)
		{
			pCur = pCur->pNext;
		}
		printf("%d ",pCur->data);
		pTail = pCur;
		pCur = plist;

	}
	
}

//删除单链表无头非尾节点
void EraseWithoutHeadNotTail(pNode pos)
{
	pNode pDel = NULL;
	assert(pos && pos->pNext);

	pDel = pos->pNext;
	pos->data = pDel->data;
	pos->pNext = pDel->pNext;
	free(pDel);
	pDel = NULL;

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
//在无头链表某节点前面插入一个节点
void InsertNodeToFront(pNode pos,DataType d)
{
	pNode pNewNode = NULL;
	assert(pos);

	pNewNode = BuyNode(pos->data);
	pNewNode->pNext = pos->pNext;
	pos->pNext = pNewNode;
	pos->data = d;

}

//约瑟夫环问题：打印依次被删的序列号并保留最后一个
void JosephusCycle(pNode* pplist,size_t k)
{
	pNode pCur = NULL;
	assert(pplist);
	pCur = *pplist;

	while (pCur != pCur->pNext)
	{
		pNode pDel = NULL;
		int count = k;
		while (--count)
		{
			pCur = pCur->pNext;
		}
		printf("删除的是：%d\n",pCur->data);
		pDel = pCur->pNext;
		pCur->data = pDel->data;
		pCur->pNext = pDel->pNext;
		free(pDel);
		pDel = NULL;
	}
	printf("最后幸存的是：%d\n", pCur->data);

}

//逆置单链表（法一：三指法）	
void ReversSingleLinkList(pList* pplist)
{
	pNode p1 = NULL;
	pNode p2 = NULL;
	pNode p3 = NULL;

	assert(pplist);

	if ((*pplist == NULL) || ((*pplist)->pNext == NULL))
	{
		return;
	}

	p1 = (*pplist);
	p2 = p1->pNext;
	p3 = p2->pNext;

	while (p2)
	{
		p2->pNext = p1;
		p1 = p2;
		p2 = p3;
		if (p3)
		{
			p3 = p3->pNext;
		}

	}
	(*pplist)->pNext = NULL;	//谨慎处理
	(*pplist) = p1;
	
}

//逆置单链表：优化
void ReversSingleLinkList_OP(pList* pplist)
{
	pNode pHead = NULL;
	pNode pTmp = NULL;
	pNode pCur = NULL;

	assert(pplist);

	pCur = (*pplist);
	pTmp = pCur->pNext;

	while (pCur)
	{  
		pCur->pNext = pHead;
		pHead = pCur;
		pCur = pTmp;
		if (pTmp)
		{
			pTmp = pTmp->pNext;
		}
	}
	(*pplist) = pHead;
}






















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
		printf("%d ", pCur->data);
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
//查找
pNode Find(pList pplist, DataType d)
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
