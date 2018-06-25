#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <assert.h>

typedef int DataType;

//不带头结点单链表
typedef struct Node
{
	DataType data;
	struct Node* pNext;
}Node,List,*pNode,*pList;

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

//任意插
void Insert(pList* pplist,pNode pos, DataType d);
//任意删除
void Erase(pList* pplist,pNode pos);

//删除指定元素
void ReMove(pList* pplist, DataType d);
//删除指定元素 (法二)
void ReMove_OP(pList* pplist, DataType d);
//删除指定所有元素
void ReMoveAll(pList* pplist, DataType d);


//查找
pNode Find(pList pplist,DataType d);
//清空
void Clear(pList* pplist);
//链表大小
int Size(pList pplist);

 




#endif//__LIST_H__