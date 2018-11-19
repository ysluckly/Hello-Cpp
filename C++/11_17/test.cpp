#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"
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
		//c++11
		void* operator new(size_t size) = delete;
		void  operator delete(void* p) = delete;

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


void test_string1()
{
	string s1;
	string s2("hello");
	string s3(s2);
	string s4 = "world"; 

	s2 = s4;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

void test_string2()
{
	string num("1234");
	// 迭代器给出统一方式去访问容器，屏蔽掉底层复杂的结构细节
	string::iterator it = num.begin();
	int value = 0;
	while (it != num.end())
	{
		value *= 10;
		value += *it - '0';
		++it;
	}
	cout << value << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;

	list<int> l;
	l.push_back(10);
	l.push_back(10);
	l.push_back(10);
	list<int>::iterator lit = l.begin();
	while (lit != l.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
}

//int StrToNum(const string& str)
//{
//	int value = 0;
//	string::const_iterator it = str.cbegin();
//	while (it != str.cend())
//	{
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//
//	return value;
//}

//int StrToNum(const string& str)
//{
//	int value = 0;
//	string::const_iterator it = str.cbegin();
//	while (it != str.cend())
//	{
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//
//	return value;
//}

void test_string3()
{
	// 了解
	// 反向迭代器
	string num("1234");
	//string::reverse_iterator rit = num.rbegin();
	//while (rit != num.rend())
	string::iterator it = num.begin();
	while (it != num.end())
	{
		//cout << *it << " ";
		(*it) += 1;
		++it;
	}
	cout << endl;

	//cout << StrToNum(num) << endl;
}

//int StrToNum(const string& str)
//{
//	int value = 0;
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		value *= 10;
//		value += (str[i] - '0');
//	}
//	return value;
//}

int StrToNum(const string& str)
{
	int value = 0;
	for (auto& e : str)
	{
		value *= 10;
		value += (e - '0');
	}

	//std::map<std::string, std::vector<std::string>> strVMap;
	//std::map<std::string, std::vector<std::string>>::const_reverse_iterator svmit = strVMap.crbegin();
	//while (svmit != strVMap.crend())
	//{
	//	++svmit;
	//}

	//for (auto& e : strVMap)
	//{

	//}

	return value;
}

void test_string4()
{
	// 新的访问方式
	// 1.迭代器 -- 不常用，跟其他容器保持统一的访问方式
	// 2.for+下标  -- 更常用
	// 3.C++11 语法糖式for
	string num("1234");
	cout << StrToNum(num) << endl;
}

void test_string5()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	s.reserve(50);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	s.resize(80, '1');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	string s1("hello Bit");
	s1[6] = 'b';
	cout << s1 << endl;
}

void test_string6()
{
	/*string s1("hello");
	s1.push_back(' ');
	s1.append("world");
	cout << s1 << endl;*/

	string s1("hello");
	s1 += ' ';
	s1 += "world";
	string s2("!!!");
	s1 += s2;
	s1.insert(s1.begin(), 'x');
	s1.insert(0, "bit-");
	s1.erase(0, 3);
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	string num("111");
	int value = atoi(num.c_str());
	cout << value << endl;
}

void test_string7()
{
	string file("test.cpp");
	size_t pos = file.rfind('.');
	if (pos == string::npos)
	{
		cout << "文件没有后缀" << endl;
	}
	else
	{
		cout << file.substr(pos, file.size() - pos) << endl;
	}

	string url("https://www.cplusplus.com/reference/string/string/erase/");
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "url invalid" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	cout << url.substr(start, finish - start) << endl;

	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}

void test_string8()
{
	string s;
	s.reserve(200);
	size_t sz = s.capacity();
	for (int i = 0; i < 200; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	string s1("hello");
	string s2("world");
	cout << s1 + s2 << endl;
	cout << s1 + "world" << endl;
	cout << "hello" + s2 << endl;


}

 
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();

	test_string8();


	system("pause");
	return 0;
}

