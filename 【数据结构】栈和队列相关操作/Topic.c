#include "Topic.h"

//////////////// 1.要求实现Min(返回最小值)的时间复杂度为O(1)////////////////////
/*通过封装一个结构体，结构体中第一个元素放值，第二个元素放最小值，
将结构体放入到栈中，这样返回最小值的时候从栈顶取结构体，再从结构体中取出最小值*/


//栈的初始化
void MStackInit(MinStack* ms)
{
	assert(ms);
	StackInit(&ms->s);
}
//入栈
void MStackPush(MinStack* ms, MDataType data)
{
	assert(ms);
	SElem elem;
	//先把元素的值和最小值用data构造好
	elem.data = elem.mindata = data;
	if (!StackEmpty(&ms->s))
	{
		//取栈里面的最小值
		MDataType minData = GetMinData(ms);
		//若最小值比放入的数据小进行更新
		if (minData < data)
		{
			elem.mindata = minData;
		}
	}
	//将elem压栈
	StackPush(&ms->s, elem);
}

//出栈
void MStackpop(MinStack* ms)
{
	assert(ms);
	assert(!MStackEmpty(ms));
	StackPop(&ms->s);
}
//判断栈是否为空
int MStackEmpty(MinStack* ms)
{
	assert(ms);
	return StackEmpty(&ms->s);
}
//取栈顶元素
MDataType MStackTop(MinStack* ms)
{
	assert(ms);
	return StackTop(&ms->s).data;
}
//取栈的大小
MDataType MStackSize(MinStack* ms)
{
	assert(ms);
	return StackSize(&ms->s);
}
//取最小值
MDataType GetMinData(MinStack* ms)
{
	assert(ms);
	return StackTop(&ms->s).mindata;
}

///////////////////////////////2.两个栈实现队列////////////////////////////////
void QueueByTwoStackInit(QueueByTwoStack* qts)
{
	assert(qts);
	StackInit(&qts->s1);
	StackInit(&qts->s2);
}
void QueueByTwoStackDestory(QueueByTwoStack* qts)
{
	assert(qts);
	StackDestory(&qts->s1);
	StackDestory(&qts->s2);

}

