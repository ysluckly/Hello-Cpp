#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <string.h >
#include <malloc.h>

#define MAX 100
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	size_t size;
}SeqList, *pSeqList;

//初始化
void InitSeqList(pSeqList pSeq);
//打印静态顺序表
void PrintSeqList(pSeqList pSeq);
//尾部插入
void PushBack(pSeqList pSeq, DataType d);
//尾部删除
void PopBack(pSeqList seq);
//头部插入
void PushFront(pSeqList pSeq, DataType d);
//头部删除
void PoPFront(pSeqList pSeq);
//查找
int Find(pSeqList pSeq, DataType d);
//指定个数插入（第几个）
void Insert(pSeqList pSeq, size_t pos, DataType d);
//指定下标删除
void Erase(pSeqList pSeq,size_t pos);
//删除指定元素
void ReMove(pSeqList pSeq,DataType d);
//删除所有指定元素
void ReMoveAll(pSeqList pSeq, DataType d);
//返回顺序表大小
int Size(pSeqList pSeq);
//判断顺序表是否为空
int Empty(pSeqList pSeq);
//冒泡排序
void BubbleSort(pSeqList pSeq);
//选择排序
void SelectSort(pSeqList pSeq);
//二分排序
int BinarySearch(pSeqList pSeq, DataType d);



#endif  //__SEQLIST_H__