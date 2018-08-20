
#include "BinaryTree.h"

///////////////////////////////二叉树经典相关操作////////////////////////////////

static pBTNode BBuyNode(BTDataType x)
{
	pBTNode node = (pBTNode)malloc(sizeof(BTNode));
	assert(node);
	node->pLeft = NULL;
	node->data = x;
	node->pRight = NULL;
	return node;
}
//创建二叉树
pBTNode BinaryTreeCreat(char* arr, int n, int* p)
{
	if ((arr[*p] != '#') && ((*p) < n))
	{
		pBTNode root = BBuyNode(arr[(*p)]);
		++(*p);
		root->pLeft = BinaryTreeCreat(arr, n, p);
		++(*p);									 
		root->pRight = BinaryTreeCreat(arr, n, p);
		return root;
	}
	else
	{
		return NULL;
	}
}
//销毁二叉树
void BinaryTreeDestory(pBTNode* root)
{
	pBTNode pCur = (*root);
	
	if (pCur)
	{
		BinaryTreeDestory(&pCur->pLeft);
		BinaryTreeDestory(&pCur->pRight);
		free(pCur);
		pCur = NULL;
	}

}

//前中后递归遍历
void BinaryTreePrevSearch(pBTNode root)
{
	if (root == NULL)
		return;
	printf("%c  ",root->data);
	BinaryTreePrevSearch(root->pLeft);
	BinaryTreePrevSearch(root->pRight);
}
void BinaryTreeMiddleSearch(pBTNode root)
{
	if (root == NULL)
		return;
	BinaryTreePrevSearch(root->pLeft);
	printf("%c  ", root->data);
	BinaryTreePrevSearch(root->pRight);
}
void BinaryTreeLastSearch(pBTNode root)
{
	if (root == NULL)
		return;
	BinaryTreePrevSearch(root->pLeft);
	BinaryTreePrevSearch(root->pRight);
	printf("%c  ", root->data);

}

//层序遍历
void BinaryTreeLevelSearch(pBTNode root)
{
	Queue q;
	if (root == NULL)
	{
		return;
	}
	QueueInit(&q);
	
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		pBTNode front = QueueFront(&q);
		printf("%c ",front->data);
		QueuePop(&q);
		if (front->pLeft)
		{
			QueuePush(&q,front->pLeft);
		}
		if (front->pRight)
		{
			QueuePush(&q,front->pRight);
		}
	}
	printf("\n");
}

//前中后非递归遍历
void BinaryTreePrevSearch_OP(pBTNode root);
void BinaryTreeMiddleSearch_OP(pBTNode root);
void BinaryTreeLastSearch_OP(pBTNode root);

//二叉树的结点个数
int BinaryTreeNodeSize(pBTNode root)
{
	if (root == NULL)
		return 0;
	return	BinaryTreeNodeSize(root->pLeft)
		+ BinaryTreeNodeSize(root->pRight) + 1;
}
//叶子结点个数
int BinaryTreeNodeLeaf(pBTNode root)
{
	if (root == NULL)
	{
		return 0;
	}
	if ((root->pLeft == NULL) && (root->pRight == NULL))
		return 1;
	return BinaryTreeNodeLeaf(root->pLeft)
		+ BinaryTreeNodeLeaf(root->pRight);
}
//二叉树深度
int BinaryTreeDepth(pBTNode root)
{
	if (root == NULL)
		return 0;
	int left = BinaryTreeDepth(root->pLeft);
	int right = BinaryTreeDepth(root->pRight);

	return (left>right) ? (left+1) : (right+1);
}
//二叉树第k层结点个数
int BinaryTreeNodeKLevel(pBTNode root, int k)
{												 
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeNodeKLevel(root->pLeft, k - 1)
		+ BinaryTreeNodeKLevel(root->pRight, k - 1);
}
//判断一个结点是否在二叉树中
pBTNode BinaryTreeFind(pBTNode root, BTDataType x)
{
	pBTNode ret;
	if (root == NULL || root->data == x)
		return root;
	ret = BinaryTreeFind(root->pLeft,x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->pRight,x);
	if (ret)
		return ret;
	return NULL;

}

