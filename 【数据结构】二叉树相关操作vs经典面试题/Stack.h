#ifndef __STACK_H__
#define __STACK_H__
/**************************************************************
*                         动态顺序栈						  *
***************************************************************/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTreeNode* SDataType;
typedef struct Stack
{
	SDataType* data;
	int top;
	int capacity;
}Stack;

//初始化
void StackInit(Stack* pStack);
//销毁
void StackDestory(Stack* pStack);

//入栈
void StackPush(Stack* pStack, SDataType x);
//出栈
void StackPop(Stack* pStack);
//取栈顶元素
SDataType StackTop(Stack* pStack);
//判空
int StackEmpty(Stack* pStack);
//栈的大小
int StackSize(Stack* pStack);
//测试
void testStack();
 

#endif //__STACK_H__
