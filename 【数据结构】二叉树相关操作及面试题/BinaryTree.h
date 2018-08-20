#ifndef __BINARY_H__
#define __BINARY_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* pLeft;
	struct BinaryTreeNode* pRight;
}BTNode,*pBTNode;


///////////////////////////////二叉树经典相关操作////////////////////////////////

//创建二叉树
pBTNode BinaryTreeCreat(char* arr,int n,int* p);
//销毁二叉树
void BinaryTreeDestory(pBTNode* root);

//前中后递归遍历
void BinaryTreePrevSearch(pBTNode root);
void BinaryTreeMiddleSearch(pBTNode root);
void BinaryTreeLastSearch(pBTNode root);
void BinaryTreeLavelSearch(pBTNode root);

//前中后非递归遍历
void BinaryTreePrevSearch_OP(pBTNode root);
void BinaryTreeMiddleSearch_OP(pBTNode root);
void BinaryTreeLastSearch_OP(pBTNode root);

//二叉树的结点个数
int BinaryTreeNodeSize(pBTNode root);
//叶子结点个数
int BinaryTreeNodeLeaf(pBTNode root);
//二叉树深度
int BinaryTreeDepth(pBTNode root);
//二叉树第k层结点个数
int BinaryTreeNodeKLevel(pBTNode root,int k);
//判断一个结点是否在二叉树中
pBTNode BinaryTreeFind(pBTNode root,BTDataType x);
//判断一棵二叉树树是否是完全二叉树
bool BinaryTreeComplete(pBTNode root);


//获取一个结点双亲结点
pBTNode GetBinaryTreeNodeParent(pBTNode root);
//获取一个结点的左孩子结点
pBTNode GetBinaryTreeNodeLeftChild(pBTNode root);
//获取一个结点的右孩子结点
pBTNode GetBinaryTreeNodeRightChild(pBTNode root);

/////////////////////////////////二叉树经典面试题////////////////////////////////

//求二叉树的镜像(递归&非递归)
//判断一颗二叉树是否为完全二叉树（层次遍历变形）

void testBinaryTreeNode();

#endif //__BINARY_H__




