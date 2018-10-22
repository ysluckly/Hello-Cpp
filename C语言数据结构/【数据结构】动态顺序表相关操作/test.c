#define _CRT_SECURE_NO_WARNINGS 1


#include "SeqList.h"
static SeqList seq;

void testpushback()
{
	PushBack(&seq, 2);
	PushBack(&seq, 6);
	PushBack(&seq, 5);

	PrintSeqList(&seq);
	PushBack(&seq, 9);
	PrintSeqList(&seq);

}


void testpopback()
{
	PopBack(&seq); 
	PrintSeqList(&seq);

	PopBack(&seq);
	PrintSeqList(&seq);

}
void testpushfront()
{
	PushFront(&seq, 2);
	PushFront(&seq, 6);
	PushFront(&seq, 5);
	PushFront(&seq, 7);
	PushFront(&seq, 9);
	PushFront(&seq, 5);

	PrintSeqList(&seq);
}
void testpopfront()
{
	PushFront(&seq, 2);
	PushFront(&seq, 6);
	PushFront(&seq, 5);
	PushFront(&seq, 7);
	PushFront(&seq, 9);
	PushFront(&seq, 5);

	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}
int testFind()
{
	PushFront(&seq, 2);
	PushFront(&seq, 6);
	PushFront(&seq, 5);
	PushFront(&seq, 7);
	PushFront(&seq, 9);
	PushFront(&seq, 5);
	PrintSeqList(&seq);

	int pos = 0;
	pos = Find(&seq, 3);
	if (pos == -1)
	{
		printf("没找到");
	}
	else
		printf("找到了 下标%d ", pos);
}

void testInsert()
{
	int pos = 3;
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	printf("\n");
	Insert(&seq, pos, 9);
	PrintSeqList(&seq);

}

void testErase()
{
	int pos = 3;
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 6);
	PushFront(&seq, 2);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	printf("\n");
	Erase(&seq, pos);
	PrintSeqList(&seq);

}

void testRemove()
{
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 6);
	PushFront(&seq, 2);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	printf("\n");
	ReMove(&seq, 3);
	PrintSeqList(&seq);

}

void testRemoveall()
{
	PushFront(&seq, 5);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 5);
	PushFront(&seq, 5);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	printf("\n");
	ReMoveAll(&seq, 5);
	PrintSeqList(&seq);

}

int testsize()
{

	PushFront(&seq, 5);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 5);
	PushFront(&seq, 5);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	printf("\n");
	printf("%d", Size(&seq));

}


void testempty()
{
	int ret = 0;
	PushFront(&seq, 5);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 5);
	PushFront(&seq, 5);
	PushFront(&seq, 5);
	PrintSeqList(&seq);
	printf("\n");
	ret = IsEmpty(&seq);
	if (!ret)
	{
		printf("kong");
	}
	else
	{
		printf("not kong");
	}


}
void testbubblesort()
{
	PushFront(&seq, 9);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 5);
	PushFront(&seq, 7);
	PrintSeqList(&seq);
	printf("\n");
	BubbleSort(&seq);
	PrintSeqList(&seq);

}
void testselectsort()
{
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 6);
	PushFront(&seq, 5);
	PushFront(&seq, 2);
	PrintSeqList(&seq);
	printf("\n");
	SelectSort(&seq);
	PrintSeqList(&seq);
}

void testbinarysearch()
{
	int pos = 0;
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 6);
	PushFront(&seq, 5);
	PushFront(&seq, 2);
	PrintSeqList(&seq);
	printf("\n");
	pos = BinarySearch(&seq,0,seq.size-1,1);
	if (pos != -1)
	{
		printf("下标为%d\n",pos);
	}
	else
	{
		printf("找不到\n");
	}
	 
}

int main()
{
	Init(&seq);
	//testpushback();
	//testpopback();
	//testpushfront();
	//testpopfront();
	//testFind();
	//testInsert();
	//testErase();
	//testRemove();
	//testRemoveall();
	//testsize();
	//testempty();
	//testbubblesort();
	//testselectsort();
	testbinarysearch();






	Destory(&seq);
	system("pause");
	return 0;
}

