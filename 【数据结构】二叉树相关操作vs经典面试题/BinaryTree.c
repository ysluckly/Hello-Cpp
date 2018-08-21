
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
//先访问每个结点（pCur&&pCur->pLeft）在压栈，，然后将右子树看成小型二叉树进行相同操作
void BinaryTreePrevSearch_OP(pBTNode root)
{
	Stack s;
	BTNode* pCur = root;
	StackInit(&s);

	if (root == NULL)
		return;
	//当前指针不为空或者栈不为空就应该继续
	while (pCur||!StackEmpty(&s))
	{
		while (pCur)
		{
			printf("%c ",pCur->data);
			StackPush(&s,pCur);
			pCur = pCur->pLeft;
		}
		pBTNode top = StackTop(&s);
		StackPop(&s);
		pCur = top->pRight;

	}
	
}
//每个结点（pCur&&pCur->pLeft）先压栈再访问，然后将右子树看成小型二叉树进行相同操作
void BinaryTreeMiddleSearch_OP(pBTNode root)
{
	Stack s;
	SatckInit(&s);

	pBTNode pCur = root;
	if (root == NULL)
		return;
	//当前指针不为空或者栈不为空就应该继续
	while (pCur || !StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->pLeft;
		}
		pBTNode top = StackTop(&s);
		printf("%c   ",top->data);
		StackPop(&s);
		pCur = top->pRight;
	}
}
//当根节点存在，先使根节点入栈，若存在左子树，使左子树入栈，直到左子树的左子树为空停止；
//此时取栈顶top元素，判断栈顶元素的右子树top->right是否为空，若为空直接打印栈顶元素；
//若不为空,再以右子树为根节点继续上述判断(入栈，取栈顶等)；
//（此处假设top->right无左右子树）那么此节点会先入栈；
//入栈完毕后得知它的左子树为空，当即会判断右子树，右子树为空，打印栈顶元素，出栈。
//此时到达栈顶top，即打印top；但是应该加一个打印判断条件(top->right == ?),这个？就是top右子树；
//综上：在每次打印完毕后，将此节点用pre标记起来，即满足top->tight == pre即可！！！
//），的的pre记录上次栈顶的位置，
void BinaryTreeLastSearch_OP(pBTNode root)
{
	Stack s;
	pBTNode pCur = root;
	StackInit(&s);
	if (root == NULL)
		return;
	//当前指针不为空或者栈不为空就应该继续
	while (pCur || !StackEmpty(&s))
	{
		while (pCur)
		{
			StackPush(&s, pCur);
			pCur = pCur->pLeft;
		}

		pBTNode tmp = StackTop(&s);
		pBTNode pre = NULL;

		if (tmp->pRight == NULL||tmp->pRight == pre)
		{
			printf("%c ",tmp);
			StackPop(&s);
			pre = tmp;
		}
		else
		{
			pCur = tmp->pRight;

		}
	}
}

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
}
//获取一个结点双亲结点
pBTNode GetBinaryTreeNodeParent(pBTNode root,BTDataType x)
{
	pBTNode ret;
	if (root == NULL)
		return NULL;
	if (root->pLeft)
	{
		if (root->pLeft->data == x)
			return root;

	}
	if (root->pRight)
	{
		if (root->pRight->data == x)
			return root;

	}
	ret = GetBinaryTreeNodeParent(root->pLeft, x);
	if (ret)
		return ret;
	ret = GetBinaryTreeNodeParent(root->pRight, x);
	if (ret)
		return ret;
	return NULL;
	
}
//获取一个结点的左孩子结点
pBTNode GetBinaryTreeNodeLeftChild(pBTNode root, BTDataType x)
{
	pBTNode ret = NULL;

	if (root == NULL)
	{
		return NULL;
	}
	ret = BinaryTreeFind(root,x);
	if (ret->pLeft)
		return ret->pLeft;
}
//获取一个结点的右孩子结点
pBTNode GetBinaryTreeNodeRightChild(pBTNode root, BTDataType x)
{

	pBTNode ret = NULL;

	if (root == NULL)
	{
		return NULL;
	}
	ret = BinaryTreeFind(root, x);
	if (ret->pRight)
		return ret->pRight;
}

//求二叉树的镜像(递归&非递归)
void BinaryTreeMirror(pBTNode root)
{
	if (NULL == root)
		return;
	if (root->pLeft == NULL&&root->pRight == NULL)
		return;
	pBTNode tmp = root->pLeft;
	root->pLeft = root->pRight;
	root->pRight = tmp;

	if (root->pLeft)
		BinaryTreeMirror(root->pLeft);
	if (root->pRight)
		BinaryTreeMirror(root->pRight);
}
void BinaryTreeMirror_OP(pBTNode root)
{

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
		printf("双亲结点 %c \n", Pret->data);
	else
		printf("不存在\n");

	Pret = GetBinaryTreeNodeParent(root, 'A');
	if (Pret)
		printf("双亲结点  %c \n", Pret->data);
	else
		printf("不存在\n");

	Pret = GetBinaryTreeNodeParent(root, 'E');
	if (Pret)
		printf("双亲结点  %c \n", Pret->data);
	else
		printf("不存在\n");

	Pret = GetBinaryTreeNodeRightChild(root,'C');
	if (Pret)
		printf("右结点  %c \n", Pret->data);
	else
		printf("不存在\n");

	//对树进行查找，遍历应该值传递
	//对树进行改变应该址传递
	BinaryTreeDestory(&root);
}