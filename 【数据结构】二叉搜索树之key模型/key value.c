#define _CRT_SECURE_NO_WARNINGS 1

#include "key value.h"

BSTreeNode* BuyBSTreeNode(BSTKeyType key, BSTValueType value)
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	node->_left = NULL;
	node->_right = NULL;
	node->_key = (BSTKeyType)malloc(strlen(key) + 1);
	strcpy(node->_key, key);
	node->_value = value;

	return node;
}

int BSTreeInsert(BSTreeNode** ppTree, BSTKeyType key, BSTValueType value)
{
	BSTreeNode* cur, *parent=NULL;
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(key, value);
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
		parent->_right = BuyBSTreeNode(key, value);
	}
	else
	{
		parent->_left = BuyBSTreeNode(key, value);
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
	printf("%s:%d\n", root->_key, root->_value);
	BSTreeInOrder(&root->_right);
}
void TestBSTree1()
{
	char str[10] = { '0' };
	BSTreeNode* pTree = NULL;
	while (1)
	{
		BSTreeNode* node;
		scanf("%s", str);
		if (strcmp(str, "exit") == 0)
		{
			break;
		}

		node = BSTreeFind(&pTree, str);
		if (node)
		{
			node->_value++;
		}
		else
		{
			BSTreeInsert(&pTree, str, 1);
		}
	}

	BSTreeInOrder(&pTree);
}