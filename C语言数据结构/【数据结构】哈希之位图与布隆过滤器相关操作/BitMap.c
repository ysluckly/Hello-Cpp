
#include "BitMap.h"

//位图初始化
void BitMapInit(BitMap* pbm, size_t len)
{
	assert(pbm);
	//加一为了使得在为某数寻址时，统一，即向上取整
	// 假如len为25,25/8=4，但是要5个字节才能存的下
	pbm->bit = (char*)malloc(((len>>3)+1));
	assert(pbm->bit);
	memset(pbm->bit,0, sizeof((len>>3)+1));
	pbm->N = len;

}
//位图销毁
void BitMapDestroy(BitMap* pbm)
{
	assert(pbm);
	free(pbm->bit);
	pbm->bit = NULL;
	pbm->N = 0;
	printf("销毁成功\n");
}

//位图
void BitMapSet(BitMap* pbm, int x)
{
	assert(pbm);
	int index = x >> 3;
	int num = x % 8;
	pbm->bit[index] |= (1<<num);
}
void BitMapReset(BitMap* pbm, int x)
{
	assert(pbm);
	int index = x >> 3;
	int num = x % 8;
	pbm->bit[index] &= ~(1<<num);
}

int BitMapTest(BitMap* pbm, int x)
{
	assert(pbm);
	int index = x >> 3;
	int num = x % 8;
	return (pbm->bit[index]&(1<<num)) == 1;
}
void TestBitMap()
{
	BitMap bm;
	BitMapInit(&bm,10);
	BitMapSet(&bm,78);
	BitMapSet(&bm, 99);
	BitMapSet(&bm, 55);
	BitMapSet(&bm, 76);

	BitMapSet(&bm,12);
	printf("  %d    ",BitMapTest(&bm,99));

	BitMapReset(&bm,78);
	printf("   %d    ",BitMapTest(&bm,78));


	BitMapDestroy(&bm);
}