//判断一棵二叉树树是否是完全二叉树
bool BinaryTreeComplete(pBTNode root)
{
	
	Queue q;

	if (root == NULL)
		return true;
	QueueInit(&q);

	QueuePush(&q,root);
	while (!QueueEmpty(&q))
	{
		pBTNode tmp = QueueFront(&q);
		QueuePop(&q);

		/*if (tmp->pLeft&&tmp->pRight)
		{
			QueuePop(&q);
			QueuePush(&q, tmp->pLeft);
			QueuePush(&q, tmp->pRight);
		}
		else if(tmp->pLeft)
		{
			if (tmp->pLeft->pLeft || tmp->pLeft->pRight)
				return false;
			QueuePop(&q);
			QueuePush(&q,tmp->pLeft);
		}
		else if (tmp->pRight)
		{
			return false;
		} */
		if (tmp == NULL)
		{
			while (!QueueEmpty(&q))
			{
				QueuePop(&q);
				if (QueueFront(&q))
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			QueuePush(&q,tmp->pLeft);
			QueuePush(&q, tmp->pRight);
		}
	}
	return true;
}
//获取一个结点双亲结点
pBTNode GetBinaryTreeNodeParent(pBTNode root,BTDataType x)
{
	pBTNode ret;
	if (root == NULL)
		return NULL;
	if (root->pLeft->data == x|| root->pRight->data == x)
		return root;
	ret = GetBinaryTreeNodeParent(root->pLeft, x);
	if (ret)
		return ret;
	ret = GetBinaryTreeNodeParent(root->pRight, x);
	if (ret)
		return ret;
	return NULL;
	
}
//获取一个结点的左孩子结点
pBTNode GetBinaryTreeNodeLeftChild(pBTNode root)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->pLeft)
		return root->pLeft;
}
//获取一个结点的右孩子结点
pBTNode GetBinaryTreeNodeRightChild(pBTNode root)
{

	if (root == NULL)
	{
		return NULL;
	}
	if (root->pRight)
		return root->pRight;
}

void testBinaryTreeNode()
{
	int i = 0;
	char arr[] = { 'A', 'B', 'D', '#', '#', '#', 'C', 'E', '#','#', 'O', '#', '#' };
	//防止在下一个栈桢销毁时，字符个数不移动，某个字符会重复新建结点，所以应该用址传递&i
	pBTNode root = BinaryTreeCreat(arr, sizeof(arr) / sizeof(char), &i);
	pBTNode tmp = NULL,Pret=NULL;
	bool ret;

	//递归遍历
	BinaryTreePrevSearch(root);
	printf("\n");
	BinaryTreeMiddleSearch(root);
	printf("\n");
	BinaryTreeLastSearch(root);
	printf("\n");
	BinaryTreeLevelSearch(root);
	printf("\n");


	printf("二叉树结点个数：%d\n",BinaryTreeNodeSize(root));
	printf("二叉树叶子节点个数：%d\n", BinaryTreeNodeLeaf(root));
	printf("二叉树第k层结点数：%d\n", BinaryTreeNodeKLevel(root,3));
	printf("二叉树深度：%d\n", BinaryTreeDepth(root));

	tmp = BinaryTreeFind(root, 'A');
	if (tmp)
		printf("%c\n ", tmp->data);
	else
		printf("不存在\n");
	
	ret = BinaryTreeComplete(root);
	if (ret == false)
		printf("no Complete!\n");
	else
		printf("yes ！\n");

	Pret = GetBinaryTreeNodeParent(root, 'B');
	if (Pret)
		printf("%c \n", Pret->data);
	else
		printf("不存在\n");

	Pret = GetBinaryTreeNodeParent(root, 'A');
	if (Pret)
		printf("%c \n", Pret->data);
	else
		printf("不存在\n");

	//对树进行查找，遍历应该值传递
	//对树进行改变应该址传递
	BinaryTreeDestory(&root);
}