#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkPractice.h"



////////////////////////////////////////////单链表接口/////////////////////////////////////

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
////////////////////////////////////////////单链表面试题/////////////////////////////////////// 

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

	while (plist != pTail)
	{
		pCur = plist;
		while (pCur->pNext != pTail)
		{
			pCur = pCur->pNext;
		}
		printf("%d ",pCur->data);
		pTail = pCur;

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
	pNode p3 = NULL;   //为了使链表不会丢失

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
	pNode pCur = NULL;
	pNode pTmp = NULL;	  //为了使链表不会丢失


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
//冒泡排序
void BubbleSort(pList* pplist)
{
	pNode pCur = NULL;
	pNode pTmp = NULL;
	pNode pTail = NULL;
	int flag = 1;

	assert(pplist);
	if ((NULL == (*pplist)) || (NULL == (*pplist)->pNext))
		return;

	while ((*pplist) != pTail)
	{
		pCur = (*pplist);
		pTmp = pCur->pNext;
		while (pCur->pNext != pTail)	//while(pTmp != pTail)
		{
			if (pCur->data > pTmp->data)
			{
				DataType tmp = pCur->data;
				pCur->data = pTmp->data;
				pTmp->data = tmp;
				flag = 0;	 
			}
			pCur = pTmp;
			pTmp = pTmp->pNext;
		}
		if (1 == flag)
			break;
		pTail = pCur;
	}
}
//合并两个有序单链表
pNode Merge(pList plist1, pList plist2)
{
	
	pNode pCur = NULL;

	if (NULL == plist1)
		return plist2;
	if (NULL == plist2)
		return plist1;

	if (plist1 == plist2)
		return NULL;

	pNode pNewList = (pNode)malloc(sizeof(Node));
	pCur = pNewList;
	while (plist1&&plist2)
	{
		if (plist1->data > plist2->data)
		{
			pCur->pNext = plist2;
			plist2 = plist2->pNext;
		}
		else
		{
			pCur->pNext = plist1;
			plist1 = plist1->pNext;
		}
		pCur = pCur->pNext;
	}
	if (plist1)
	{
		pCur->pNext = plist1;
	}
	else if (plist2)
	{
		pCur->pNext = plist2;
	}
	return pNewList->pNext;
}

//合并两个有序单链表:递归
pNode Merge_OP(pList plist1, pList plist2)
{
	pNode pNewList = (pNode)malloc(sizeof(Node));

	pNode pCur = pNewList;


	if (NULL == plist1)
		return plist2;
	if (NULL == plist2)
		return plist1;

	if (plist1 == plist2)
		return NULL;

	if (plist1->data > plist2->data)
	{
		 
		pCur->pNext = Merge_OP(plist1, plist2->pNext);
	}
	else
	{
		 
		pCur->pNext = Merge_OP(plist1->pNext, plist2);

	}
	return pNewList->pNext;

}

//寻找中间节点
pNode FindMiddle(pList plist)
{
	pList pSlow = plist;
	pList pFast = plist;
	if ((NULL == plist) || (NULL == plist->pNext))
		return plist;
	while (pFast&&pFast->pNext)
	{
		pFast = pFast->pNext->pNext;
		pSlow = pSlow->pNext;

	}
	return pSlow;

}
//寻找倒数第k节点
pNode FindRevers(pList plist, size_t k)
{
	pNode pFast = plist;
	pNode pSlow = plist;
	if (NULL == plist)
		return NULL;
	while (k--)
	{
		if (pFast == NULL)
			return NULL;
		pFast = pFast->pNext;
	}
	while (pFast)
	{
		pFast = pFast->pNext;
		pSlow = pSlow->pNext;
	}
	return pSlow;
}
//判断单链表是否带换？若带环，求长度,环入口。
pNode IsWithCross(pList plist)
{
	pList pFast = plist;
	pList pSlow = plist;
	assert(plist);
	
	while (pFast&&pFast->pNext)
	{

		pFast = pFast->pNext->pNext;
		pSlow = pSlow = pSlow->pNext;
		if (pFast == pSlow)
		{
			return pSlow;
		}
	}
	return NULL;
}
int GetCrossLenth(pList pMeet)
{
	int len = 0;
	pNode pCur = NULL;
	assert(pMeet);
	
	len = 1;
	pCur = pMeet->pNext;
	while (pCur!=pMeet)
	{
		len++;
		pCur = pCur->pNext;
	}
	return len;
}
pNode CrossIn(pList plist, pList pMeet)
{
	pNode pCur = NULL;
	assert(plist&&pMeet);
	pCur = plist;
	while (pCur != pMeet)
	{
		pCur = pCur->pNext;
		pMeet = pMeet->pNext;
	}
	return pCur;
}
//判断两单链表是否相交？若相交，求交点
int CheckCross(pList plist1, pList plist2)
{
	assert(plist1&&plist2);
	pNode p1 = plist1;
	pNode p2 = plist2;

	while (p1->pNext)
	{
		p1 = p1->pNext;
	}
	while (p2->pNext)
	{
		p1 = p2->pNext;
	}
	/*if (p1 == p2)
	{
		return 1;
	}
	else
	{
		return 0;
	}  */
	return p1 == p2;
}
pNode GetCrossNode(pList plist1, pList plist2)
{
	assert(plist1&&plist2);
	int len1 = 0;
	int len2 = 0;

	pNode p1 = plist1;
	pNode p2 = plist2;
	while (p1)
	{
		len1++;
		p1 = p1->pNext;
	}
	while (p2)
	{
		len2++;
		p2 = p2->pNext;
	}

	//长表比短表多出的长度
	int gap = abs(len1 - len2);
	//默认pCur1 为长链表
	pNode pCur1 = p1;
	pNode pCur2 = p2;
	if (len2 > len1)
	{
		pCur1 = p2;
		pCur2 = p1;

	}
	while (gap--)
	{
		pCur1 = pCur1->pNext;
	}
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->pNext;
		pCur2 = pCur2->pNext;
	}
	return pCur1;

}
//复杂链表复制

