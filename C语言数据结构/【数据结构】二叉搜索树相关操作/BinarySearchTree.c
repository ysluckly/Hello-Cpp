
#include "BinarySearchTree.h"

////////////////////////////////////////////////非递归/////////////////////////////////////

// 销毁
void Destroy(BSTNode** ppTree)
{
	assert(ppTree);
	if ((*ppTree))
	{
		Destroy(&(*ppTree)->pLeft);
		Destroy(&(*ppTree)->pRight);
		free((*ppTree));
		(*ppTree) = NULL;
	}
}
BSTNode* BuyNode(DataType x)
{
	BSTNode* tmp = (BSTNode*)malloc(sizeof(BSTNode));
	assert(tmp);
	tmp->data = x;
	tmp->pLeft = NULL;
	tmp->pRight = NULL;
	return tmp;
}
//插入
void BinarySearchTreeInsert(BSTNode** ppTree, DataType x)
{
	BSTNode* pCur = (*ppTree);
	BSTNode* pParent = NULL;

	assert(ppTree);
	if (*ppTree == NULL)
	{
		(*ppTree) = BuyNode(x);
		return;
	}
	
	 //查找
	while (pCur)
	{
		if (pCur->data > x)
		{
			pParent = pCur;
			pCur = pCur->pLeft;
		}					   
		else if (pCur->data<x)
		{
			pParent = pCur;
			pCur = pCur->pRight;

		}
		else
		{   //有相同返回
			return;
		}	
	}
	//插入
	if (pParent->data > x)
	{
		pParent->pLeft = BuyNode(x);
	}
	else
	{
		pParent->pRight = BuyNode(x);

	}
}
//查找
BSTNode* BinarySearchTreeFind(BSTNode** ppTree, DataType x)
{
	BSTNode* pCur = (*ppTree);

	assert(ppTree);
	if ((*ppTree) = NULL)
		return NULL;
	while (pCur)
	{
		if (pCur->data < x)
		{
			pCur = pCur->pRight;
		}
		else if (pCur->data > x)
		{
			pCur = pCur->pLeft;
		}
		else
			return pCur;
	}
}
//删除
int BinarySearchTreeRemove(BSTNode** ppTree, DataType x)
{
	BSTNode* pCur = (*ppTree);
	BSTNode* pParent = NULL;
	BSTNode* pDel = NULL;

	assert(ppTree);
	if ((*ppTree) == NULL)
		return -1;
	//查找
	while (pCur)
	{
		if (pCur->data > x)
		{
			pParent = pCur;
			pCur = pCur->pLeft;
		}
		else if (pCur->data < x)
		{
			pParent = pCur;
			pCur = pCur->pRight;
		}
		else
		{	//已找到
			break;
		}
	}
	if (pCur == NULL)
		return -1;
	if (pCur->pLeft== NULL)
	{
		pDel = pCur;
		if (pParent == NULL)
		{
			(*ppTree) = pCur->pRight;
		}
		else
		{
			if (pParent->pLeft == pCur)
			{
				pParent->pLeft = pCur->pRight;

			}
			else
			{
				pParent->pRight = pCur->pRight;
			}
		}
		free(pDel);
		pDel = NULL;
	}
	else if (pCur->pRight == NULL)
	{
		pDel = pCur;
		if (pParent == NULL)
			(*ppTree) = pCur->pLeft;
		else
		{
			if (pParent->pLeft == pCur)
			{
				pParent->pLeft = pCur->pLeft;
			}
			else
			{
				pParent->pRight = pCur->pLeft;
			}
		}
		free(pDel);
		pDel = NULL;
	}
	else
	{
		BSTNode* replace = pCur->pRight;
		while (replace->pLeft)
		{
			pParent = replace;
			replace = replace->pLeft;
		}
		pCur->data = replace->data;
		if (pParent->pLeft == replace)
			pParent->pLeft = replace->pRight;
		else
			pParent->pRight = replace->pRight;

		free(replace);
		replace = NULL;
	}
	return 1;
}

