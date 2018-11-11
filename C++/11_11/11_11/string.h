#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <Windows.h> 
#include <algorithm>
#include <string>
#include <assert.h>
#include <vector>
#include <list>
#include <map>
using namespace std;

namespace My
{
	class Mystring
	{
	public:
		//类内默认内联（内联声明定义不要分开，易产生链接错误）
		/////////////////////////////////////////////////////////////////
		//默认成员函数
		Mystring(const char* str = "")
		{
			//判断传空指针 
			if (nullptr == str)
			{
				_str = new char[1];
				_size = 0;
				_capacity = 0;
				*_str = '\0';
			}
			else
			{
				_str = new char[strlen(str) + 1];
				_size = strlen(str);
				_capacity = _size;
				strcpy(_str, str);
			}
		}

		~Mystring()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
			_size = _capacity = 0;
		}

		Mystring(const Mystring& s)
			:_str(new char[strlen(s._str)+1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str,s._str);
		}

		Mystring& operator=(const Mystring& s)
		{
			if (_str)
			{
				delete[] _str; //释放空间资源
				_str = nullptr;
			}
			if (this != &s)
			{
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
		}

		////////////////////////////////////////////////////////////////////
		//Iterator
		Iterator Begin()
		{
			return _str;

		}
		Iterator End()
		{
			return _str + _size;
		}

		///////////////////////////////////////////////////////////////////
		//modify
		void PushBack(char ch)
		{
			if (_size == _capacity)
			{
				Resize(2 * _capacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		void Append(size_t n, char ch)
		{
			for (int i = 0; i < n; ++i)
			{
				PushBack(ch);
			}
		}
		void Append(const char* str)
		{


		}
		Mystring& operator+=(const Mystring& s);//用实参字符串转类进行实现
		Mystring& operator+=(const char ch)
		{
			PushBack(ch);
			return *this;
		}
		Mystring& operator+=(const char* str);
		{


		}

		///////////////////////////////////////////////////////////////////
		//capacity
		size_t Size() const;
		size_t Capacity() const;
		bool Empty() const;
		void Resize(size_t newSize);
		void Resize(size_t newSize,char ch);
		void Reserve(size_t newCapacity);

		///////////////////////////////////////////////////////////////////
		//access
		char& operator[](size_t pos);                   //越剧程序崩溃
		const char& operator[](size_t pos) const;
		const char& At(size_t pos) const;				//越界抛出异常行

		//////////////////////////////////////////////////////////////////
		//关系运算符
		bool operator>(const Mystring& s);
		bool operator<(const Mystring& s);
		bool operator==(const Mystring& s);
		bool operator>=(const Mystring& s);
		bool operator<=(const Mystring& s);
		bool operator!=(const Mystring& s);

		///////////////////////////////////////////////////////////////////
		//算法
		void Clear();
		void Swap();
		const char* C_str() const;
		size_t Find(char ch, size_t pos = 0) const;
		size_t Find(const char* str, size_t pos= 0) const;
		Mystring SubString(size_t pos, size_t n);
		Mystring& Insert(size_t pos,char ch);
		Mystring& Insert(size_t pos, const char* str);
		Mystring Erase(size_t pos,size_t len);

	private:
		friend ostream& operator<<(ostream& _cout, const My::Mystring& s)
		{
			_cout << s._str << endl;
			return _cout;
		}
		friend istream& operator>>(istream& _cin, My::Mystring& s)
		{
			_cin >> s._str;
			return _cin;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;	//find算法返回值默认-1;
	};
	const size_t My::Mystring::npos = -1;
}

#endif //__FILE_H__