#ifndef __TOPIC_H__
#define __TOPIC_H__

#include "Stack.h"
#include "Queue.h"

/******************************************************************************
*                           栈与队列相关面试题                               *
*******************************************************************************/

///////////////////////////////////////////////////////////////////////
//1.实现一个栈，要求实现Push(出栈)、pop(入栈)、Min(返回最小值)的时间复杂度为O(1)


typedef int MDataType;
//结构体，第一个元素放值，第二个元素放最小值
typedef struct SElem
{
	MDataType data;
	MDataType mindata;
}SElem;//栈里放的元素为结构体SElem

typedef struct MinStack
{
	Stack s;
}MinStack;

//初始化
void MStackInit(MinStack* ms);
//入栈
void MStackPush(MinStack* ms, MDataType data);
//出栈
void MStackpop(MinStack* ms);
//判断栈是否为空
int MStackEmpty(MinStack* ms);
//取栈顶元素
MDataType MStackTop(MinStack* ms);
//取出最小的元素
MDataType GetMinData(MinStack* ms);
//栈的大小
MDataType MStackSize(MinStack* ms);


///////////////////////////////////////////////////////////////////////
//2.两个栈实现一个队列
typedef struct  QueueByTwoStack
{
	Stack s1;
	Stack s2;
}QueueByTwoStack;

void QueueByTwoStackInit(QueueByTwoStack* qts);
void QueueByTwoStackDestory(QueueByTwoStack* qts);

void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x);
void QueueByTwoStackPop(QueueByTwoStack* qts);
DataType QueueByTwoStackFront(QueueByTwoStack* qts);
int QueueByTwoStackEmpty(QueueByTwoStack* qts);
int QueueByTwoStackSize(QueueByTwoStack* qts);
void testQueueByTwoStack();

///////////////////////////////////////////////////////////////////////
//3.两个队列实现一个栈
typedef struct  StackByTwoQueue
{
	Queue q1;
	Queue q2;
}StackByTwoQueue;

void StackByTwoQueueInit(StackByTwoQueue* stq);
void StackByTwoQueueDestory(StackByTwoQueue* stq);
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x);
void StackByTwoQueuePop(StackByTwoQueue* stq);
DataType StackByTwoQueueFront(StackByTwoQueue* stq);
int StackByTwoQueueEmpty(StackByTwoQueue* stq);
int StackByTwoQueueSize(StackByTwoQueue* stq);

void testStackByTwoQueue();


///////////////////////////////////////////////////////////////////////
// 4.元素出栈，入栈的合法性。如入栈的序列（1,2,3,4,5），出栈序列为（4,5,3,2,1）
int Check(int *stack_in, int *stack_out, int len_in, int len_out);
void testInWithOut();

 
///////////////////////////////////////////////////////////////////////
// 5.一个数组实现两个栈（共享栈）

#define MAXSIZE 10
//利用数组实现一个共享栈，第一个栈是从前往后入栈，第二栈的元素从后往前放
typedef struct SharedStack
{
	int data[MAXSIZE];
	int top1;	  //左栈顶
	int top2;	  //右栈顶
}SharedStack;

//flag为判断区分两个栈 ，规定1为左栈，0为右栈

void SharedStackInit(SharedStack* s);

// 入栈 
void SharedStackPush(SharedStack* s, int data, int flag);
// 出栈 
void SharedStackPop(SharedStack* s, int flag);
// 获取栈顶元素 
int SharedStackTop(SharedStack* s, int flag);
// 有效元素的个数 
int SharedStackSize(SharedStack* s, int flag);
// 检测栈是否为空 
int SharedStackEmpty(SharedStack* s, int flag);

#endif // __TOPIC_H__