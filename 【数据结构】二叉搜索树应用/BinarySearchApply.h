#ifndef __APPLY_H__
#define __APPLY_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//1. 判断一个单词是否拼写正确
//2. 请模拟实现一个简单的中英互译的字典
/*
typedef char* KeyType;
typedef char* ValueType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	KeyType _key;
	ValueType _value;
}BSTreeNode;

BSTreeNode* BuyBSTreeNode(KeyType key, ValueType value);
int BSTreeInsertR(BSTreeNode** tree, KeyType key, ValueType value);
BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key);
int BSTreeRemoveR(BSTreeNode** tree, KeyType key);
void CheckWord(BSTreeNode** tree, KeyType key);
 */ 



//3. log文件中有许多异常重复的IP地址，请统计出每个异常IP出现了多少次？
typedef char* KeyType;
typedef int ValueType; //存放重复出现的次数

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	KeyType _key;
	ValueType _value;
}BSTreeNode;
BSTreeNode* BuyBSTreeNode(KeyType key);
int BSTreeInsertR(BSTreeNode** tree, KeyType key);
BSTreeNode* BSTreeFindR(BSTreeNode* tree, KeyType key);
int BSTreeRemoveR(BSTreeNode** tree, KeyType key);
#endif  //__APPLY_H__