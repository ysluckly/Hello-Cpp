#ifndef __HSAH_H__
#define __HSAH_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//key-value模型

typedef int KeyType;
typedef char ValueType;

//表中数据状态
typedef enum State
{
	EMPTY,	//不存在数据
	EXIST,	//存在
	DELETE  //被删除
}State;

//表中数据类型
typedef struct HashData
{
	State  state; //数据状态
	KeyType key;  //待插入值
	ValueType value;  
}HashData;
typedef struct HashTable
{
	HashData* data;//采用动态数组实现
	int size;	//有效数据个数
	int lenth;  //表长
	

}HashTable;

//初始化
void HashInit(HashTable* ht,int len);
//销毁
void HashDestroy(HashTable* ht);

//插入数据
int HashInsert(HashTable* ht, KeyType key,ValueType value);
//删除数据
int HashRemove(HashTable* ht,KeyType key);
//查找数据
HashData* HashFind(HashTable* ht,KeyType key);
//表的有效长度
int HashSize(HashTable* ht);
//判空
int HashEmpty(HashTable* ht);
//打印
void HashPrint(HashTable* ht);

//测试
void testHash();




#endif //__HSAH_H__