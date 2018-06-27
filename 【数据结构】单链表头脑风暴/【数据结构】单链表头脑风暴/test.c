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
	//¹¹³É»·
	Find(plist, 10)->pNext = plist;
	
	JosephusCycle(&plist,3);

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

int main()
{
	InitList(&plist);
	//testprint();
	//testerasenottail();
	//testinsrttnodetofront();
	testjosephuscycle();			 //???
	//testreverssinglelink();
	//testreverssinglelink_OP();




	DestoryList(&plist);
	system("pause");
	return 0;
}

