#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkPractice.h"
static pList plist = NULL;


void testprint()
{
	PushBack(&plist, 2);
	PushBack(&plist, 9);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);

	//ReversPrintLinkList(plist);
	ReversPrintLinkList_OP(plist);
 
}

void testerasenottail()
{
	pNode pos = NULL;
	PushBack(&plist, 2);
	PushBack(&plist, 9);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);
	pos = Find(plist, 6);
	if (pos)
	{
		EraseWithoutHeadNotTail(pos);
	}
	PrintList(plist);


}
void testinsrttnodetofront()
{
	pNode pos = NULL;
	PushBack(&plist, 2);
	PushBack(&plist, 9);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);
	pos = Find(plist, 6);
	if (pos)
	{
		 InsertNodeToFront(pos,8);
	}
	PrintList(plist);

}

void testjosephuscycle()
{
	int i = 0;
	for (i = 1; i <= 10; i++)
	{
		PushBack(&plist, i);

	}
	PrintList(plist);
	//构成环
	Find(plist, 10)->pNext = plist;
	
	JosephusCycle(&plist,3);
	Find(plist, 4)->pNext = NULL;

}
void testreverssinglelink()
{
	PushBack(&plist, 2);
	PushBack(&plist, 9);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);

	ReversSingleLinkList(&plist);
	PrintList(plist);

}

void testreverssinglelink_OP()
{
	PushBack(&plist, 2);
	PushBack(&plist, 9);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);

	ReversSingleLinkList_OP(&plist);
	PrintList(plist);

}
void testbubblesort()
{
	PushBack(&plist, 2);
	PushBack(&plist, 9);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PrintList(plist);

	BubbleSort(&plist);
	PrintList(plist);
}
void testmerge()
{
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	pNode plist3 = NULL;
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 5);
	PushBack(&plist1, 8);
	PushBack(&plist1, 9);
	PrintList(plist1);


	PushBack(&plist2, 2);
	PushBack(&plist2, 4);
	PushBack(&plist2, 6);
	PushBack(&plist2, 7);
	PushBack(&plist2, 8);
	PrintList(plist2);


	//plist3 = Merge(plist1, plist2);
	plist3 = Merge_OP(plist1, plist2);
	PrintList(plist3);
}
void testfindmiddle()
{
	pNode plist1 = NULL;
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 5);
	PushBack(&plist, 8);
	PushBack(&plist, 9);
	PrintList(plist);

	plist1 = FindMiddle(plist);
	printf("%d\n", plist1->data);
}
void testfindrevers()
{
	pNode plist1 = NULL;
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 5);
	PushBack(&plist, 8);
	PushBack(&plist, 9);
	PrintList(plist);

	plist1 = FindRevers(plist,2);
	printf("%d",plist1->data);
}
void testiswithcross()
{
	pNode plist1 = NULL;
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 5);
	PushBack(&plist1, 8);
	PushBack(&plist1, 9);
	PrintList(plist);

	pNode tmp = Find(plist, 5);
	Find(plist, 9)->pNext =  tmp;

	pNode ret = IsWithCross(plist);
	if (ret == NULL)
	{
		printf("不 带环的 \n");
	}
	else
	{
		printf("带环的\n");
		pNode pMeet = IsWithCross(plist);
		printf("环长度  %d\n", GetCrossLenth(pMeet));
		printf("环入口：%d\n", CrossIn(plist, pMeet)->data);
		Find(plist, 9)->pNext = NULL;

	}

}
void testcross()
{
	pNode plist1 = NULL;
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 4);

	PushBack(&plist1, 5);
	PushBack(&plist1, 8);
	PushBack(&plist1, 9);
	PrintList(plist);

	pNode plist2 = NULL;
	PushBack(&plist2, 2);
	PushBack(&plist2,3);
	PushBack(&plist2, Find(plist1, 5));

	if (1 == CheckCross(plist1, plist2))
	{
		printf("相交\n");
	}
	else
	{
		printf("不相交\n");
	}

	pNode tmp = GetCrossNode(plist1,plist2);
	printf("%d  ",tmp->data);

	DestoryList(&plist1);
	DestoryList(&plist2);


}





int main()
{
	InitList(&plist);
	//testprint();
	//testerasenottail();
	//testinsrttnodetofront();
	//testjosephuscycle();			 //循环链表，销毁应该先断开链表
	//testreverssinglelink();
	//testreverssinglelink_OP();
	//testbubblesort();
	//testmerge();
	//testfindmiddle();
	//testfindrevers();
	//testiswithcross();			   //循环链表，销毁应该先断开链表
	//testcross();
	

	DestoryList(&plist);
	system("pause");
	return 0;
}

