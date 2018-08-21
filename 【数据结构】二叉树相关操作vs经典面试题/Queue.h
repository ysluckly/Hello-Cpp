#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


/**************************************************************
*						    链式队列						  *
***************************************************************/
typedef struct BinaryTreeNode* DataType;

typedef struct QueueNode
{
	DataType* data;
	struct QueueNode* pNext;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue;

//初始化
void QueueInit(Queue* pQueue);
//销毁
void QueueDestory(Queue* pQueue);

QueueNode* BuyNode(DataType x);
//入队
void QueuePush(Queue* pQueue, DataType x);
//出队
void QueuePop(Queue* pQueue);
//取队头元素
DataType QueueFront(Queue* pQueue);
//取队尾元素
DataType QueueBack(Queue* pQueue);
//判空
int QueueEmpty(Queue* pQueue);
//队的大小
int QueueSize(Queue* pQueue);
//测试
void testQueue();



#endif//__QUEUE_H__
