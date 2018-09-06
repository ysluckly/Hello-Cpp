
#include "HashTableBucket.h"

void HashTableBucketInit(HTB* htb, size_t len)
{
	assert(htb);
	htb->len = GetNextPrime(len);
	htb->table = (HashNode**)malloc(sizeof(HashNode*)*len);
	assert(htb->table);
	memset(htb->table, NULL, sizeof(HashNode*)*len);
	htb->size = 0;
	htb->len = len;

}
void HashTableBucketDestroy(HTB* htb)
{
	assert(htb);
	size_t  i = 0;
	for (i = 0; i < htb->len; ++i)
	{
		HashNode* pCur = htb->table[i];
		while (pCur)
		{
			HashNode* next = pCur->pNext;
			free(pCur);
			pCur = next;
		}
		htb->table[i] = NULL;
	}
	free(htb->table);
	htb->table = NULL;
	htb->len = htb->size = 0;

}
//获得插入位置
int Func(HTBKeyType key, size_t len)
{
	return key%len;

	//字符串
	/*return StrHash(key)%len*/
	
}
 
//检查容量
void CheckCapacity(HTB* htb)
{
	assert(htb);
	if (htb->len == htb->size)
	{
		int i = 0;
		HTB hb;
		hb.len = GetNextPrime(htb->len);
		HashTableBucketInit(&hb, hb.len);

		for (i = 0; i < htb->len; ++i)
		{
			HashNode* pCur = htb->table[i];
			while (pCur)
			{
				HashNode* next = pCur->pNext;
				int index = Func(pCur->key, hb.len);

				pCur->pNext = hb.table[index];
				hb.table[index] = pCur;
				
				pCur = next;
			}
			htb->table[i] = NULL;
		}
		HashTableBucketDestroy(htb->table);
		htb->len = hb.len;
		htb->size = hb.size;
		htb->table = hb.table;

	}
}


void HashTableBucketInsert(HTB* htb, HTBKeyType key, HTBValueType value)
{
	assert(htb);
	//检查容量
	CheckCapacity(htb);
	//插入
	int index = Func(key, htb->len);
	//检查是否有相同元素
	HashNode* pCur = htb->table[index];
	while (pCur)
	{
		if (pCur->key == key)
			return;
		pCur = pCur->pNext;
	}

	HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
	assert(newNode);
	newNode->key = key;
	newNode->value = value;
	newNode->pNext = NULL;

	//头插
	newNode->pNext = htb->table[index];
	htb->table[index] = newNode;
	htb->size++;
}
void HashTableBucketRemove(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = Func(key, htb->len);
	HashNode* pPre = NULL;
	HashNode* pCur = htb->table[index];
	while (pCur)
	{
		if (pCur->key == key)
		{
			if (!pPre)
			{
				htb->table[index] = pCur->pNext;
			}
			else
			{
				pPre->pNext = pCur->pNext;
			}
			free(pCur);
			pCur = NULL;
			htb->size--;
			return 1;

		}
		else
		{
			pPre = pCur;
			pCur = pCur->pNext;
		}
	}
	return 0;

}
HTB* HashTableBucketFind(HTB* htb, HTBKeyType key)
{
	assert(htb);
	int index = Func(key, htb->len);
	HashNode* pCur = htb->table[index];

	while (pCur)
	{
		if (pCur->key == key)
			return pCur;
		pCur = pCur->pNext;
	}
	return NULL;
}

void HashTableBucketPrint(HTB* htb)
{
	assert(htb);
	size_t i = 0;
	for (i = 0; i < htb->len; ++i)
	{
		HashNode* pCur = htb->table[i];
		printf("htp->table[%d]->", i);
		while (pCur)
		{
			printf(" [%d:%d]->", pCur->key, pCur->value);
			pCur = pCur->pNext;

		}
		printf("NULL\n");

	}
}
int HashTableBucketSize(HTB* htb)
{
	assert(htb);
	return htb->size;
}
int HashTableBucketEmpty(HTB* htb)
{
	assert(htb);
	return htb->size = 0;
}

void testHashTableBucket()
{
	HTB httb;
	HashTableBucketInit(&httb, 10);
	HashTableBucketInsert(&httb, 28, 0);
	HashTableBucketInsert(&httb, 3, 0);
	HashTableBucketInsert(&httb, 66, 0);
	HashTableBucketInsert(&httb, 12, 0);
	HashTableBucketInsert(&httb, 9, 0);
	HashTableBucketPrint(&httb);

}
