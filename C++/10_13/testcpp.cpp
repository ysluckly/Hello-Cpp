//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "hello world" << endl;
//	std::cout << "hello world" << std::endl;
//
//	return 0;
//}

//#include <stdio.h>
//
//int a = 0;
//
//namespace my
//{
//	int a = 1;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N3
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
//
//namespace your
//{
//	int a = 2;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//
//namespace your
//{
//	int b = 2;
//}
//
//int main()
//{
//	int a = 3;
//	printf("hello world\n");
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	printf("%d\n", my::a);
//	printf("%d\n", your::a);
//	printf("%d\n", my::Add(1, 2));
//	printf("%d\n", my::N3::Sub(1, 2));
//
//	return 0;
//}

//#include <stdio.h>
//
//namespace my
//{
//	int a = 1;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//}
//
////using my::a;
//using namespace my;
//
//int main()
//{
//
//	printf("%d\n", my::a);
//	printf("%d\n", a);
//	printf("%d\n", Add(1, 2));
//
//	return 0;
//}

//#include <iostream>
////using namespace std; // std C++库的命名空间
//
//// int swap = 10;
////swap
//namespace BIT
//{
//	int swap = 0;
//	int printf = 10;
//}
//
//int main()
//{
//	//std::cout << "hello world\n";
//	printf("%d\n", BIT::swap);
//	printf("%d\n", BIT::printf);
//
//	int a = 1, b = 2;
//	std::swap(a, b);
//
//	//printf("%d\n", max(1, 2));
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "Hello world!!!\n";
//	printf("Hello world!!!\n");
//
//	int a = 10;
//	scanf("%d", &a);
//	printf("%d\n", a);
//
//	cin >> a;
//	cout << a << endl;
//
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
////void TestFunc(int a = 10, int b = 20, int c = 30)
////{
////	cout << "a = " << a << endl;
////	cout << "b = " << b << endl;
////	cout << "c = " << c << endl;
////}
//
//void TestFunc(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//void  Swap(int* a, int* b)
//{
//
//}
//
//void  Swap(char* a, char* b)
//{
//
//}
//
//int main()
//{
//	//TestFunc(1);
//	//TestFunc(1, 2);
//	//TestFunc(1, 2, 3);
//
//	return 0;
//}

//#include "F.h"

//#pragma once
//#include <iostream>
//using namespace std;
//
//void F1(int a);
//int main()
//{
//	F1(10);
//
//	return 0;
//}
//
//int main()
//{
//	F1(1);
//
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int& c = b;
//
//	b = 20;
//	c = 30;
//
//	int d = 40;
//	c = d;
//
//	return 0;
//}
//


//#include <iostream>
//using namespace std;
//
//int main()
//{
//	const int a = 10;
//	const int& b = a;
//
//	int c = 20;
//	const int& d = c;
//
//	int e = 10;
//	const double& f = e;
//
//	return 0;
//}

#include <iostream>
using namespace std;

void Swap(int& x1, int& x2)
{
	int x = x1;
	x1 = x2;
	x2 = x;
}

//int& TestRefReturn(int& a)
//{
//	a += 10;
//	return a;
//}

//int& TestRefReturn(int& a)
//{
//	a += 10;
//	return a;
//}
//
//int main()
//{
//	int x = 10;
//	int y = TestRefReturn(x);
//
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(10, 20);
//	Add(100, 200);
//	cout << "Add(10,20) is :" << ret << endl;
//	return 0;
//}

//#include<time.h>
//
//struct A
//{
//	int a[100000];
//};
//A a;
//
//A& TestFunc()
//{
//	return a;
//}
//
//int main()
//{
//	long begin = clock();
//	for (int i = 0; i < 10000; ++i)
//		TestFunc();
//	long end = clock();
//
//	cout << "count time:" << end - begin << endl;
//}

//int main()
//{
//	int a = 10;
//
//	int* pa = &a;
//	int& ra = a;
//}
//
//inline int Add(int a, int b)
//{
//	int c = a + b;
//
//	return c;
//}
//
//inline int f(int n)
//{
//	return n < 1 ? n : f(n - 1) + n;
//}
//
//#define MAX(a, b) ((a)>(b)?(a):(b))
//
//struct Student
//{
//	void ShowInfo()
//	{
//		cout << _name << " " << _age << endl;
//	}
//
//	void SetAge(int age)
//	{
//		_age = age;
//	}
//public:
//	char* _name;
//protected:
//	int _age;
//};
//
//// const enum inline替代宏
//int main()
//{
//	//int ret = Add(1, 2);
//	//printf("%d", ret);
//
//	//cout << f(10) << endl;
//
//	//MAX(1, 2); // 1>2?1:2;
//	//int x1 = 1, x2 = 2;
//	//MAX(x1|x2, x1&x2);  //x1|x2>x1&x2 ?
//
//	Student s;
//	s._name = "jack";
//	s.SetAge(10);
//
//	s.ShowInfo();
//
//	return 0;
//}

#include <time.h>

struct A
{
	int a[100000];
};
A a;

void TestFunc1(A a)
{}

void TestFunc2(A& a)
{}

int main()
{
	size_t begin1 = clock();
	A a;
	for (int i = 0; i < 10000; ++i)
		TestFunc1(a);
	size_t end1 = clock();

	size_t begin2 = clock();
	for (int i = 0; i < 10000; ++i)
		TestFunc2(a);
	size_t end2 = clock();

	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}