ComplexNode* ComplexListCopy(ComplexNode* head)
{
	ComplexNode* pOldList = NULL;
	ComplexNode* pNewList = NULL;
	ComplexNode* pNewHead = NULL;

	if (head == NULL)
		return NULL;
	pOldList = head;
	//每个结点后边链接一个与自身一致的结点
	while (pOldList)
	{
		ComplexNode* tmp = (ComplexNode*)malloc(sizeof(ComplexNode));
		tmp->data = pOldList->data;
		tmp->pNext = NULL;
		tmp->pRandom = NULL;

		tmp->pNext = pOldList->pNext;
		pOldList->pNext = tmp;
		pOldList = tmp->pNext;
	}
	//对新结点随机域赋值
	pOldList = head;
	while (pOldList)
	{
		pNewList = pOldList->pNext;
		
		pNewList->pRandom = (pOldList->pRandom==NULL)?NULL:pOldList->pRandom->pNext;
		pOldList = pNewList->pNext;

	}
	//拆分链表
	pOldList = head;
	pNewHead = pOldList->pNext;
	while (pOldList->pNext)
	{
		pNewList = pOldList->pNext;
		pOldList->pNext = pNewList->pNext;
		pOldList = pNewList;
	}
	return pNewHead;
}
//两个单链表的交集
void Union(pList plist1, pList plist2)
{
	pNode p1 = plist1;
	pNode p2 = plist2;
	if (plist1 == NULL || plist2 == NULL)
		return ;
	if (p1->data < p2->data)
	{
		p1 = p1->pNext;
	}
	else if (p1->data>p2->data)
	{
		p2 = p2->pNext;
	}
	else
	{
		printf("%d  ",p1->data);
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	
}


//两个单链表的并集

void Togeter(pList* plist1, pList plist2)
{
	assert(plist1&&plist2);
	//思路：把2中每个元素单独拿出来与1中所有元素比较，
	//如果把1遍历完都没有相同就把此元素链接1后，开始对2中的下一个元素进行相同操作，
	//如果有相同就直接退出比较，开始对2中的下一个元素进行相同操作
}

//两个单链表的差集  plsit-plist2(去重)
void Difference(pList* plist1, pList plist2)
{
	assert(plist1&&plist2);
	//思路：先取1第一个元素跟2所有比较，如果有相同删掉此节点，
	//如果没有相同就继续下一个结点跟2所有元素比较
	pNode pa = (*plist1);
	pNode pb = plist2;
	pNode pre = NULL, pDel = NULL;
	while (pa)
	{
		pb = plist2;
		while (pb&&pa->data != pb->data)
			pb = pb->pNext;
		if (pb)
		{
			if (!pre)
			{
				(*plist1) = pa->pNext;

			}
			else
			{
				pre->pNext = pa->pNext;

			}
			pDel = pa;
			pa = pa->pNext;
			free(pDel);
			pDel = NULL;
		}
		else
		{
			pre = pa;
			pa = pa->pNext;
		}
	}

}