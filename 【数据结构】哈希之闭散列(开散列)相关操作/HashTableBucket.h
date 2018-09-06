

#include "common.h"


//typedef char* HTBKeyType;
//typedef char* HTBValueType;

//typedef char* HTBKeyType;
//typedef int HTBValueType;

typedef int HTBKeyType;
typedef int HTBValueType;

typedef struct HashDataNode
{
	HTBKeyType key;
	HTBValueType value;
	struct HashData* pNext;
}HashNode;

typedef struct HTBNode
{
	HashNode** table;
	size_t size;
	size_t len;
}HTB;


void HashTableBucketInit(HTB* htb, size_t len);
void HashTableBucketDestroy(HTB* htb);

void HashTableBucketInsert(HTB* htb, HTBKeyType key, HTBValueType value);
void HashTableBucketRemove(HTB* htb, HTBKeyType key);
HTB* HashTableBucketFind(HTB* htb, HTBKeyType key);

void HashTableBucketPrint(HTB* htb);
int HashTableBucketSize(HTB* htb);
int HashTableBucketEmpty(HTB* htb);