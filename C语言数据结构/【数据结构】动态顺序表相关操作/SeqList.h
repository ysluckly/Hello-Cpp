#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <string.h>

typedef int DataType;
#define DEFAULE_MAX 3

typedef struct SeqList
{
	DataType* data;
	size_t size;
	size_t capacity;
}SeqList, *pSeqList;

//初始化
void Init(pSeqList pSeq);
//销毁
void Destory(pSeqList pSeq);
//打印
void PrintSeqList(pSeqList pSeq);

//尾插
void PushBack(pSeqList pSeq, DataType d);
//尾删
void PopBack(pSeqList pSeq);

//头部插入
void PushFront(pSeqList pSeq, DataType d);
//头部删除
void PopFront(pSeqList pSeq);

//查找
int Find(pSeqList pSeq, DataType d);
//指定个数插入（第几个）
void Insert(pSeqList pSeq, size_t pos, DataType d);
//指定下标删除
void Erase(pSeqList pSeq, size_t pos);
//删除指定元素
void ReMove(pSeqList pSeq, DataType d);
//删除所有指定元素
void ReMoveAll(pSeqList pSeq, DataType d);
//返回顺序表大小
int Size(pSeqList pSeq);
//判断顺序表是否为空
int IsEmpty(pSeqList pSeq);
//冒泡排序
void BubbleSort(pSeqList pSeq);
//选择排序
void SelectSort(pSeqList pSeq);
//二分排序
int BinarySearch(pSeqList pSeq, DataType d);









#endif// __SEQLIST_H__