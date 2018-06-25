#define _CRT_SECURE_NO_WARNINGS 1

#include "LinkList.h"

pList plist = NULL;



void testpushback()
{
	PushBack(&plist,2);
	PushBack(&plist,5);
	PushBack(&plist,8);
	PushBack(&plist,6);
	PushBack(&plist,9);

	PrintList(plist);
}

void testpopback()
{
	PushBack(&plist, 2);
	PushBack(&plist, 5);
	PushBack(&plist, 8);
	PushBack(&plist, 6);
	PushBack(&plist, 9);

	PrintList(plist);
	PopBack(&plist);
	PrintList(plist);
	PopBack(&plist);
	PrintList(plist);

}
void testpushfront()
{
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 2);
	PushFront(&plist, 0);
	PushFront(&plist, 9);
	PrintList(plist);
}

void testpopfront()
{
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 2);
	PushFront(&plist, 0);
	PushFront(&plist, 9);
	PrintList(plist);

	
	PopFront(&plist);
	PrintList(plist);

	PopFront(&plist);
	PrintList(plist);
}

void testinsert()
{
	pNode pos = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 9);
	PrintList(plist);
	pos = Find(plist,5);
	if (pos)
	{
		Insert(&plist, pos ,4);
		PrintList(plist);

	}
	

}
void testerase()
{

	pNode pos = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 9);
	PrintList(plist);
	pos = Find(plist, 7);
	if (pos)
	{
		Erase(&plist, pos);
		PrintList(plist);

	}

}
void testfind()
{
	pNode POS = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 9);
	PrintList(plist);

	if (Find(plist, 0) != NULL)
	{		
		POS = Find(plist, 0);
	}
	else
	{
		printf("Ã»ÕÒµ½");
		return;
	}
	
	printf("%d",POS->data);

}
void testclear()
{
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 9);
	PrintList(plist);
	Clear(&plist);

}
void testsize()
{
	int i = 0;
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 9);
	PrintList(plist);

	i = Size(plist);
	printf("%d\n",i);

}

void testremove()
{
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 7);
	PushFront(&plist, 9);
	PrintList(plist);

	ReMove(&plist, 5);
	ReMove_OP(&plist, 9);
	PrintList(plist);


}

void testremoveall()
{
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 5);
	PushFront(&plist, 9);
	PushFront(&plist, 6);
	PushFront(&plist, 5);
	PushFront(&plist, 6);
	PushFront(&plist, 5);
	PrintList(plist);

	ReMoveAll(&plist, 5);
	ReMoveAll(&plist, 6);
	PrintList(plist);

}
int main()
{
	InitList(&plist);
	//testpushback();
	//testpopback();
	//testpushfront();
	//testpopfront();
	//testinsert();
	//testerase();
	//testfind();
	//testremove();
	testremoveall();
	//testclear();
	//testsize();






	DestoryList(&plist);
	system("pause");
	return 0;
}

