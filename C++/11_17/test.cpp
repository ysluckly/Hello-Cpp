#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>

//只能在栈上创建对象
//只需要屏蔽new delete功能即可即屏蔽地掉operator new，operator delete表达式
void test1()
{
	class StackOnly
	{
	public:
		StackOnly()
		{
			;
		}

	private:
		//屏蔽 new delete
		void* operator new(size_t size);
		void  operator delete(void* p);

	};

}
//只能在堆上创建对象
//构造私有化
void test2()
{
	class HeapOnly
	{
	public:
		static HeapOnly* CreatObj()
		{
			return new HeapOnly;
		}
	private:
		HeapOnly()
		{
			;
		}

		//防拷贝
		HeapOnly(const HeapOnly& s);

	};
}

//浅拷贝，创造多个对象，销毁一个，其他的随之销毁，再引用，程序崩溃，所以采用深拷贝
//传统模拟实现string
void test3()
{
	class String
	{
		String(const char* str="")
		{
			//如果为空，认为非法，断言退出
			if (str == nullptr)
			{
				assert(false);
				return;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);

		}
		String(const String& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);

		}
		String& operator=(const String& s)
		{
			//释放资源
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
			if (this != &s)
			{
				_str = new char[strlen(s._str)+1];
				strcpy(_str,s._str);
				return *this;
			}
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}


		}
	private:
		char* _str;
	};

}
//现代模拟实现string
void test4()
{
	class String
	{
		String(const char* str = "")
		{
			//如果为空，认为非法，断言退出
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);

		}
		String(const String& s)
			:_str(nullptr)
		{
			String tmp(s);
			swap(_str,tmp._str);

		}
		String& operator=(const String& s)
		{
			
			if (this != &s)
			{
				String tmp(s);
				swap(_str, tmp._str);
				
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}


		}
	private:
		char* _str;
	};

}
using namespace std;
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();

	system("pause");
	return 0;
}

