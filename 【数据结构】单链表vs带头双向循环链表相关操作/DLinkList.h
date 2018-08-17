#ifndef __LINKLIST_H__
#define __LINKLIST_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//带头结点循环双链表

typedef int DataType;
typedef struct DLinkList
{
	DataType data;
	struct DLinkList* pNext;
	struct DLinkList* pPrev;
}pDLinkList,*DLinkList;		//节点信息

/*typedef struct DLinkList
{
	DLinkList* pHead;
}DLinkList;	*/ 		 //链表信息



void DLinkListInit(DLinkList* pHead);
void DLinkListDestory(DLinkList* pHead);

void DLinkListPushBack(DLinkList* pHead,DataType x);
void DLinkListPushFront(DLinkList* pHead,DataType x);
void DLinkListPopBack(DLinkList* pHead);
void DLinkListPopFront(DLinkList* pHead);

DLinkList DLinkListFind(DLinkList* pHead, DataType x);
void DLinkListInsert(DLinkList* pHead, DLinkList pos, DataType x);
void DLinkListErase(DLinkList* pHead, DLinkList pos);
									  
int DLinkListSize(DLinkList* pHead);
int DLinkListEmpty(DLinkList* pHead);

void PrintDLinkList(DLinkList pHead);
void testDLinkList();




#endif//__LINKLIST_H__