// 栈s1入数据，s2出数据，
void QueueByTwoStackPush(QueueByTwoStack* qts, DataType x)
{
	assert(qts);
	StackPush(&qts->s1, x);

}
//s2出数据，如果有数据直接出，如果没有就从s1中把数据倒过来
void QueueByTwoStackPop(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2))
	{
		while (!StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
	StackPop(&qts->s2);

}
DataType QueueByTwoStackFront(QueueByTwoStack* qts)
{
	assert(qts);
	if (StackEmpty(&qts->s2))
	{
		while (!StackEmpty(&qts->s1))
		{
			StackPush(&qts->s2, StackTop(&qts->s1));
			StackPop(&qts->s1);
		}
	}
	return StackTop(&qts->s2);
}
int QueueByTwoStackEmpty(QueueByTwoStack* qts)
{
	assert(qts);
	return StackEmpty(&qts->s1)&StackEmpty(&qts->s2);
}
int QueueByTwoStackSize(QueueByTwoStack* qts)
{
	assert(qts);
	return StackSize(&qts->s1) + StackSize(&qts->s2);
}

void testQueueByTwoStack()
{
	QueueByTwoStack stq;
	QueueByTwoStackInit(&stq);
	QueueByTwoStackPush(&stq, 1);
	QueueByTwoStackPush(&stq, 2);
	QueueByTwoStackPush(&stq, 3);
	QueueByTwoStackPush(&stq, 4);
	QueueByTwoStackPop(&stq);

	QueueByTwoStackPush(&stq, 5);
	QueueByTwoStackPush(&stq, 6);
	QueueByTwoStackPush(&stq, 7);
	QueueByTwoStackPush(&stq, 8);

	printf("%d", QueueByTwoStackSize(&stq));

	while (!QueueByTwoStackEmpty(&stq))
	{
		printf("%d ", QueueByTwoStackFront(&stq));
		QueueByTwoStackPop(&stq);
	}
	QueueByTwoStackDestory(&stq);
}

///////////////////////////////3.两个队列实现栈////////////////////////////////

void StackByTwoQueueInit(StackByTwoQueue* stq)
{
	assert(stq);
	QueueInit(&stq->q1);
	QueueInit(&stq->q2);
}
void StackByTwoQueueDestory(StackByTwoQueue* stq)
{
	assert(stq);
	QueueDestory(&stq->q1);
	QueueDestory(&stq->q2);

}
//两个队列实现栈，开始入队时，q1空入q2，q2空入q1，非空队上插入数据，另一个队当出栈时的缓存区
void StackByTwoQueuePush(StackByTwoQueue* stq, DataType x)
{
	assert(stq);
	if (QueueEmpty(&stq->q1))
	{
		QueuePush(&stq->q2, x);
	}
	else
	{
		QueuePush(&stq->q1, x);
	}

}
//出栈时，将非空队列前n-1数据导入空队，将原非空队列第n个数据出队
void StackByTwoQueuePop(StackByTwoQueue* stq)
{
	assert(stq);
	Queue *empty = &stq->q1, *noempty = &stq->q2;
	if (!QueueEmpty(&stq->q1))
	{
		empty = &stq->q2;
		noempty = &stq->q1;
	}
	while (QueueSize(noempty) > 1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	QueuePop(noempty);

}
DataType StackByTwoQueueFront(StackByTwoQueue* stq)
{
	assert(stq);
	if (QueueEmpty(&stq->q1))
	{
		return QueueBack(&stq->q2);
	}
	else
		return QueueBack(&stq->q1);
}
int StackByTwoQueueEmpty(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueEmpty(&stq->q1)&QueueEmpty(&stq->q2);
}
int StackByTwoQueueSize(StackByTwoQueue* stq)
{
	assert(stq);
	return QueueSize(&stq->q1) + QueueSize(&stq->q2);
}

void testStackByTwoQueue()
{
	StackByTwoQueue stq;
	StackByTwoQueueInit(&stq);
	StackByTwoQueuePush(&stq, 1);
	StackByTwoQueuePush(&stq, 2);
	StackByTwoQueuePush(&stq, 3);
	StackByTwoQueuePush(&stq, 4);
	StackByTwoQueuePop(&stq);

	StackByTwoQueuePush(&stq, 5);
	StackByTwoQueuePush(&stq, 6);
	StackByTwoQueuePush(&stq, 7);
	StackByTwoQueuePush(&stq, 8);

	printf("%d     ", StackByTwoQueueSize(&stq));

	while (!StackByTwoQueueEmpty(&stq))
	{
		printf("%d ", StackByTwoQueueFront(&stq));
		StackByTwoQueuePop(&stq);
	}
	StackByTwoQueueDestory(&stq);
}

////////////////////////4.元素出栈，入栈的合法性。//////////////////////////
//如入栈的序列（1,2,3,4,5），出栈序列为（4,5,3,2,1） 
/*传入两个数组，一个是进入栈的序列另一个是出栈顺序，创建一个栈，将进入栈的序列依次
压入栈中,当进入序列和出栈序列的第一个元素相同时，弹出这个元素，同时出栈序列，向后
走，该元素已经成功出栈，此时若入栈序列还有元素继续重复上述操作，直到，最后一个元素
也入栈,这时栈中剩下的元素位置已经固定，只能从栈顶依次弹出，每次弹出前栈顶元素和弹出序列元
素比较若相等则继续弹出，同时弹出序列向后移动，一旦栈顶元素和弹出序列不相等，说明
弹出序列要弹出的元素不在栈顶,所以无法弹出，所以就是非法弹出，否则继续重复
上述操作，直到栈中的元素数目为0，即栈空，证明弹出序列合法*/

int Check(int *stack_in, int *stack_out, int len_in, int len_out)
{
	Stack s;
	StackInit(&s);
	assert(stack_in && stack_out);
	//两个序列长度不相等，不合法  
	if (len_in != len_out)
		return 0;
	
	int j = 0;
	int i = 0;
	for (; i < len_in; i++)
	{
		StackPush(&s, stack_in[i]);
		//入栈序列栈顶元素与当前出栈序列元素不相等，不合法  
		while (StackSize(&s) > 0 && StackTop(&s) == stack_out[j])
		{
			StackPop(&s);
			j++;
		}
	}

	//当所有出栈序列元素都匹配完之后，栈不为空，不合法
	return (StackSize(&s)>0) ? 0 : 1;
}


void testInWithOut()
{
	int stack_in[] = { 1, 2, 3, 4, 5 };       //入栈序列  
	int stack_out[] = { 4, 5, 3, 2, 1 };      //出栈序列  
	int len_in = sizeof(stack_in) / sizeof(stack_in[0]);      //入栈序列长度  
	int len_out = sizeof(stack_out) / sizeof(stack_out[0]);   //出栈序列长度  
	int ret = Check(stack_in, stack_out, len_in, len_out);
	if (ret == 1)
		printf("合法\n");
	else
		printf("不合法\n");

}


/////////////////////////5.一个数组实现两个栈（共享栈）/////////////////////////////

void SharedStackInit(SharedStack* s)
{
	s->top1 = 0;
	s->top2 = MAXSIZE - 1;
}

// 入栈 
void SharedStackPush(SharedStack* s, int data, int flag)
{
	if (s->top2 <= s->top1)
		return;

	if (1 == flag)
		s->data[s->top1++] = data;
	else
		s->data[s->top2--] = data;
}

// 出栈 
void SharedStackPop(SharedStack* s, int flag)
{
	if (SharedStackEmpty(s, flag))
		return;

	if (1 == flag)
		s->top1--;
	else
		s->top2++;
}

// 获取栈顶元素 
int SharedStackTop(SharedStack* s, int flag)
{
	assert(!SharedStackEmpty(s, flag));
	if (1 == flag)
		return s->data[s->top1 - 1];
	else
		return s->data[s->top2 + 1];
}

// 有效元素的个数 
int SharedStackSize(SharedStack* s, int flag)
{
	if (1 == flag)
		return s->top1;
	else
		return MAXSIZE - s->top2 - 1;
}

// 检测栈是否为空 
int SharedStackEmpty(SharedStack* s, int flag)
{
	if (1 == flag)
		return 0 == s->top1;
	else
		return MAXSIZE - 1 == s->top2;
}