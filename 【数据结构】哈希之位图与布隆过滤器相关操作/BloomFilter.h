#ifndef __BLOOMFILTER_H__

#define __BLOOMFILTER_H__


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BitMap.h"


typedef char* DataType;
typedef struct BloomFilterNode
{
	BitMap Bloom;
}BloomFilter;


//布隆过滤器初始化
void BloomFilterInit(BloomFilter* bf,size_t len);
//布隆过滤器销毁
void BloomFilterDestroy(BloomFilter* bf);


//布隆过滤器计数
void BloomFilterSet(BloomFilter* bf, DataType x);
//布隆过滤器重置
void BloomFilteReset(BloomFilter* bf, DataType x);	//不支持
//布隆过滤器测试
int BloomFilterTest(BloomFilter* bf, DataType x);

 //测试
void TestBloomFilter();



#endif //__BLOOMFILTER_H__