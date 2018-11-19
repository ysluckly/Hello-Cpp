#define _CRT_SECURE_NO_WARNINGS 1
#include "String.h"

using bit::String;

const size_t String::npos = -1;

void String::Reserve(size_t n)
{
	if (n > _capacity)
	{
		char* newstr = new char[n + 1];
		strcpy(newstr, _str);
		delete[] _str;

		_str = newstr;
		_capacity = n;
	}
}

void String::Resize(size_t n, char ch)
{
	if (n <= _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	else
	{
		if (n > _capacity)
		{
			Reserve(n);
		}

		size_t pos = _size;
		while (pos < n)
		{
			_str[pos] = ch;
			++pos;
		}
		_size = n;
		_str[n] = '\0';
	}
}

void String::PushBack(char ch)
{
	//if (_size == _capacity)
	//{
	//	Reserve(_capacity * 2);
	//}

	//_str[_size] = ch;
	//++_size;
	//_str[_size] = '\0';

	Insert(_size, ch);
}

void String::Append(const char* str)
{
	//size_t len = strlen(str);
	//if (_size + len > _capacity)
	//{
	//	Reserve(_size + len);
	//}

	//strcpy(_str + _size, str);
	//_size += len;
	Insert(_size, str);
}

String& String::operator+= (char ch)
{
	this->PushBack(ch);
	return *this;
}

String& String::operator+= (const char* str)
{
	this->Append(str);
	return *this;
}

size_t String::Find(char ch, size_t pos)
{
	assert(pos < _size);

	while (pos < _size)
	{
		if (_str[pos] == ch)
		{
			return pos;
		}

		++pos;
	}

	return String::npos;
}

size_t String::RFind(char ch, size_t pos)
{
	int end = _size - 1;
	if (pos != String::npos)
	{
		assert(pos < _size);

		end = pos;
	}

	while (end >= 0)
	{
		if (_str[end] == ch)
		{
			return end;
		}

		--end;
	}

	return String::npos;
}

size_t String::Find(const char* str, size_t pos)
{
	assert(pos < _size);

	char* pmatch = strstr(_str + pos, str);
	if (pmatch == nullptr)
	{
		return npos;
	}
	else
	{
		return pmatch - _str;
	}
}

// "hello world"
String String::Substr(size_t pos, size_t len)
{
	if (_size - pos < len)
	{
		len = _size - pos;
	}

	String sub;
	sub.Reserve(len);
	for (size_t i = pos; i < pos + len; ++i)
	{
		sub += _str[i];
	}

	return sub;
}

void String::Insert(size_t pos, char ch)
{
	assert(pos <= _size);
	if (_size == _capacity)
	{
		if (_size == _capacity)
		{
			Reserve(_capacity * 2);
		}
	}

	int end = _size;
	while (end >= (int)pos)
	{
		_str[end + 1] = _str[end];
		--end;
	}
	_str[pos] = ch;
	_size++;
}

void String::Insert(size_t pos, const char* str)
{
	assert(pos < _size);
	size_t len = strlen(str);
	if (_size + len > _capacity)
	{
		Reserve(_size + len);
	}

	int end = _size;
	while (end >= (int)pos)
	{
		_str[end + len] = _str[end];
		--end;
	}

	while (*str)
	{
		_str[pos++] = *str++;
	}
	_size += len;
}

void String::Erase(size_t pos, size_t len)
{
	assert(pos < _size);
	if (len == npos || pos + len >= _size)
	{
		_str[pos] = '\0';
		_size = pos;
	}
	else
	{
		for (size_t i = 0; i < len; ++i)
		{
			_str[pos] = _str[pos + len];
			pos++;
		}
		_size -= len;
		_str[_size] = '\0';
	}
}