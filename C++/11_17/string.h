#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <Windows.h> 
#include <algorithm>
#include <assert.h>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

class String
{
public:
	// 迭代器
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}


	// 在类里面实现，默认是inline
	String(const char* str = "")
	{
		_size = strlen(str);
		_capacity = _size > 15 ? _size : 15;
		_str = new char[_capacity + 1];
		strcpy(_str, str);
	}

	~String()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}

	// s1 = s2
	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}

	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	size_t Size() const
	{
		return _size;
	}

	size_t Capacity() const
	{
		return _capacity;
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	const char* c_str()
	{
		return _str;
	}

	void Reserve(size_t n);
	void Resize(size_t n, char ch = '\0');

	void PushBack(char ch);
	void Append(const char* str);
	String& operator+=(char ch);
	String& operator+=(const char* str);
	size_t Find(char ch, size_t pos = 0);
	size_t RFind(char ch, size_t pos = npos);

	size_t Find(const char* str, size_t pos = 0);
	void Insert(size_t pos, char ch);
	void Insert(size_t pos, const char* str);
	void Erase(size_t pos, size_t len = npos);
	String Substr(size_t pos, size_t len = npos);
private:
	char* _str;
	size_t _size;
	size_t _capacity;

public:
	static const size_t npos;
};

#endif //__FILE_H__