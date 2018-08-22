#include "Heap.h"


//交换函数
static Swap(HDataType* x, HDataType* y)
{
	HDataType* tmp = *x;
	*x = *y;
	*y = tmp;
}

//因为【从最后一个分支开始，以当前结点为根节点向下调整】，所以叫做向下调整
static AdjustDown(HDataType* hhp, int size, int i) //参数：堆的地址，大小，当前分支节点
{
	assert(hhp);
	int parent = i;
	int leftchild = parent * 2 + 1;
	while (leftchild<size)
	{
		//选出左右孩子大的,前提右孩子存在
		if (((leftchild + 1) < size) && (hhp[leftchild] < hhp[leftchild + 1]))
			leftchild++;
		if (hhp[parent] < hhp[leftchild])
		{
			Swap(&hhp[parent], &hhp[leftchild]);
			//继续深探
			parent = leftchild;
			leftchild = parent * 2 + 1;
		}
		else
			break;
	}

}
//创建堆 【堆的第一个下标为0】  创建复杂度O(N)
void HeapInit(Heap* hp, HDataType* arr, int n)
{
	assert(hp&&arr);

	hp->data = (HDataType*)malloc(sizeof(HDataType)*n);
	hp->size = n;			
	hp->capacity = n;

	int i = 0;

	//二叉树的层次遍历序列[复制]
	for (i = 0; i < n; i++)
	{
		hp->data[i] = arr[i];
	}

	//【堆分为大堆小堆，此处实现的大堆】

	/*调堆：n为元素个数，先减1到最后叶子节点的下标，在减1除2到最后一个分支节点（即最后叶子节点的双亲结点）
	【从最后一个分支开始，以当前结点为根节点向下调整】，调整完毕后再调整前一个分支节点，
	 避免了从头到尾调整的不必要麻烦（每个节点可能会被调整好多次）*/
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		//因为【从最后一个分支开始，以当前结点为根节点向下调整】，所以叫做向下调整
		//hp->data数组为实际堆，数组名为堆的地址
		AdjustDown(hp->data, hp->size, i); //参数：堆的地址，大小，当前分支节点
	}


}
//销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	hp->capacity = hp->size = 0;
	free(hp->data);
	hp->data = NULL;
	printf("销毁成功\n");
}

//作为孩子结点【跟双亲比较大小】，叫做向上调整   0(log n)
static AdjustUp(HDataType* hhp, int size, int i)//参数：堆的地址，大小，当前节点(起初为最后一个叶子节点)
{
	assert(hhp);
	int parent = (i - 1) / 2;
	int child = i;
	while (child>0)
	{
		if (hhp[child]>hhp[parent])
		{
			Swap(&hhp[parent], &hhp[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}

}

//插入数据
void HeapPush(Heap* hp, HDataType x)
{
	assert(hp);
	if (hp->capacity == hp->size)
	{
		HDataType* tmp = (HDataType*)realloc(hp->data,sizeof(HDataType)*(hp->capacity + 5));
		assert(tmp);
		hp->data = tmp;
		hp->capacity += 5;
		printf("增容成功 当前容量%d  \n",hp->capacity);
	}
	hp->data[hp->size++] = x;
	
	//作为孩子结点【跟双亲比较大小】，叫做向上调整
	AdjustUp(hp->data, hp->size, hp->size - 1);//参数：堆的地址，大小，当前节点(起初为最后一个叶子节点)
}
//删除数据
void HeapPop(Heap* hp)
{
	assert(hp);
	//直接删头后就叫做神龙有尾无头，所以先将头与尾交换，尾出数组，在对头进行向下调整
	//交换首尾
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->data, hp->size, 0);

}
//堆顶元素
HDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->data[0];
}
//判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
//堆的大小
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

//打印
void HeapPrint(Heap* hp)
{
	int i = 0;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d  ",hp->data[i]);
	}
	printf("\n");
}
//测试
void testHeap()
{
	Heap heap;
	HDataType arr[] = { 43, 56, 2, 78, 9, 14, 52, 65, 87, 23 };
	HeapInit(&heap, arr, sizeof(arr) / sizeof(HDataType));

	HeapPrint(&heap);

	printf("堆的大小：%d\n",HeapSize(&heap));
	printf("堆顶元素：%d\n", HeapTop(&heap));
	printf("是否为空？ %d\n",HeapEmpty(&heap));

	HeapPush(&heap,99);
	HeapPrint(&heap);

	printf("堆的大小：%d\n", HeapSize(&heap));
	printf("堆顶元素：%d\n", HeapTop(&heap));
	printf("是否为空？ %d\n", HeapEmpty(&heap));

	HeapPop(&heap);
	HeapPrint(&heap);
	printf("堆的大小：%d\n", HeapSize(&heap));
	printf("堆顶元素：%d\n", HeapTop(&heap));
	printf("是否为空？ %d\n", HeapEmpty(&heap));

	HeapDestory(&heap);

}