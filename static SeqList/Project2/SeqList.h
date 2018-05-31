#pragma once   //保证头文件只被编译一次

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<Windows.h>
#include<stddef.h>     //size_t 无符号整形
//静态顺序表
typedef int typedata;
#define N 10

typedef struct SeqList
{
	typedata _arr[N];
	size_t _size;
}SeqList;
 //增删查改
void Swap(int *x, int *y);
void SeqListInit(SeqList* pSeq);
void SeqListPrint(SeqList* pSeq);
void test1();

void SeqListPushFront(SeqList* pSeq, typedata x);
void SeqListPushBack(SeqList* pSeq, typedata x);
void SeqLIstInsert(SeqList* pSeq, size_t pos, typedata x);

void SeqListPopFront(SeqList* pSeq);	
void SeqListPopBack(SeqList* pSeq);
void SeqListErase(SeqList* pSeq, size_t pos);

void SeqListFind(SeqList* pSeq, typedata x);
void SeqListModify(SeqList* pSeq, size_t pos, typedata x);

void SeqListEraseAll(SeqList* pSeq, typedata x);
void SeqListBubbleSort(SeqList* pSeq);
void SeqListSlectSort(SeqList* pSeq);
int SeqListBinarySearch(SeqList* pSeq, typedata x);



