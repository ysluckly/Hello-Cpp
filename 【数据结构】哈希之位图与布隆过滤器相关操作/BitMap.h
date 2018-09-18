#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct BitMapNode
{
	char* bit; //指向N位组成的空间
	size_t N; //总的位数
}BitMap;

void BitMapInit(BitMap* pbm,size_t len);
void BitMapDestroy(BitMap* pbm);

void BitMapSet(BitMap* pbm,size_t x);
void BitMapReset(BitMap* pbm,size_t x);
int BitMapTest(BitMap* pbm,size_t x);
void TestBitMap();






#endif //__BITMAP_H__