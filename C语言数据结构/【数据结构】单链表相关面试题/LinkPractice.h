#ifndef __PRACTICE_H__
#define __PRACTICE_H__

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>


typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* pNext;
}Node, *pNode,*pList;

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* pNext;
	struct ComplexNode* pRandom;
}ComplexNode;

///////////////////////////////链表接口实现/////////////////////////////////////////

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

////////////////////////////////单链表面试题////////////////////////////////////////

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
//冒泡排序
void BubbleSort(pList* pplist);
//合并两个有序单链表
pNode Merge(pList plist1,pList plist2);
pNode Merge_OP(pList plist1, pList plist2);
//寻找中间节点
pNode FindMiddle(pList plist);
//寻找倒数第k节点
pNode FindRevers(pList plist, size_t k);
//判断单链表是否带换？若带环，求长度,环入口。
pNode IsWithCross(pList plist);
int GetCrossLenth(pList pMeet);
pNode CrossIn(pList plist, pList pMeet);
//判断两单链表是否相交？若相交，求交点
int CheckCross(pList plist1, pList plist2);
pNode GetCrossNode(pList plist1, pList plist2);
//复杂链表复制
ComplexNode* ComplexListCopy(ComplexNode head);

//两个单链表的交集
void Union(pList plist1, pList plist2);
//两个单链表的差集
void Difference(pList* plist1, pList plist2);
//两个单链表的并集
void Togeter(pList* plist1, pList plist2);









//


#endif //__PRACTICE_H__