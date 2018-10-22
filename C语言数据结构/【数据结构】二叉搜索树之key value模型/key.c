#define _CRT_SECURE_NO_WARNINGS 1

#include "key.h"


BSTreeNode* BuyBSTreeNode(BSTKeyType key)
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_key = (BSTKeyType)malloc(strlen(key) + 1);
	strcpy(node->_key, key);

	return node;
}

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key)
{
	BSTreeNode* cur, *parent = NULL;
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(key);
		return 1;
	}

	cur = *ppTree;
	while (cur)
	{
		if (strcmp(cur->_key, key) > 0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key) < 0)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return 0;
		}
	}

	if (strcmp(parent->_key, key) < 0)
	{
		parent->_right = BuyBSTreeNode(key);
	}
	else
	{
		parent->_left = BuyBSTreeNode(key);
	}

	return 1;
}

BSTreeNode* BSTreeFind(BSTreeNode** ppTree, BSTKeyType key)
{
	BSTreeNode* cur = *ppTree;
	while (cur)
	{
		if (strcmp(cur->_key, key) < 0)
		{
			cur = cur->_right;
		}
		else if (strcmp(cur->_key, key) > 0)
		{
			cur = cur->_left;
		}
		else
		{
			return cur;
		}
	}

	return NULL;
}

void BSTreeInOrder(BSTreeNode** ppTree)
{
	BSTreeNode* root = *ppTree;
	if (*ppTree == NULL)
	{
		return;
	}

	BSTreeInOrder(&root->_left);
	printf("%s:\n", root->_key);
	BSTreeInOrder(&root->_right);
}

void TestBSTree1()
{
	char str[10];
	BSTreeNode* pTree= NULL;
	BSTreeInsert(&pTree, "insert");
	BSTreeInsert(&pTree, "sort");
	BSTreeInsert(&pTree, "find");
	BSTreeInsert(&pTree, "tree");
	BSTreeInsert(&pTree, "destory");

	BSTreeInOrder(&pTree);

	while (1)
	{
		scanf("%s", str);
		if (BSTreeFind(&pTree, str))
		{
			printf("正确的单词\n");
		}
		else
		{
			printf("错误的单词\n");
		}
	}
}