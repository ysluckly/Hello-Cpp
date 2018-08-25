#include "HashTable.h"


//初始化
void HashInit(HashTable* ht, int len)
{
	int i = 0;
	assert(ht&&len > 0);
	ht->data = (HashData*)malloc(sizeof(HashData)*len);
	if (ht->data == NULL)
	{
		perror("not to creat table");

	}
	//初始化数据状态
	ht->lenth = len;
	ht->size = 0;
	for (; i < ht->lenth; i++)
	{
		ht->data[i].state = EMPTY;
	}
}
//销毁
void HashDestroy(HashTable* ht)
{		
	assert(ht);
	ht->lenth = ht->size = 0;
	free(ht->data);
	ht->data = NULL;
}


//获得插入位置
int  GetPosition(HashTable* ht, KeyType key)
{
	assert(ht);
	return key%ht->lenth;

}
//容量
static void CheckCapacity(HashTable* ht)
{
	assert(ht);
	//思想：新建一个比原来大二倍的数组，将数据移到新表，销毁旧表,更新指针
	HashTable hht;
	int len = ht->lenth * 2;
	
	//比较负载因子，一般要求控制0.7-0.8之间，此处控制0.7之内
	if (ht->size * 10 / ht->lenth > 7)
	{
		int j = 0;
		HashInit(&hht, len);
		for (j = 0; j < ht->lenth; j++)
		{
			if (ht->data[j].state == EXIST)
			{
				HashInsert(&hht, ht->data[j].key, ht->data[j].value);

			}
		}

		//销毁表，更新指针
		free(ht->data);
		ht->data = hht.data;
		ht->lenth = hht.lenth;
		ht->size = hht.size;
		printf("成功增容\n");
	}
}
//插入数据
int HashInsert(HashTable* ht, KeyType key, ValueType value)
{
	assert(ht);
	//检查容量
	CheckCapacity(ht);
	////直接定址法，获得插入位置
	int pos = GetPosition(ht,key);
	//为空，被删位置直接插，但存在位置有冲突，所以需要闭散列处理冲突
	while (ht->data[pos].state == EXIST)
	{
		//如果有相同数据就不用插入
		if (ht->data[pos].key == key)
			return 0;
		//闭散列线性探测，找下一个插入位置
		 else
			 pos++;
	}
	//找到位置直接插入
	ht->data[pos].key = key;
	ht->data[pos].value = value;
	ht->data[pos].state = EXIST;
	ht->size++;
	return 1;
	
}
int HashRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	////直接定址法，获得插入位置
	HashData* tmp = HashFind(ht, key);
	if (tmp)
	{
		ht->size--;
		tmp->state= DELETE;
		return 1;
	}
	return 0;



}
//查找数据
HashData* HashFind(HashTable* ht, KeyType key)
{
	assert(ht);
	////直接定址法，获得插入位置
	int pos = GetPosition(ht, key);
	//如果状态为空，被删直接返回NULL；存在的话就判断是否冲突，并且处理冲突，直到该位置后为空状态结束
	while (ht->data[pos].state != EMPTY)
	{
		if (ht->data[pos].key == key)
		{
			if (ht->data[pos].state == EXIST)
			{
				return &ht->data[pos];
			}
			else
			{	 //状态为删除状态，说明要找的数据已经被删除，直接返回
				return NULL;
			}

		}
		else
		{
			pos++;
		}
	}
	return NULL;
}
//表的有效长度
int HashSize(HashTable* ht)
{
	assert(ht);
	return ht->size;
}
//判空
int HashEmpty(HashTable* ht)
{
	assert(ht);
	return ht->size ==0;
}
//打印
void HashPrint(HashTable* ht)
{
	assert(ht);
	int i = 0;
	for (i = 0; i < ht->lenth; i++)
	{
		if (ht->data[i].state == EXIST)
		{
			printf("%d->(%d:%d)\n",i ,ht->data[i].key,ht->data[i].value);
		}
	}
	printf("\n");
}

//测试
void testHash()
{
	HashTable ht;
	HashInit(&ht, 6);
	HashInsert(&ht,56,'e');
	HashInsert(&ht, 1, 't');
	HashInsert(&ht, 57, 'y');
	HashInsert(&ht, 88, 'u');
	HashInsert(&ht, 3, 'o');
	HashInsert(&ht, 4, 'e');
	HashInsert(&ht, 2, 'x');

	printf("changdu : %d、\n", HashSize(&ht));
	printf("weikong? : %d、\n", HashEmpty(&ht));

	HashPrint(&ht);

	HashData* tmp  = HashFind(&ht, 88);
	if (tmp)
	{
		printf("找到\n");
	}
	else
	{
		printf("查找失败、\n");
	}
	tmp = HashFind(&ht, 99);
	if (tmp)
	{
		printf("找到\n");
	}
	else
	{
		printf("查找失败、\n");
	}

	int o = HashRemove(&ht, 88);
	if (o)
	{
		HashPrint(&ht);

	}
	else
	{
		printf("删除sha/ibai\n");
	}
	o = HashRemove(&ht, 22);
	if (o)
	{
		HashPrint(&ht);

	}
	else
	{
		printf("删除sha/ibai\n");
	}
	printf("changdu : %d、\n",HashSize(&ht));
	printf("weikong? : %d、\n", HashEmpty(&ht));
	 


	HashDestroy(&ht);



}

