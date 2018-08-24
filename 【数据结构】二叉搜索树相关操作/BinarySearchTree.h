#ifndef __BST_H__
#define __BST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct BinarySearchTreeNode
{
	DataType data;
	struct BinarySearchTreeNode* pLeft;
	struct BinarySearchTreeNode* pRight;
}BSTNode;

////////////////////////////////////////////////非递归/////////////////////////////////////
//插入
void BinarySearchTreeInsert(BSTNode** ppTree,DataType x);
//查找
BSTNode* BinarySearchTreeFind(BSTNode** ppTree,DataType x);
//删除
int BinarySearchTreeRemove(BSTNode** ppTree, DataType x);

// 销毁
void Destroy(BSTNode** ppTree);

////////////////////////////////////////////////递归/////////////////////////////////////
//插入
void BinarySearchTreeInsert_OP(BSTNode** ppTree, DataType x);
//查找
BSTNode* BinarySearchTreeFind_OP(BSTNode** ppTree, DataType x);
//删除
int BinarySearchTreeRemove_OP(BSTNode** ppTree, DataType x);

//层比编
void Level(BSTNode** ppTree);
//测试
void testBinarySearchTree();
//////////////////////////////////// //////典型应用/////////////////////////////////////
//key模型
//key/value模型
#endif //__BST_H__