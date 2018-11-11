//#define _CRT_SECURE_NO_WARNINGS 1
//#include "string.h"
//
////验证回文
//class String
//{
//public:
//	String(string s)
//		:s(s)
//	{}
//
//	bool IsReverseChar(string& s)
//	{
//		size_t begin = 0;
//		size_t end = s.size();
//
//		while (begin < end)
//		{
//			while (begin < end&&!isalnum(s[begin]))
//				begin++;
//			while (begin < end&&!isalnum(s[end]))
//				end--;
//			if ((s[begin] - 'A' + 32) % 32 == (s[end] - 'A' + 32) % 32)
//			{
//				begin++;
//				end--;
//			}
//			else
//			{
//				return false;
//			}
//
//		}
//		return true;
//
//	}
//
//	void test()
//	{
//		if (IsReverseChar(s))
//		{
//			cout << "true" << endl;
//
//		}
//		else
//		{
//			cout << "false" << endl;
//		}
//	}
//private:
//	string s;
//};
//
//void test1()
//{
//	//String s("abcbA");
//
//	string s;
//	cin >> s;
//
//	//优化 ：转小写
//	/*for (int i = 0; i < s.size(); ++i)
//	{
//
//	if (s[i] >= 'A'&&s[i] <= 'Z')
//	{
//	s[i] = tolower(s[i]);
//	}
//	}  */
//
//	for (auto& e : s)
//	{
//		if (e >= 'A'&&e <= 'Z')
//		{
//			e = tolower(e);
//		}
//	}
//
//	cout << s;
//
//	String a(s);
//	a.test();
//
//
//}
////字符串相加
//class Solution
//{
//public:
//	string addStrings(string num1, string num2) {
//		int n1 = num1.size() - 1;
//		int n2 = num2.size() - 1;
//
//		string res;
//		//进位
//		int count = 0;
//		while (n1 >= 0 || n2 >= 0)
//		{
//			int sum = ((n1 >= 0) ? num1[n1--] - '0' : 0) + ((n2 >= 0) ? num2[n2--] - '0' : 0) + count;
//			count = sum / 10;
//			sum %= 10;
//			//数大每次后移造成的代价很大
//			res.insert(res.begin(), sum + '0');
//			//改进
//			//采用尾插，最后通过reverse(res.begin(),res.end());进行转换
//		}
//		//两数相加，进位最大为1
//		return count ? '1' + res : res;
//	}
//};
//
////C语言
////int i = int();//默认初始化为0
////C++
////cout<<int()<<endl;//0
//
////1.传统方法：模拟实现string
////class Stringg
////{
////public:
////	/*Stringg()
////		:_str(new char[1])
////	{
////		_str[0] = '\0';
////	}
////	Stringg(char* str)
////		:_str(new char[strlen(str + 1)]
////	{	
////		strcpy(_str, str);
////	}*/
////	//构造最好缺省（包含无参与有参）
////	Stringg(const char* str = "")	  
////		:_str(new char[strlen(str) + 1])
////	{
////		// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下
////		//assert(str);
////		if (nullptr == str)
////		{
////			return;
////		}
////		strcpy(_str, str);
////	}
////	//s3(s2)	  深拷贝：各自私有空间【重新开辟空间】
////	Stringg(const Stringg& s)
////	:_str(new char[strlen(s._str)+1])
////	{
////		strcpy(_str, s._str);
////
////	}
////
////	//s4 =s2	  深拷贝
////	Stringg operator=(const Stringg& s)
////	{
////		if (this!=&s)
////		{
////			delete[] _str;	  //释放原本空间
////			_str = new char[strlen(s._str) + 1];
////			strcpy(_str, s._str);
////
////		}
////		return *this;
////
////	}
////	~Stringg()
////	{
////		if (_str)
////		{
////			delete[] _str;
////			_str = nullptr;
////		}
////	}
////private:
////	char* _str;
////};
////// 测试
////void TestString()
////{
////	String s1("hello bit!!!");
////	String s2(s1);
////}
//
//
////2.现代方法：模拟实现string
//class sstring
//{
//public:
//	sstring(const sstring& s)
//		:_str(nullptr)
//	{
//		sstring tmp(s._str);
//		swap(_str, tmp._str);
//
//	}
//	~sstring()
//	{
//
//	}
//private:
//	char* _str;
//};
//void test2()
//{	//sizeof注重的是总的字符个数
//	//strlen注重的是'\0'
//	char a1[] = "";
//	cout << sizeof(a1) << endl;	 //1
//	cout << strlen(a1) << endl;	 //0
//
//	char a2[] = "adv\0\ddd";  //'\0'
//	cout << sizeof(a2) << endl;	 //8
//	cout << strlen(a2) << endl;	 //3
//
//	char a3[] = "\\0";
//	cout << sizeof(a3) << endl;	  //3
//	cout << strlen(a3) << endl;	  //2
//
//	char a4[] = "0";
//	cout << sizeof(a4) << endl;	   //2
//	cout << strlen(a4) << endl;	   //1
//
//	char a5[] = "\0 000";
//	cout << sizeof(a5) << endl;	   //6
//	cout << strlen(a5) << endl;	   //0
//
//	char a6[] = "0000";
//	cout << sizeof(a6) << endl;	   //5
//	cout << strlen(a6) << endl;	   //4
//
//	char a7[] = "\000000";		  // \ddd
//	cout << sizeof(a7) << endl;	 //5
//	cout << strlen(a7) << endl;	 //0
//
//	char a8[] = "\x0000";
//	cout << sizeof(a8) << endl;	  //2
//	cout << strlen(a8) << endl;	  //0
//	char a8[] = "\x0000000000000000000000000000000000000000000";
//	cout << sizeof(a8) << endl;	  //2
//	cout << strlen(a8) << endl;	  //0
//
//	char a9[] = "\xff";			   // \xdd
//	cout << sizeof(a9) << endl;	  //2
//	cout << strlen(a9) << endl;	  //1
//
//	char a10[] = "\x0ff";			   // \xdd
//	cout << sizeof(a10) << endl;	  //2
//	cout << strlen(a10) << endl;	  //1
//
//	char a11[] = "\xff0";			//报错    
//	cout << sizeof(a11) << endl;
//	cout << strlen(a11) << endl;
//}
//
//int main()
//{
//	//test2();
//	//TestString();
//	cout << min(1, 5, 2, 6) << endl;
//	system("pause");
//	return 0;
//}
//
