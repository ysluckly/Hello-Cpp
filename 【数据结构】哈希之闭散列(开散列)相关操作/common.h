#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//素数表
static size_t GetNextPrime(int value)
{
	int i = 0;
	//const int _PrimeSize = 28;
	static const unsigned long PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};

	for (; i < 28; ++i)
	{
		if (PrimeList[i] > value)
		{
			return PrimeList[i];
		}
	}

	return PrimeList[27];
}

//处理字符串
static size_t StrHash(const char* str)
{
	size_t hash = 0;
	size_t seed = 131;
	while (*str)
	{
		hash = hash*seed + *str;
		++str;
	}

	printf("%u\n", hash);

	return hash;
}


#endif //__HASHTABLE_H__