 
/////////////////////////////////////////////////////
 
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef char* BSTKeyType;
//typedef int BSTValueType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSTKeyType _key;
}BSTreeNode;

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType x);
int BSTreeRemove(BSTreeNode** ppTree, BSTKeyType x);
BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType x);

void BSTreeInOrder(BSTreeNode** ppTree);
void TestBSTree1();