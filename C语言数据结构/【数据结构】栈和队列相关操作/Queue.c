#include "Queue.h"

//有头结点的队列
/*//初始化
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pNode = (DataType*)malloc(sizeof(DataType));//头结点
	pNode->pNext = NULL;
	pQueue->front = pQueue->rear = pNode;
}
//销毁
void QueueDestory(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front->pNext;
	while (pCur)
	{
		QueueNode* pDel = pCur;
		pQueue->front->pNext = pDel->pNext;
		free(pDel);
		pDel = NULL;
		pCur = pQueue->front->pNext;
	}
	free(pQueue->front);
	pQueue->front = NULL;

}

QueueNode* BuyNode(DataType x)
{
	QueueNode* ptr = (DataType*)malloc(sizeof(DataType));
	assert(ptr);
	ptr->data = x;
	ptr->pNext = NULL;
	return ptr;
}
//入队
void QueuePush(Queue* pQueue, DataType x)
{
	assert(pQueue);
	QueueNode* back = BuyNode(x);
	pQueue->rear->pNext = back;
	pQueue->rear = back;

}
//出队
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pDel = pQueue->front->pNext;
	pQueue->front->pNext = pDel->pNext;
	
	if (pDel == pQueue->rear)
	{
		pQueue->rear = pQueue->front;
	}
	free(pDel);
	pDel = NULL;

}
//取队头元素
DataType QueueTop(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front->pNext->data;

}
//判空
int QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front->pNext == NULL;;

}
//队的大小
int QueueSize(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front->pNext;
	int len = 0;
	while (pCur)
	{
		len++;
		pCur = pCur->pNext;

	}
	return len;

}*/


///////////////////////////////无头结点/////////////////////////////
//初始化
void QueueInit(Queue* pQueue)
{
	assert(pQueue);
	pQueue->front = NULL;
	pQueue->rear = NULL;
}

//销毁
void QueueDestory(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front;
	while (pCur)
	{
		QueueNode* next = pCur->pNext;
		free(pCur);
		pCur = next;
	}
	pQueue->front = pQueue->rear = NULL;
}

QueueNode* BuyNode(DataType x)
{
	QueueNode* ptr = (QueueNode*)malloc(sizeof(QueueNode));
	assert(ptr);
	ptr->data = x;
	ptr->pNext = NULL;
	return ptr;
}

//入队
void QueuePush(Queue* pQueue, DataType x)
{
	assert(pQueue);
	if (pQueue->rear == NULL)
	{
		QueueNode* node = BuyNode(x);
		 pQueue->rear = node;
		 pQueue->front = pQueue->rear;
	}
	else
	{
		QueueNode* node = BuyNode(x);
		pQueue->rear->pNext = node;
		pQueue->rear = node;
	}
}

//出队
void QueuePop(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front->pNext;
	free(pQueue->front);
	pQueue->front = pCur;

	if (pCur == NULL)
	{
		pQueue->rear = NULL;
	}

}

//取队头元素
DataType QueueFront(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front->data;
}

//取队尾元素
DataType QueueBack(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->rear->data;

}

//判空
int QueueEmpty(Queue* pQueue)
{
	assert(pQueue);
	return pQueue->front == NULL;
}

//队的大小
int QueueSize(Queue* pQueue)
{
	assert(pQueue);
	QueueNode* pCur = pQueue->front;
	int len = 0;
	while (pCur)
	{
		len++;
		pCur = pCur->pNext;
	}
	return len;
}


//测试
void testQueue()
{
	Queue q;

	QueueInit(&q);
	QueuePush(&q, 5);
	QueuePush(&q, 4);
	QueuePush(&q, 3);
	QueuePush(&q, 2);

	printf("队列的大小：%d\n",QueueSize(&q));
	printf("队首元素：%d\n", QueueFront(&q));


	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestory(&q);
}

