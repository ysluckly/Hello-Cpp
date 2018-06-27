#ifndef __PRACTICE_H__
#define __PRACTICE_H__

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>




typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* pNext;
}Node, *pNode,*pList;


//逆序打印单链表（递归）
void ReversPrintLinkList(pList plist);
//逆序打印单链表（非递归）
void ReversPrintLinkList_OP(pList pist);
//删除单链表无头非尾节点
void EraseWithoutHeadNotTail(pNode pos);
//在无头链表某节点前面插入一个节点
void InsertNodeToFront(pNode pos,DataType d);
//约瑟夫环问题：打印依次被删的序列号并保留最后一个
void JosephusCycle(pNode* pplist,size_t k);
//逆置单链表
void ReversSingleLinkList(pList* pplist);









//初始化
void InitList(pList* pplist);
//打印
void PrintList(pList pplist);
//销毁链表
void DestoryList(pList* pplist);

//尾插
void  PushBack(pList* pplist, DataType d);
//尾删
void PopBack(pList* pplist);
//头插
void  PushFront(pList* pplist, DataType d);
//头删
void PopFront(pList* pplist);
//查找
pNode Find(pList pplist, DataType d);



#endif //__PRACTICE_H__