#define _CRT_SECURE_NO_WARNINGS 1

#include "BinarySearchApply.h"

/*
void TestBSTree1() {
	BSTreeNode* tree = NULL;

	BSTreeInsertR(&tree, "tree", "Ê÷");
	BSTreeInsertR(&tree, "sort", "ÅÅÐò");
	BSTreeInsertR(&tree, "binary", "¶þ·Ö");
	BSTreeInsertR(&tree, "return", "·µ»Ø");
	BSTreeInsertR(&tree, "hash", "¹þÏ£");
	BSTreeInsertR(&tree, "list", "Á´±í");

	printf("%s\n", BSTreeFindR(tree, "tree")->_value);
	printf("%s\n", BSTreeFindR(tree, "return")->_value);
	printf("%s\n", BSTreeFindR(tree, "hash")->_value);
	printf("%s\n", BSTreeFindR(tree, "list")->_value);
	printf("lit:   %p\n", BSTreeFindR(tree, "lit"));
	printf("list:  %p\n", BSTreeFindR(tree, "list"));
	BSTreeRemoveR(&tree, "list");
	printf("list:  %p\n", BSTreeFindR(tree, "list"));
	CheckWord(tree, "tree");
	CheckWord(tree, "hash");
	CheckWord(tree, "list");
	CheckWord(tree, "asdsd");

} */

void TestBSTreeISP() {
	BSTreeNode* tree = NULL;

	BSTreeInsertR(&tree, "102.100.01");
	BSTreeInsertR(&tree, "102.100.12");
	BSTreeInsertR(&tree, "102.100.01");
	BSTreeInsertR(&tree, "102.100.35");
	BSTreeInsertR(&tree, "102.100.65");
	BSTreeInsertR(&tree, "102.100.35");
	BSTreeInsertR(&tree, "102.100.35");
	printf("102.100.01  %d\n", BSTreeFindR(tree, "102.100.01")->_value);
	printf("102.100.12  %d\n", BSTreeFindR(tree, "102.100.12")->_value);
	printf("102.100.35  %d\n", BSTreeFindR(tree, "102.100.35")->_value);
	printf("102.100.65  %d\n", BSTreeFindR(tree, "102.100.65")->_value);

	printf("01:   %p\n", BSTreeFindR(tree, "102.100.01"));
	printf("102.100.65:  %p\n", BSTreeFindR(tree, "102.100.65"));
	BSTreeRemoveR(&tree, "102.100.65");
	printf("102.100.65:  %p\n", BSTreeFindR(tree, "102.100.65"));
}
int main()
{
	//TestBSTree1();
	TestBSTreeISP();
	system("pause");
	return 0;
}

