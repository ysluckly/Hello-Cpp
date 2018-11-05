#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <Windows.h> 
#include <vector>
#include <algorithm>
using namespace std;

//初识STL
void test01()
{
	//容器
	vector<int> v;//创建一个容器，动态数组
	v.push_back(10);//通过vector通过成员方法，向容器尾部添加元素
	v.push_back(10);
	v.push_back(5);

			//       迭代器（指针）
			//容器-------------------算法

	//迭代器
	vector<int>::iterator pStart = v.begin();//拿到指向第一个元素的迭代器
	vector<int>::iterator pEnd = v.end();//返回指向最后一个元素的下一个位置


	while (pStart != pEnd)
	{
		cout <<*pStart<< " ";
		pStart++;
	}
	cout << endl;

	//算法
	//count统计容器中某个元素个数
	int n= count(v.begin(),v.end(),4);//开始、结束、需要统计的元素
	cout << " " << n << endl;

}
//练习案例
class Teacher
{
public:
	Teacher(int a, int b)
		:_a(a)
		,_b(b)
	{
	}

	int _a;
	int _b;
};
void test02()
{
	vector<Teacher> v;
	Teacher t1(1, 2), t2(3, 4), t3(5,6);
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	vector<Teacher>::iterator pStart = v.begin();
	vector<Teacher>::iterator pEnd = v.end();

	while (pStart!=pEnd)
	{
		Teacher t = *pStart;
		cout << t._a <<" "<< t._b << endl;
		pStart++;
	}
}
//容器放类型对象指针
void test03()
{
	vector<Teacher*> v;//容器放Teacher类型指针
	Teacher t1(1, 2), t2(3, 4), t3(5, 6);
	Teacher* p1 = &t1;
	Teacher* p2 = &t2;
	Teacher* p3 = &t3;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	vector<Teacher*>::iterator pStart = v.begin();
	vector<Teacher*>::iterator pEnd = v.end();

	while (pStart != pEnd)
	{
		Teacher* t = *pStart;
		cout << t->_a <<" "<< t->_b << endl;
		pStart++;
	}

}

int mycount(int* pStart, int* pEnd, int value)
{
	int n = 0;
	while (pStart != pEnd)
	{
		if (*pStart == value)
			n++;
		pStart++;
	}
	return n;
}
////STL容器基本原理
void test04()
{
	int arr[] = { 3, 5, 6, 8 };
	int* pStart = arr;
	int* pEnd = &arr[sizeof(arr) / sizeof(int)];

	int n = mycount(pStart, pEnd, 8);
	cout << n << endl;
}

///////////////////////////容器
//string

int main()
{
////STL初识
	//test01();
	//test02();
	//test03();

////STL容器基本原理
	//test04();


	system("pause");
	return 0;
}