////////////////////////////////////////////////递归/////////////////////////////////////
//插入
void BinarySearchTreeInsert_OP(BSTNode** ppTree, DataType x)
{
	assert(ppTree);
	if (*ppTree == NULL)
	{
		(*ppTree) = BuyNode(x);
		return;

	}
	if ((*ppTree)->data > x)
		BinarySearchTreeInsert_OP(&(*ppTree)->pLeft, x);
	else if ((*ppTree)->data < x)
		BinarySearchTreeInsert_OP(&(*ppTree)->pRight, x);
	else
	{
		printf("插入失败\n");
		return;
	}
		
}
//查找
BSTNode* BinarySearchTreeFind_OP(BSTNode** ppTree, DataType x)
{
	assert(ppTree);
	if (*ppTree == NULL)
	{
		return NULL;

	}
	if ((*ppTree)->data > x)
		return BinarySearchTreeFind_OP(&(*ppTree)->pLeft, x);
	else if ((*ppTree)->data < x)
		return BinarySearchTreeFind_OP(&(*ppTree)->pRight, x);
	else
	{
		return (*ppTree);
	}
}
//删除
int BinarySearchTreeRemove_OP(BSTNode** ppTree, DataType x)
{
	assert(ppTree);
	if (*ppTree == NULL)
		return -1;
	if ((*ppTree)->data < x)
		return BinarySearchTreeRemove_OP(&(*ppTree)->pRight, x);
	else if ((*ppTree)->data >x)
		return BinarySearchTreeRemove_OP(&(*ppTree)->pLeft,x);
	else
	{
		
		BSTNode* pCur = (*ppTree);//(*pptree)为指向被删节点与双亲节点的路径的指针
		if (pCur->pLeft == NULL)
		{
			(*ppTree) = pCur->pRight;
			free(pCur);
			pCur = NULL;
		}
		else if (pCur->pRight == NULL)
		{
			(*ppTree) = pCur->pLeft;
			free(pCur);
			pCur = NULL;

		}
		else
		{
			BSTNode* replace = pCur->pRight;
			while (replace->pLeft)
			{
				replace = replace->pLeft;
			}
			pCur->data = replace->data;
			return BinarySearchTreeRemove_OP(&pCur->pRight,replace->data);

		}
	}
}

//层比编
void Level(BSTNode** ppTree)
{
	assert(ppTree);
	if ((*ppTree) == NULL)
		return;
	Level(&(*ppTree)->pLeft);
	printf("%d  ",(*ppTree)->data);
	Level(&(*ppTree)->pRight);

}
//////////////////////////////////// //////典型应用/////////////////////////////////////
//key模型
//key/value模型


void testBinarySearchTree()
{
	int i = 0;
	BSTNode* ret = NULL;
	BSTNode* pTree = NULL;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (; i < sizeof(a) / sizeof(int); ++i)
	{
		BinarySearchTreeInsert(&pTree, a[i]);
	}
	Level(&pTree);
	printf("\n");
	ret = BinarySearchTreeFind_OP(&pTree, 9);
	if (ret)
		printf("成功\n");
	BinarySearchTreeRemove(&pTree,0);
	Level(&pTree);
	printf("\n");
	BinarySearchTreeRemove(&pTree, 1);
	Level(&pTree);
	printf("\n");
	BinarySearchTreeRemove(&pTree, 2);
	Level(&pTree);
	printf("\n");
	BinarySearchTreeRemove(&pTree, 3);
	Level(&pTree);
	printf("\n");	
	BinarySearchTreeRemove(&pTree, 4);
	Level(&pTree);
	printf("\n");
	BinarySearchTreeRemove(&pTree, 5);
	Level(&pTree);
	printf("\n");
	BinarySearchTreeRemove(&pTree, 6);
	Level(&pTree);
	printf("\n");
	BinarySearchTreeRemove(&pTree, 7);
	Level(&pTree);
	printf("\n");

	Destroy(&pTree);

}
